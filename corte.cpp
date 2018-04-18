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

//Metodos de Tira
Tira::Tira(){
	
}
Tira::~Tira(){
	cout << "Elemento Destruido" << endl;
}




void Tira::setup(bool _vorh){
	vorh = _vorh;
	
	//Diretory images setup
	ofDirectory dir2(path);
	dir = dir2;
	dir.listDir();
	for(int i = 0; i < dir.size(); i++) {
		images.push_back(dir.getPath(i));
	}
	
	//ofParameterGroup setup
	tiraParameters.setName("Tira Controles");
//	tiraParameters.add(sepY.set("Y",0,0,200));
	tiraParameters.add(seVaEnY.set("Colision en Y",4,0,40));

	if (vorh == true){
		tiraParameters.add(ancho.set("Ancho",200,0,ofGetWidth()));
		tiraParameters.add(alto.set("Alto",20,0,ofGetHeight()));
	} else {
		tiraParameters.add(ancho.set("Ancho",20,0,ofGetWidth()));
		tiraParameters.add(alto.set("Alto",200,0,ofGetHeight()));
	}
	tiraParameters.add(rotx.set("Rotar X",0,-1,1));
	tiraParameters.add(roty.set("Rotar Y",0,-1,1));
	tiraParameters.add(rotz.set("Rotar Z",0,-1,1));
	tiraParameters.add(sen.set("Velocidad",0, -0.01, 0.01));
	tiraParameters.add(grados.set("Grados", 0, 0, 720));
	tiraParameters.add(ruta.set("Imagen",0, 0, dir.size()-1));
	if(vorh == true){
		tiraParameters.add(enX.set("Posicion X", 0, -ofGetWidth()/2, ofGetWidth()/2));
		tiraParameters.add(enY.set("Posicion Y", 0, 0, 15));
	}else {
		tiraParameters.add(enX.set("Posicion X", 1, 0, 15));
		tiraParameters.add(enY.set("Posicion Y", 0, -ofGetHeight()/2, ofGetHeight()/2));
	}
	tiraParameters.add(escalarX.set("Escalar X", 1, 0, 20));
	tiraParameters.add(escalarY.set("Escalar Y", 1, 0, 20));
	tiraParameters.add(destruir.set("DESTRUIR", 0,0,1));
	
}




void Tira::anadirCorte(){
	if(vorh == true){
			Corte cort;
			cort.setup(0, flageV, 0, 200, 20, 0, ofRandom(300), "images/1.jpg", 0, 1, 0,1, vorh);
			flageV = flageV - 20;
			//Guarda los cortes en el vector
			cortes.push_back(cort);
	}else{
			Corte cort;
			cort.setup(flageH, -(ofGetHeight()/2), 0, 20, 200, 0, ofRandom(300), "images/1.jpg", 0, 0, 1,1, vorh);
			flageH = flageH + 20;
			//Guarda los cortes en el vector
			cortes.push_back(cort);
	}
}



void Tira::update(){
	ofDirectory dir2(path);
	dir = dir2;
	dir.listDir();
	if(dir.size() > dirAnterior){
		images.push_back(dir.getPath(dir.size()-1));
		dirAnterior = dir.size();
	}
	for(int i = 0; i < cortes.size(); i++){
//		if(sepY != anteriorsepY){
//			cortes[i].y = cortes[i].y + sepY;
//			if (i == cortes.size()-1){
//				anteriorsepY = sepY;
//			}
//		}
		cortes[i].seVaEnY = seVaEnY;
		cortes[i].wid = ancho;
		cortes[i].hei = alto;
		cortes[i].rotX = rotx;
		cortes[i].rotY = roty;
		cortes[i].rotZ = rotz;
		cortes[i].grados = grados;
		cortes[i].sumX = enX;
		cortes[i].sumY = enY;
		cortes[i].scaleX = escalarX;
		cortes[i].scaleY = escalarY;
		cortes[i].seno += sen;
		guardarSeno = cortes[i].seno;
		cortes[i].rutaImagen = ofToString(dir.getPath(ruta));
//		cout << cortes[i].rutaImagen << endl;

	}
}




//Metodos de Corte
Tira::Corte::Corte(){
	
	
}

void Tira::Corte::setup(float posx, float posy, float posz, float width, float height, float sum, float primerPosX, string rutaImg, float senoidal, float sumarX, float sumarY, float skal, bool _verOrHor){
	verOrHor = _verOrHor;
	x = posx;
	y = posy;
	z = posz;
	wid = width;
	hei = height;
	sumX = sumarX;
	sumY = sumarY;
	grados = 0;
	primeraX = primerPosX;
	rutaImagen = rutaImg;
	imagen.load(rutaImagen);
	ofLoadImage(p, rutaImagen);
	//Fijarse de poder perillear con gui el wid y el height de los crops
	if(verOrHor == true){
		p.crop(ofRandom(0, imagen.getWidth() - wid), ofRandom(0, imagen.getHeight() - hei), 200, 20);
	}
	else {
		p.crop(ofRandom(0, imagen.getWidth() - wid), ofRandom(50, imagen.getHeight() - hei), 20, 200);
	}
	p.resize(wid, hei);
	latextu.loadData(p);
	sumador = sum;
	if (primerPosX < 0){
		sumador = ofRandom(0,20);
	} else{
		sumador = ofRandom(-20,0);
	}
	seno = senoidal;
	scaleX = skal;
	scaleY = skal;
}


void Tira::Corte::draw(){
	if(rotX != 0 || rotY != 0 || rotZ != 0){
		ofRotate(sin(seno) * grados, rotX, rotY, rotZ);
	}
	ofPushMatrix();
	latextu.setAnchorPoint(latextu.getWidth()/2, latextu.getHeight()/2);
	//Posible ponerles senos a los scale. Ej: sin(seno)*scaleY
	ofScale(scaleX, scaleY);
	if( verOrHor == true){
		latextu.draw(sin(seno)*sumX, y+=sumY, z, wid, hei);
	}else{
		latextu.draw(x+=sumX, sumY, z, wid, hei);
	}
	ofPopMatrix();

}

void Tira::Corte::colisiona(){
	if( verOrHor == true ){
		if(y >= ofGetHeight()/2 + 20*seVaEnY){
			x = 0;
			y = (0 - ofGetHeight()/2) - hei*seVaEnY;
			if(rutaImagen != rutaAnterior){
				cambioImg();
				rutaAnterior = rutaImagen;
			}
		}
	}else {
		if(x >= ofGetWidth()/2){
			y = 0;
			x = (0 - ofGetWidth()/2) - wid;
			if(rutaImagen != rutaAnterior){
				cambioImg();
				rutaAnterior = rutaImagen;
			}
		}
	}
	if(x <= 0 || x+latextu.getWidth() >= ofGetWidth() ){
		sumador = sumador * -1;
	}
	
}
//Arreglar el cambio de imagenn
void Tira::Corte::cambioImg(){
	imagen.load(rutaImagen);
	ofLoadImage(p, rutaImagen);
	if(verOrHor == true){
		p.crop(ofRandom(0, imagen.getWidth() - wid), ofRandom(0, imagen.getHeight() - hei), 200, 20);
	}
	else {
		p.crop(ofRandom(0, imagen.getWidth() - wid), ofRandom(50, imagen.getHeight() - hei), 20, 200);
	}
	p.resize(wid, hei);
	latextu.loadData(p);
}
