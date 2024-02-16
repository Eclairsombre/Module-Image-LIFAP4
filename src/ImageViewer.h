#ifndef VIEWER
#define VIEWER

#include <SDL2/SDL.h>
#include "Image.h"

/**
 * @class ImageViewer
 *
 * @brief Une classe pour afficher une image.
 *
 */

class ImageViewer
{

private:
    SDL_Window *window;     //< La fenêtre
    SDL_Renderer *renderer; //< Le renderer
    double zoom = 1.0;      //< Le zoom

public:
    /**
     * @brief Construit un nouvel objet ImageViewer:: ImageViewer
     * @return ImageViewer : Un objet ImageViewer
     *
     */
    ImageViewer();

    /**
     * @brief Détruit l'objet ImageViewer:: ImageViewer
     *
     */
    ~ImageViewer();

    /**
     * @brief Affiche l'image im
     *
     * @param im L'image à afficher
     * @return void : Affiche l'image
     */
    void afficher(const Image &im);
};

#endif