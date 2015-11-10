#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup() {
    for (int i=0; i<10; i++) {
        Ball newBall;
        newBall.setup();
        balls.push_back(newBall);
    }
    
    for (int i=0; i<10; i++) {
        bouncingobject newBall;
        newBall.setup();
        bouncingobjects.push_back(newBall);
    }
    
    for (int i=0; i<10; i++) {
        bouncetri newBall;
        newBall.setup();
        bouncingtri.push_back(newBall);
    }
    
    for (int i=0; i<10; i++){
        bouncerekt newBall;
        newBall.setup();
        bouncingrekt.push_back(newBall);
    }
}

//--------------------------------------------------------------
void ofApp::update() {
    for (int i=0; i<balls.size(); i++) {
        balls[i].update();
    }
    
    for (int i=0; i<bouncingobjects.size(); i++){
        bouncingobjects[i].update();
    }
    
    for (int i=0; i<bouncingtri.size(); i++){
        bouncingtri[i].update();
    }
    
    for (int i=0; i<bouncingrekt.size(); i++){
        bouncingrekt[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    for (int i=0; i<balls.size(); i++) {
        balls[i].draw();
    }
    
    for (int i=0; i<bouncingobjects.size(); i++){
     bouncingobjects[i].draw();
    }
    
    for (int i=0; i<bouncingtri.size(); i++){
        bouncingtri[i].draw();
    }
    
    for (int i=0; i<bouncingrekt.size(); i++){
        bouncingrekt[i].draw();
    }
    
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
