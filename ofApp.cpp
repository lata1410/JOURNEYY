#include "ofApp.h"
#include <vector>
#include <iostream>

//--------------------------------------------------------------
void ofApp::setup(){
	renderGui = true;
	
	//Primera tira
	//Tira primerTira;
	//primerTira.setup( true );
	
	//Pone el vector que acaba de llenar en el vector de vectores 'myVect'
	//myVect.push_back(primerTira);
	
	//Se le suma uno al index de los vectores porque ya creamos una tira de imagenes
	//indexV = 1;

	//SETUP Y ADD GUI

	//tiraGroup.add(myVect[0].tiraParameters);
	//gui.setup(tiraGroup);

	firstColor.r = ofRandom(255);
	firstColor.g = ofRandom(255);
	firstColor.b = ofRandom(255);
	secColor.r = ofRandom(255);
	secColor.g = ofRandom(255);
	secColor.b = ofRandom(255);
}

//--------------------------------------------------------------
void ofApp::update(){
	for ( int w = 0; w < myVect.size(); w++ ) {
		if(myVect.size() > 0){
			//Puede ser que sedesfasen a no eliminar el elemento de gui
			if( myVect[w].destruir == 1 ){
				int tope = myVect[w-1].tiraParameters.size();
				for(int i = 0; i < tope; i++ ){
					myVect[w].tiraParameters.remove(myVect[w].tiraParameters.back());
				}
				tiraGroup.remove(w);
				myVect[w].tiraParameters.setName("D");
				gui.setup(tiraGroup);
				myVect.erase(myVect.begin() + w);
				//myVect[w].tiraParameters.setName("Tira " + ofToString(w));
			}
			myVect[w].update();
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	cout << myVect.size() << endl;
	cout << tiraGroup.size() << endl;

	//Background en gradiente con dos colores que luego va a ser tomados de alguna de las texturas de las tiras que esten en la pantalla
	//ofBackgroundGradient(firstColor, secColor, OF_GRADIENT_LINEAR);
	ofBackground(0);
	//Frame Rate
	ofDrawBitmapString(ofToString(ofGetFrameRate()), 10, 10);
	//Dibuja la GUI
	gui.draw();
	//Traslada el centro al medio de la pantalla
	ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
	//A–ade tira de imagenes si la booleana andirTira es verdadera

	if(anadirTiraV == true){
		if(nuevatira == true ){
			cout << myVect.size() << endl;
			Tira newTira;
			myVect.push_back(newTira);
			nuevatira = false;
		}
	
		if(setupTira == true){
				myVect[myVect.size()-1].setup( true );
				setupTira = false;
			}
			if( myVect[myVect.size()-1].cortes.size() < 12 ){
				myVect[myVect.size()-1].anadirCorte();
			}
		
		
		if ( myVect[myVect.size()-1].cortes.size() == 12 ) {
			myVect[myVect.size()-1].tiraParameters.setName("Tira " + ofToString(myVect.size()-1));
			tiraGroup.add(myVect[myVect.size()-1].tiraParameters);
			gui.setup(tiraGroup);
			cout << "Cosas en TiraGroup: " + ofToString(tiraGroup.size()) << endl;
			anadirTiraV = false;
		}
	}
	if(anadirTiraH == true){
		if(nuevatira == true ){
			cout << myVect.size() << endl;
			Tira newTira;
			myVect.push_back(newTira);
			nuevatira = false;
		}
		
		if(setupTira == true){
			myVect[myVect.size()-1].setup( false );
			setupTira = false;
		}
		if( myVect[myVect.size()-1].cortes.size() < 45 ){
			myVect[myVect.size()-1].anadirCorte();
		}
		if ( myVect[myVect.size()-1].cortes.size() == 45 ) {
			myVect[myVect.size()-1].tiraParameters.setName("Tira " + ofToString(myVect.size()-1));
			tiraGroup.add(myVect[myVect.size()-1].tiraParameters);
			gui.setup(tiraGroup);
			anadirTiraH = false;
		}
	}
	
	//RENDER
	if(myVect.size() > 0){
		for ( int w = 0; w < myVect.size(); w++ ) {
			for ( int i = 0 ; i < myVect[w].cortes.size(); i++ ) {
				//Valores random para el gradient del background
				if ( ofGetElapsedTimeMillis() % 1000 == 0 ){
					firstColor = myVect[w].cortes[i].p.getColor(ofRandom(myVect[w].cortes[i].p.getWidth()), ofRandom(myVect[w].cortes[i].p.getHeight()));
					secColor = myVect[w].cortes[i].p.getColor(ofRandom(myVect[w].cortes[i].p.getWidth()), ofRandom(myVect[w].cortes[i].p.getHeight()));
				}
				myVect[w].cortes[i].draw();
				myVect[w].cortes[i].colisiona();
			}
		}
	}
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if(key == OF_KEY_UP){
		anadirTiraV = true;
		setupTira = true;
		nuevatira = true;
	} else if(key == OF_KEY_LEFT){
		anadirTiraH = true;
		setupTira = true;
		nuevatira = true;
	}
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
