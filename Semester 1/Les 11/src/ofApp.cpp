#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255,255,255);
    ofSetFrameRate(60);
    //ofSetVerticalSync(true);
    
    video.loadMovie("video.mp4");
    video.play();
    video.setLoopState(OF_LOOP_NORMAL);
}

//--------------------------------------------------------------
void ofApp::update(){
    video.update();
    rotate++;
}

//--------------------------------------------------------------
void ofApp::draw(){
    video.draw(0,0);
    ofScale(0.7,0.7,0.7);
    ofTranslate(400,200);
    ofRotateX(rotate);
    ofRotateY(rotate);
    video.draw(0,0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}
