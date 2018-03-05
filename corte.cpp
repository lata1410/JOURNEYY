//
//  corte.cpp
//  retrato
//
//  Created by Lautaro on 25/11/17.
//
//

#include "corte.hpp"
#include <vector>
#include <string>

Corte::Corte(){
	
	
}

void Corte::setup(float posx, float posy, float posz, float width, float height, float sum, float primerPosX, int posVector, string rutaImg, float senoidal, float sumarX, float skal){
	x = posx;
	y = posy;
	z = posz;
	wid = width;
	hei = height;
	sumX = sumarX;
	//sumY = sumarY;

	firstX = x;
	firstY = y;
	primeraX = primerPosX;
	rutaImagen = rutaImg;
	imagen.load(rutaImg);
	ofLoadImage(p, rutaImagen);
	if (destruccion == false){
		p.crop(0, ofRandom(50, imagen.getHeight()-50), p.getWidth(), 200);
	} else {
		p.crop(0, ofRandom(50, imagen.getHeight()-50), p.getWidth(), 200);
	}
	p.resize(wid, hei);
	latextu.loadData(p);
	sumador = sum;
	//x = x+primerPosX;
	if (primerPosX < 0){
		sumador = ofRandom(0,20);
	} else{
		sumador = ofRandom(-20,0);
	}
	seno = senoidal;
	scaleY = skal;
}


void Corte::draw(){
	ofRotate(sin(seno)*360,rotX,rotY,rotZ);
	ofPushMatrix();
	latextu.setAnchorPoint(latextu.getWidth()/2, latextu.getHeight()/2);
	ofScale(scaleX, scaleY);
	latextu.draw(sumX, y+=sumY, z, wid, hei);
	ofPopMatrix();
}

void Corte::colisiona(){
	if(x <= 0 || x+latextu.getWidth() >= ofGetWidth() ){
		sumador = sumador * -1;
	}
	if(y >= ofGetHeight()/2 + hei*4){
		destruccion = true;
	}
}

void Corte::cortar(){

}
