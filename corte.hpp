//
//  corte.hpp
//  retrato
//
//  Created by Lautaro on 25/11/17.
//
//

#ifndef corte_hpp
#define corte_hpp

#include <stdio.h>
#include <string>
#include "ofMain.h"


class Corte {
public:
	Corte();
	ofImage imagen;
	void setup(float posx, float posy, float posz, float width, float height, float sum, float primerPosX, int posVector, string rutaImg, float senoidal, float sumarX, float skal);
	void cortar();
	void draw();
	void colisiona();
	float sumador, primeraX, firstX, firstY;
	bool destruccion;
	ofPixels p;
	ofTexture latextu;
	float seno;
	float x, y, z, wid, hei, rotX, rotY, rotZ, sumX, sumY, scaleX, scaleY;
	string rutaImagen;
};



#endif /* corte_hpp */
