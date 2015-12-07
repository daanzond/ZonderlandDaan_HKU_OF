#pragma once

#include "ofMain.h"



class ofApp : public ofBaseApp{
    ofSoundPlayer lose;

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
    
    ofVideoGrabber cam;
    ofSerial serial;
    int16_t val;
    void mergeInt(unsigned char hi, unsigned char lo);
    ofImage plaatje;
	
    bool tookPhoto;
    ofImage zwaailicht;
};
