#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    // kies random start coordinaten
    x = ofRandom(0, ofGetWidth());
    y = ofRandom(0, ofGetHeight());

    // random snelheid
    speedX = ofRandom(-10, 10);
    speedY = ofRandom(-10, 10);
    
    // kies random start coordinaten
    x2 = ofRandom(0, ofGetWidth());
    y2 = ofRandom(0, ofGetHeight());
    
    // random snelheid
    speedX2 = ofRandom(-10, 10);
    speedY2 = ofRandom(-10, 10);

    // grootte van cirkel
    radius = 40;

    color.set(ofRandom(255),ofRandom(255),ofRandom(255));
}

//--------------------------------------------------------------
void ofApp::update() {

    // links/ rechts tegen de rand aan? keer om!
    if(x < 0 ) {
    color. set(ofRandom(255), ofRandom(255), ofRandom(255));
        radius =(ofRandom(255));
        x = 0;
        speedX = -speedX;
    } else if(x > ofGetWidth()) {
        radius =(ofRandom(255));
        color. set(ofRandom(255), ofRandom(255), ofRandom(255));
        x = ofGetWidth();
        speedX = -speedX;
    }

    // boven/onder tegen de rand aan? keer om!
    if(y < 0 ) {
        radius =(ofRandom(255));
        color. set(ofRandom(255), ofRandom(255), ofRandom(255));
        y = 0;
        speedY = -speedY;
    } else if(y > ofGetHeight()) {
        radius =(ofRandom(255));
        color. set(ofRandom(255), ofRandom(255), ofRandom(255));
        y = ofGetHeight();
        speedY = -speedY;
    }

    // bereken nieuwe coordinaten
    x+=speedX;
    y+=speedY;
    
    // links/ rechts tegen de rand aan? keer om!
    if(x2 < 0 ) {
        color. set(ofRandom(255), ofRandom(255), ofRandom(255));
        radius =(ofRandom(255));
        x2 = 0;
        speedX2 = -speedX2;
    } else if(x2 > ofGetWidth()) {
        radius =(ofRandom(255));
        color. set(ofRandom(255), ofRandom(255), ofRandom(255));
        x2 = ofGetWidth();
        speedX2 = -speedX2;
    }
    
    // boven/onder tegen de rand aan? keer om!
    if(y2 < 0 ) {
        radius =(ofRandom(255));
        color. set(ofRandom(255), ofRandom(255), ofRandom(255));
        y2 = 0;
        speedY2 = -speedY2;
    } else if(y > ofGetHeight()) {
        radius =(ofRandom(255));
        color. set(ofRandom(255), ofRandom(255), ofRandom(255));
        y2 = ofGetHeight();
        speedY2 = -speedY2;
    }
    
    // bereken nieuwe coordinaten
    x2+=speedX2;
    y2+=speedY2;
}

//--------------------------------------------------------------
void ofApp::draw() {
    ofSetColor(color);
    ofCircle(x, y, radius);
    ofCircle(x2, y2, radius);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
