# Module Image

Création de fonction permettant de simuler des pixels, des images et d'afficher celle-ci avec SDL2 dans le cadre du LIFAP4.

## I) Requis
1. Linux OS
2.  g++ compiler

    Télécharger avec : 
    ```sudo apt update && sudo apt upgrade``` 
    ```sudo apt-get install g++ ```

3. SDL2 librairie

    Télécharger avec : 
    ```sudo apt install libsdl2-dev libsdl2-mixer-dev libsdl2-image-dev libsdl2-ttf-dev```

## II) Télécharger et compiler
1. Ouvrir un terminal dans le dossier souhaité et exécuter :

   ```git clone https://forge.univ-lyon1.fr/p2207113/module-image.git```
2. Après, exécuter dans le même terminal :
   ```make```   

## III) Organisation

- Dossier src : Contient tous les fichiers .cpp et .h 
- Dossier obj : Contient tous les fichiers .o 
- Dossier  doc : Contient le diagramme des classes et la documentation avec Doxygen
- Dossier data : Contient les images générées avec le code
- Dossier bin : Contient tous les exécutables

## IV) Run

- Lancer le test de régression :
```bash
./bin/test
```

- Lancer la création des images :
```bash
./bin/exemple
```

- Lancer l'affichage d'une image avec SDL2 :
```bash
./bin/affichage
```

## V) Collaborateurs
<a href="https://github.com/Xeon0X">Xeon0X</a>
<a href="https://github.com/You6f">You6f</a>



