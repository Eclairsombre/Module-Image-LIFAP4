#include "ImageViewer.h"
#include <cmath>
#include <iostream>

ImageViewer::ImageViewer()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cout << "SDL initialization failed: " << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }
    this->window = SDL_CreateWindow("Image Viewer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 200, 200, 0);
    if (this->window == nullptr)
    {
        std::cout << "SDL window creation failed: " << SDL_GetError() << std::endl;
        SDL_Quit();
        exit(EXIT_FAILURE);
    }
    this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (this->renderer == nullptr)
    {
        std::cout << "SDL renderer creation failed: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        exit(EXIT_FAILURE);
    }
}

ImageViewer::~ImageViewer()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void ImageViewer::afficher(const Image &im)
{
    SDL_Event event;
    bool running = true;
    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
            }
            else if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_t)
                {
                    this->zoom *= 1.1;
                }
                else if (event.key.keysym.sym == SDLK_g)
                {
                    this->zoom /= 1.1;
                }
            }
        }
        SDL_SetRenderDrawColor(renderer, 211, 211, 211, 255);
        SDL_RenderClear(renderer);

        int windowWidth, windowHeight;
        SDL_GetWindowSize(window, &windowWidth, &windowHeight);
        int imagePosX = (windowWidth - im.getDimx() * zoom) / 2;
        int imagePosY = (windowHeight - im.getDimy() * zoom) / 2;

        for (int i = 0; i < im.getDimx(); i++)
        {
            for (int j = 0; j < im.getDimy(); j++)
            {
                Pixel p = im.getPix(i, j);
                SDL_SetRenderDrawColor(renderer, p.r, p.g, p.b, 255);
                SDL_Rect pixelRect = {(int)(std::round(imagePosX + i * zoom)),
                                      (int)(std::round(imagePosY + j * zoom)),
                                      (int)(std::round(zoom)) + 1,
                                      (int)(std::round(zoom)) + 1};
                SDL_RenderFillRect(renderer, &pixelRect);
            }
        }
        SDL_RenderPresent(renderer);
    }
}