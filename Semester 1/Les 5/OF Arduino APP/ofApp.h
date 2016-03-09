#pragma once

#include "ofMain.h"

#include "Ball.h"
#include "bouncingobject.h"
#include "bouncetri.h"

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
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

        vector<Ball> balls;
        vector<bouncingobject> bouncingobjects;
        vector<bouncetri> bouncingtri;
    
    ofArduino arduino;
    bool isArduinoInitialized;
    
private:
    void setupArduino(const int & version);
    void digitalPinChanged(const int & pinNum);
    void analogPinChanged(const int & pinNum);
};
