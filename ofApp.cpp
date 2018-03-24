#include "ofApp.h"
#include <vector>
#include <iostream>

//--------------------------------------------------------------
void ofApp::setup(){
	renderGui = true;
	//Donde inician las primer imagen
	flage = -(ofGetHeight()/2);

	
	//Imagenes en array
	ofDirectory dir2(path);
	dir = dir2;
	dir.listDir();
	for(int i = 0; i < dir.size(); i++) {
		images.push_back(dir.getPath(i));
	}
	cout << images.size() << endl;
	
	//Setea el gui de imagenes desde 0 hasta la cabtidad de imagenes que halla en la carpeta antes de arrancar el programa
	ofParameter<int> ruta{"Imagen",0,0, dir.size()};

	//For que inicializa la primer tira de imagenes(Cortes)
	for(int i = 0; i<45; i++) {
		Corte cort;
		cort.setup(-(ofGetWidth()/2), flage, 0, 200, 20, 0, ofRandom(300), i, "yo.jpg", 0, 0,0);
		flage = flage + 20;
		//Guarda los cortes en el vector
		loVectore[indexV].push_back(cort);
	}
	
	//Pone el vector que acaba de llenar en el vector ce vectores 'myVect'
	myVect.push_back(loVectore[indexV]);
	//Se le suma uno al index de los vectores porque ya creamos una tira de imagenes
	indexV = 1;
	
	
	//Vectores de GUI DATA
	vectorAnchos.push_back(ancho);
	vectorAltos.push_back(alto);
	vectorRotX.push_back(rotx);
	vectorRotY.push_back(roty);
	vectorRotZ.push_back(rotz);
	vectorSen.push_back(sen);
	vectorRuta.push_back(ruta);
	vectorEnX.push_back(enX);
	vectorEnY.push_back(enY);
	vectorEscalarX.push_back(escalarX);
	vectorEscalarY.push_back(escalarY);

	//SETUP Y ADD GUI
	gui.setup();
	grupo.setup("UNO");
	grupo.add(vectorAnchos[0]);
	grupo.add(vectorAltos[0]);
	grupo.add(vectorRotX[0]);
	grupo.add(vectorRotY[0]);
	grupo.add(vectorRotZ[0]);
	grupo.add(vectorSen[0]);
	grupo.add(vectorRuta[0]);
	grupo.add(vectorEnX[0]);
	grupo.add(vectorEnY[0]);
	grupo.add(vectorEscalarX[0]);
	grupo.add(vectorEscalarY[0]);
	gui.add(&grupo);
	firstColor.r = ofRandom(255);
	firstColor.g = ofRandom(255);
	firstColor.b = ofRandom(255);
	secColor.r = ofRandom(255);
	secColor.g = ofRandom(255);
	secColor.b = ofRandom(255);
}

