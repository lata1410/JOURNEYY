#pragma once

#include "ofMain.h"
#include "corte.hpp"
#include "ofxGui.h"
#include <string>



class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
	
	//Mis variables

	vector <vector <Corte>> myVect;
	vector<Corte> loVectore[100];
	int indexV = 0;


	ofxPanel gui;
	ofxGuiGroup grupo;
	string images[3];
	float flage;
	float guardarSeno;
	bool renderGui;
	bool sumaresta;
	bool setupAnadirTira;
	bool anadirTira;
	
	vector<ofParameter<float>> vectorAnchos;
	vector<ofParameter<float>> vectorAltos;
	vector<ofParameter<float>> vectorRotX;
	vector<ofParameter<float>> vectorRotY;
	vector<ofParameter<float>> vectorRotZ;
	vector<ofParameter<float>> vectorSen;
	vector<ofParameter<int>> vectorRuta;
	vector<ofParameter<float>> vectorEnX;
	vector<ofParameter<float>> vectorEnY;
	vector<ofParameter<float>> vectorEscalarX;
	vector<ofParameter<float>> vectorEscalarY;

	
	ofParameter<float> ancho{"Ancho",200,0,ofGetWidth()};
	ofParameter<float> alto{"Alto",20,0,ofGetHeight()};
	ofParameter<float> rotx{"Rotar X",0,-1,1};
	ofParameter<float> roty{"Rotar Y",0,-1,1};
	ofParameter<float> rotz{"Rotar Z",0,-1,1};
	ofParameter<float> sen{"Velocidad",0,0,0.001};
	ofParameter<int> ruta{"Imagen",0,0,2};
	ofParameter<float> enX{"Posicion X", 0, -ofGetWidth()/2, ofGetWidth()/2};
	ofParameter<float> enY{"Posicion Y", 2, 0, 15};
	ofParameter<float> escalarX{"Escalar X",1,0,20};
	ofParameter<float> escalarY{"Escalar Y",1,0,20};
	
	//ofParameter<float> enY{"Posicion Y", 2, -ofGetHeight(), ofGetHeight()};
	//ofParameter<float> enZ{"Posicion Z", 0, -ofGetWidth(), ofGetWidth()};
	//vector <vector <Corte>> loVectore;
	//vector<Corte> dos;
	int o = 0;
	ofColor firstColor;
	ofColor secColor;
	
};
