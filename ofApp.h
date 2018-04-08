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

	//Vector de vectores de cortes (tiras) 
	vector <Tira> myVect;
	ofxPanel gui;
	ofParameterGroup tiraGroup;
	float flage;
	float guardarSeno;
	bool renderGui;
	bool anadirTiraV;
	bool anadirTiraH;
	bool setupTira;
	bool nuevatira;
	string path = "images";
	ofDirectory dir;
	int dirAnterior;
	int o = 0;
	ofColor firstColor;
	ofColor secColor;
	Tira newTira;


};