//--------------------------------------------------------------
void ofApp::update(){
	dir.listDir();
	if(dir.size() > dirAnterior){
		images.push_back(dir.getPath(dir.size()-1));
		dirAnterior = dir.size();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	//Background en gradiente con dos colores que luego va a ser tomados de alguna de las texturas de las tiras que esten en la pantalla
	ofBackgroundGradient(firstColor, secColor, OF_GRADIENT_LINEAR);
	//Frame Rate
	ofDrawBitmapString(ofToString(ofGetFrameRate()), 10, 10);
	//Dibuja la GUI
	gui.draw();
	//Traslada el centro al medio de la pantalla
	ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
	//A–ade tira de imagenes si la booleana andirTira es verdadera
	if(anadirTira == true){
		setupAnadirTira = true;
		//o++;
		Corte cort;
		cort.setup(-(ofGetWidth()/2), flage, 0, 200, 20, 0, ofRandom(300), o, "yo.jpg", 0,0,0);
		loVectore[indexV].push_back(cort);
		flage = flage - 20;
	}
	//Setea la GUI de la nueva tira y los vectores de la misma
	if(loVectore[indexV].size() == 45 && setupAnadirTira == true){
		anadirTira = false;
		myVect.push_back(loVectore[indexV]);
		//o = 0;
		indexV++;
		setupAnadirTira = false;
		ofParameterGroup aver;
		ofParameter<float> ancho{"Ancho",200,0,ofGetWidth()};
		ofParameter<float> alto{"Alto",20,0,ofGetHeight()};
		ofParameter<float> rotx{"Rotar X",0,-1,1};
		ofParameter<float> roty{"Rotar Y",0,-1,1};
		ofParameter<float> rotz{"Rotar Z",0,-1,1};
		ofParameter<float> sen{"Velocidad",0,0,0.001};
		ofParameter<int> ruta{"Imagen",0,0, images.size()};
		ofParameter<float> enX{"Posicion X", 0, -ofGetWidth()/2, ofGetWidth()/2};
		ofParameter<float> enY{"Posicion Y", 2, 0, 20};
		ofParameter<float> escalarX{"Escalar X",1,0,20};
		ofParameter<float> escalarY{"Escalar Y",1,0,20};
		vectorAnchos.push_back(ancho);
		vectorAltos.push_back(alto);
		vectorRotX.push_back(rotx);
		vectorRotY.push_back(roty);
		vectorRotZ.push_back(rotz);
		vectorSen.push_back(sen);
		vectorRuta.push_back(ruta);
		vectorEscalarX.push_back(escalarX);
		vectorEscalarY.push_back(escalarY);
		vectorEnX.push_back(enX);
		vectorEnY.push_back(enY);
		aver.add(vectorAnchos[myVect.size()-1]);
		aver.add(vectorAltos[myVect.size()-1]);
		aver.add(vectorRotX[myVect.size()-1]);
		aver.add(vectorRotY[myVect.size()-1]);
		aver.add(vectorRotZ[myVect.size()-1]);
		aver.add(vectorSen[myVect.size()-1]);
		aver.add(vectorRuta[myVect.size()-1]);
		aver.add(vectorEnX[myVect.size()-1]);
		aver.add(vectorEnY[myVect.size()-1]);
		aver.add(vectorEscalarX[myVect.size()-1]);
		aver.add(vectorEscalarY[myVect.size()-1]);
		gui.add(aver);
	}
	
	//RENDER
	for ( int w = 0; w<myVect.size(); w++ ) {
		for ( int i = 0 ; i<myVect[0].size(); i++ ) {
			//Valores random para el gradient del background
			if ( ofGetElapsedTimeMillis() % 1000 == 0 ){
				firstColor = myVect[w][i].p.getColor(ofRandom(myVect[w][i].p.getWidth()), ofRandom(myVect[w][i].p.getHeight()));
				secColor = myVect[w][i].p.getColor(ofRandom(myVect[w][i].p.getWidth()), ofRandom(myVect[w][i].p.getHeight()));
			}

		//GUI
		myVect[w][i].wid = vectorAnchos[w];
		myVect[w][i].hei = vectorAltos[w];
		myVect[w][i].rotX = vectorRotX[w];
		myVect[w][i].rotY = vectorRotY[w];
		myVect[w][i].rotZ = vectorRotZ[w];
		myVect[w][i].sumX = vectorEnX[w];
		myVect[w][i].sumY = vectorEnY[w];
		myVect[w][i].scaleX = vectorEscalarX[w];
		myVect[w][i].scaleY = vectorEscalarY[w];
		myVect[w][i].seno += vectorSen[w];
		guardarSeno = myVect[w][i].seno;
		
		myVect[w][i].draw();
		myVect[w][i].colisiona();
		
		//Destruccion de las imagenes que llegan al borde de la pantalla
		if (myVect[w][i].destruccion == true){
			myVect[w][i].setup(-(ofGetWidth()/2), (0 - ofGetHeight()/2)-alto, 0, 200, 20, 0, ofRandom(300), i, images[vectorRuta[w]], guardarSeno, enX,vectorEscalarY[w]);
			myVect[w][i].destruccion = false;
		}
	}
	}
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if(key == OF_KEY_UP){
		anadirTira = true;
		o = 0;
		vector<Corte> dos;
	} else if (key == OF_KEY_DOWN){
		myVect.pop_back();
		vectorAnchos.pop_back();
		vectorAltos.pop_back();
		vectorRotX.pop_back();
		vectorRotY.pop_back();
		vectorRotZ.pop_back();
		vectorSen.pop_back();
		vectorRuta.pop_back();
		vectorEscalarX.pop_back();
		vectorEscalarY.pop_back();
		vectorEnX.pop_back();
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
