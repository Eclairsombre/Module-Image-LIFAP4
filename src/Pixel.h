#ifndef _PIXEL_H
#define _PIXEL_H

/**
 * @struct Pixel
 *
 * @brief Une structure pour représenter un pixel.
 *
 */
struct Pixel
{
    unsigned char r, g, b; ///< Les composantes rouge, vert et bleu du pixel

    /**
     * @brief Construit un nouveau objet Pixel:: Pixel
     *
     * @return Pixel : Un objet Pixel
     */
    Pixel();

    /**
     * @brief Construit un nouveau objet Pixel:: Pixel
     *
     * @param rr La composante rouge
     * @param gg La composante verte
     * @param bb La composante bleue
     * @return Pixel : Un objet Pixel
     */
    Pixel(unsigned char rr, unsigned char gg, unsigned char bb);

    /**
     * @brief Affiche les composantes du pixel
     *
     * @return void : Affiche les composantes du pixel
     */
    void afficherPixel() const;
};

#endif
