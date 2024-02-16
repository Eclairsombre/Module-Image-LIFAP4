#include "Image.h"
#include <iostream>
using namespace std;
#include <fstream>
#include <cassert>

Image::Image()
{
    this->dimx = 0;
    this->dimy = 0;
    this->tab = nullptr;
}

Image::Image(int dimx, int dimy)
{
    if (dimx < 0 || dimy < 0)
    {
        std::cout << "Erreur : dimensions négatives" << std::endl;
        this->dimx = 0;
        this->dimy = 0;
    }
    else
    {
        this->dimx = dimx;
        this->dimy = dimy;
        this->tab = new Pixel[dimx * dimy];
    }
}

Image::~Image()
{
    this->dimx = 0;
    this->dimy = 0;
    if (tab != nullptr)
    {
        delete[] tab;
    }
}

void Image::setPix(int x, int y, const Pixel p)
{
    assert(x >= 0 && x <= this->dimx && y >= 0 && y <= this->dimy);

    this->tab[x + y * this->dimx] = p;
}

Pixel &Image::getPix(int x, int y)
{
    assert(x >= 0 && x <= this->dimx && y >= 0 && y <= this->dimy);

    return this->tab[x + y * this->dimx];
}

Pixel Image::getPix(int x, int y) const
{
    assert(x >= 0 && x <= this->dimx && y >= 0 && y <= this->dimy);

    return this->tab[x + y * this->dimx];
}

void Image::dessinerRectangle(int Xmin, int Ymin, int Xmax, int Ymax, const Pixel p)
{
    assert(Xmin >= 0 && Xmin <= this->dimx && Ymin >= 0 && Ymin <= this->dimy && Xmax >= 0 && Xmax <= this->dimx && Ymax >= 0 && Ymax <= this->dimy);

    for (int i = Xmin; i <= Xmax; i++)
    {
        for (int j = Ymin; j <= Ymax; j++)
        {
            this->setPix(i, j, p);
        }
    }
}

void Image::effacer(const Pixel p)
{
    this->dessinerRectangle(0, 0, this->dimx - 1, this->dimy - 1, p);
}

void Image::sauver(const std::string &filename) const
{
    ofstream fichier(filename.c_str());
    assert(fichier.is_open());
    fichier << "P3" << endl;
    fichier << this->dimx << " " << this->dimy << endl;
    fichier << "255" << endl;
    for (int y = 0; y < this->dimy; ++y)
    {
        for (int x = 0; x < this->dimx; ++x)
        {
            Pixel pix = this->getPix(x, y);
            fichier << +pix.r << " " << +pix.g << " " << +pix.b << " ";
        }
    }
    cout << "Sauvegarde de l'image " << filename << " ... OK\n";
    fichier.close();
}

void Image::ouvrir(const std::string &filename)
{
    ifstream fichier(filename.c_str());
    assert(fichier.is_open());
    std::string mot;
    char r, g, b;
    fichier >> mot >> this->dimx >> this->dimy >> mot;
    assert(dimx > 0 && dimy > 0);
    this->tab = new Pixel[this->dimx * this->dimy];
    Pixel pix = Pixel();

    for (int y = 0; y < this->dimy; ++y)
        for (int x = 0; x < this->dimx; ++x)
        {
            fichier >> r >> g >> b;
            pix = Pixel(r, g, b);
            this->setPix(x, y, pix);
        }
    fichier.close();
    cout << "Lecture de l'image " << filename << " ... OK\n";
}

void Image::afficherConsole() const
{
    cout << dimx << " " << dimy << endl;
    for (int y = 0; y < dimy; ++y)
    {
        for (int x = 0; x < dimx; ++x)
        {
            const Pixel &pix = getPix(x, y);
            cout << +pix.r << " " << +pix.g << " " << +pix.b << " ";
        }
        cout << endl;
    }
}

int Image::getDimx() const
{
    return this->dimx;
}

int Image::getDimy() const
{
    return this->dimy;
}

void Image::testRegression()
{
    cout << "Test regression Image" << endl;
    cout << "Test regression Image : Constructeur" << endl;
    Image img = Image(5, 5);
    Image img2 = Image();
    assert(img.dimx == 5);
    assert(img.dimy == 5);
    assert(img2.dimx == 0);
    assert(img2.dimy == 0);
    cout << "Test regression Image : Constructeur OK" << endl;

    cout << "Test regression Image : setPix et getPix" << endl;
    img.setPix(0, 0, Pixel(255, 0, 0));
    Pixel pix = img.getPix(0, 0);
    assert(pix.r == 255);
    assert(pix.g == 0);
    assert(pix.b == 0);
    cout << "Test regression Image : setPix et GetPix OK" << endl;

    cout << "Test regression Image : dessinerRectangle" << endl;
    img.dessinerRectangle(1, 1, 4, 4, Pixel(0, 0, 255));
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            Pixel pix = img.getPix(i, j);
            assert(pix.r == 0);
            assert(pix.g == 0);
            assert(pix.b == 255);
        }
    }
    cout << "Test regression Image : dessinerRectangle OK" << endl;

    cout << "Test regression Image : effacer" << endl;
    img.effacer(Pixel(255, 0, 255));
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            Pixel pix = img.getPix(i, j);
            assert(pix.r == 255);
            assert(pix.g == 0);
            assert(pix.b == 255);
        }
    }
    cout << "Test regression Image : effacer OK" << endl;

    cout << "Test regression Image OK" << endl;
}
