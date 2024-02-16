#ifndef IMAGE
#define IMAGE

#include "Pixel.h"
#include <string>

/**
 * @class Image
 *
 * @brief Une classe pour représenter une image.
 *
 */

class Image
{
private:
    Pixel *tab;     ///< Le tableau de pixels
    int dimx, dimy; ///< Les dimensions de l'image

public:
    /**
     * @brief Construit un nouvel objet Image:: Image
     * @return Image : Un objet Image
     *
     */
    Image();

    /**
     * @brief Construit un nouvel objet Image:: Image
     *
     * @param dimx La dimension x de l'image
     * @param dimy La dimension y de l'image
     * @return Image : Un objet Image
     */
    Image(int dimx, int dimy);

    /**
     * @brief Détruit l'objet Image:: Image
     *
     */
    ~Image();

    /**
     * @brief Set le pixel à la position (x, y) avec la valeur p.
     *
     * @param x La coordonnée x du pixel
     * @param y La coordonnée y du pixel
     * @param p Le pixel à set
     * @return void : Set le pixel
     */
    void setPix(int x, int y, const Pixel p);

    /**
     * @brief Get le pixel à la position (x, y)
     *
     * @param x La coordonnée x du pixel
     * @param y La coordonnée y du pixel
     * @return  Pixel& :Récupère le pixel original de coordonnées (x,y) en vérifiant sa validité. On récupere le pixel original, pas une copie.
     */
    Pixel &getPix(int x, int y);

    /**
     * @brief Get le pixel à la position (x, y)
     *
     * @param x La coordonnée x du pixel
     * @param y La coordonnée y du pixel
     * @return Pixel : Récupère le pixel original de coordonnées (x,y) en vérifiant sa validité. On récupere une copie du pixel.
     */
    Pixel getPix(int x, int y) const;

    /**
     * @brief Dessine un rectangle de couleur p aux coordonnées (Xmin, Ymin) et (Xmax, Ymax)
     *
     * @param Xmin La coordonnée x du coin en haut à gauche du rectangle
     * @param Ymin La coordonnée y du coin en haut à gauche du rectangle
     * @param Xmax La coordonnée x du coin en bas à droite du rectangle
     * @param Ymax La coordonnée y du coin en bas à droite du rectangle
     * @param p La couleur du rectangle
     * @return  void : Dessine le rectangle
     */
    void dessinerRectangle(int Xmin, int Ymin, int Xmax, int Ymax, const Pixel p);

    /**
     * @brief Efface l'image en la remplissant de la couleur p
     *
     * @param p La couleur de l'effacement
     * @return void : Efface l'image
     */
    void effacer(const Pixel p);

    /**
     * @brief Teste les différentes méthodes de la classe Image
     *
     * @return void : Teste les différentes méthodes de la classe Image
     */
    static void testRegression();

    /**
     * @brief Sauvegarde l'image dans un fichier
     *
     * @param filename Le nom du fichier
     * @return void : Sauvegarde l'image
     */
    void sauver(const std::string &filename) const;

    /**
     * @brief Ouvre un fichier et charge l'image
     *
     * @param filename Le nom du fichier
     * @return void : Charge l'image
     */
    void ouvrir(const std::string &filename);

    /**
     * @brief Affiche l'image dans la console
     *
     * @return void : Affiche l'image
     */
    void afficherConsole() const;

    /**
     * @brief Get la dimension x de l'image
     *
     * @return int : La dimension x de l'image
     */
    int getDimx() const;

    /**
     * @brief Get la dimension y de l'image
     *
     * @return int : La dimension y de l'image
     */
    int getDimy() const;
};

#endif
