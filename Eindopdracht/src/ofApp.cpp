#include "ofApp.h"

ofSoundPlayer lose;

//--------------------------------------------------------------
void ofApp::setup(){
    lose.loadSound("alarm.wav");
    serial.setup(0, 9600);
    cam.initGrabber(320, 240);
    tookPhoto = false;
    zwaailicht.loadImage("zwaailicht.gif");
    val = -90;
}

//--------------------------------------------------------------
void ofApp::update(){
    cam.update();
    if (serial.available() >= 5)
    {
        if (serial.readByte() == 0x44 && serial.readByte() == 0x7A) //als ik DZ ontvang
        {
            uint8_t high = serial.readByte();
            uint8_t low = serial.readByte();
            mergeInt(high, low);
            
            serial.flush();
        }
    }
    
    if (val >= -70 && !tookPhoto){
        plaatje.setFromPixels(cam.getPixelsRef());
        plaatje.saveImage("test" + ofToString(ofGetUnixTime()) + ".png");
        tookPhoto = true;
        lose.play();

    }
    else if (val <= -71)
    {
        tookPhoto = false;
        lose.stop();

    }
    
    zwaailicht.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.draw(0, 0, ofGetWidth(), ofGetHeight());
    ofDrawBitmapString(ofToString(val), 100, 100);
    
    if (tookPhoto)
    {
        ofSetColor(255,255,255);
        zwaailicht.draw(0, 0);
        zwaailicht.draw(ofGetWidth() - zwaailicht.width, 0);
        zwaailicht.draw(0, ofGetHeight() - zwaailicht.height);
        zwaailicht.draw(ofGetWidth() - zwaailicht.width, ofGetHeight() - zwaailicht.height);
        ofSetColor(255,0,0);
    }
    else
    {
        ofSetColor(255,255,255);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp::mergeInt(uint8_t hi, uint8_t lo) {
    uint16_t bytehi = hi << 8;
    uint8_t bytelo = lo;
    val = bytehi + bytelo;
}