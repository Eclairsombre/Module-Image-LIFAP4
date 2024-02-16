CC=g++
CFLAGS= -c -Wall 
LIBFLAGS=-lSDL2main  -lSDL2
OBJ_DIR = obj



all: doc bin/exemple bin/test bin/affichage 

bin/test :  $(OBJ_DIR)/Pixel.o $(OBJ_DIR)/Image.o $(OBJ_DIR)/mainTest.o 
	$(CC) $(OBJ_DIR)/Pixel.o $(OBJ_DIR)/Image.o $(OBJ_DIR)/mainTest.o -o bin/test

bin/exemple: $(OBJ_DIR)/Pixel.o $(OBJ_DIR)/Image.o $(OBJ_DIR)/mainExemple.o
	$(CC) $(OBJ_DIR)/Pixel.o $(OBJ_DIR)/Image.o $(OBJ_DIR)/mainExemple.o -o bin/exemple

bin/affichage: $(OBJ_DIR)/Pixel.o $(OBJ_DIR)/Image.o $(OBJ_DIR)/ImageViewer.o $(OBJ_DIR)/mainAffichage.o 
	$(CC) $(OBJ_DIR)/Pixel.o $(OBJ_DIR)/Image.o $(OBJ_DIR)/ImageViewer.o $(OBJ_DIR)/mainAffichage.o $(LIBFLAGS) -o bin/affichage

$(OBJ_DIR)/mainTest.o: src/mainTest.cpp src/Pixel.h src/Image.h
	$(CC) $(CFLAGS) src/mainTest.cpp -o $(OBJ_DIR)/mainTest.o

$(OBJ_DIR)/mainExemple.o: src/mainExemple.cpp src/Pixel.h src/Image.h
	$(CC) $(CFLAGS) src/mainExemple.cpp -o $(OBJ_DIR)/mainExemple.o

$(OBJ_DIR)/mainAffichage.o: src/mainAffichage.cpp src/ImageViewer.h src/Pixel.h src/Image.h
	$(CC) $(CFLAGS) src/mainAffichage.cpp -o $(OBJ_DIR)/mainAffichage.o

$(OBJ_DIR)/ImageViewer.o: src/ImageViewer.cpp src/ImageViewer.h src/Pixel.h src/Image.h
	$(CC) $(CFLAGS) src/ImageViewer.cpp -o $(OBJ_DIR)/ImageViewer.o

$(OBJ_DIR)/Pixel.o: src/Pixel.cpp src/Pixel.h
	$(CC) $(CFLAGS) src/Pixel.cpp -o $(OBJ_DIR)/Pixel.o

$(OBJ_DIR)/Image.o: src/Image.cpp src/Image.h src/Pixel.h
	$(CC) $(CFLAGS) src/Image.cpp -o $(OBJ_DIR)/Image.o


clean:
	rm -rf $(OBJ_DIR)/*.o bin/exemple bin/test bin/affichage
	rm -rf data/*.ppm

doc: doc/doxyfile
	doxygen doc/doxyfile



