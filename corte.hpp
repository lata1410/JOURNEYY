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
#include "ofxGui.h"


class Tira{
public:
	Tira();
	void setup(bool _vorh);
	void anadirCorte();
	void update();
	bool vorh;
	string path = "images";
	ofDirectory dir;
	int dirAnterior;
	vector<string> images;
	ofParameterGroup tiraParameters;
	ofParameter<float> sepY;
	ofParameter<float> seVaEnY;

	ofParameter<float> ancho;
	ofParameter<float> alto;
	ofParameter<float> rotx;
	ofParameter<float> roty;
	ofParameter<float> rotz;
	ofParameter<float> sen;
	ofParameter<float> grados;
	ofParameter<int> ruta;
	ofParameter<float> enX;
	ofParameter<float> enY;
	ofParameter<float> escalarX;
	ofParameter<float> escalarY;
	ofParameter<int> destruir;
	float guardarSeno;
	class Corte {
	public:
		Corte();
		ofImage imagen;
		void setup(float posx, float posy, float posz, float width, float height, float sum, float primerPosX, string rutaImg, float senoidal, float sumarX, float sumarY, float skal, bool _verOrHor);
		void cortar();
		void draw();
		void colisiona();
		void cambioImg();
		float sumador, primeraX;
		bool destruccion;
		bool cambiarImg;
		bool verOrHor;
		ofPixels p;
		ofTexture latextu;
		float seno;
		float x, y, z, wid, hei, rotX, rotY, rotZ, sumX, sumY, scaleX, scaleY, grados, seVaEnY;
		string rutaImagen;
		string rutaAnterior;
	};
	//Primer vector para la inicializacion
	vector<Corte> loVectore[100];
	int indexV = 0;
	//Donde inician las primer imagen
	float flageV = ofGetHeight()/2;
	float flageH =  -(ofGetWidth()/2);
	vector<Corte> cortes;
	int rutaAnterior = 0;
	string rutaActual;
	bool cambio = false;
	float anteriorsepY, anteriorsepX;
	~Tira();
};



#endif /* corte_hpp */
