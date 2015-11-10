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
    
    arduino.connect("/dev/cu.usbmodem1411",57600);
    arduino.sendFirmwareVersionRequest();
    
}

//--------------------------------------------------------------
void ofApp::update() {

    arduino.update();
    
    for (int i=0; i<balls.size(); i++) {
        balls[i].update();
    }
    
    for (int i=0; i<bouncingobjects.size(); i++){
        bouncingobjects[i].update();
    }
    
    for (int i=0; i<bouncingtri.size(); i++){
        bouncingtri[i].update();
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
}

//--------------------------------------------------------------
void ofApp::setupArduino(const int& version){
    //remove listener because we don't need it anymore
    ofRemoveListener(arduino.EInitialized, this, &ofApp::setupArduino);
    // set flag: Arduino now ready for use
    isArduinoInitialized = true;
    
    //print firmware name and version to the console
    arduino.sendDigitalPinMode(12, ARD_OUTPUT);
    
    //set listeners for pin events
    ofAddListener(arduino.EDigitalPinChanged, this, &ofApp::digitalPinChanged);
    ofAddListener(arduino.EAnalogPinChanged, this, &ofApp::analogPinChanged);
    
}

//--------------------------------------------------------------
void ofApp::digitalPinChanged(const int& pinNum){
    //get value with arduino.getDigital (pinNum)
}

//--------------------------------------------------------------
void ofApp::analogPinChanged(const int& pinNum){
    //get value with arduino.getAnalog(pinNum));
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    
    if (key == 'w'){
        arduino.sendDigital(13, ARD_HIGH); //this will switch the on-board Arduino LED on
    }
    
    else{
        arduino.sendDigital(13, ARD_LOW); //this will switch the on-board Arduino LED on
    }

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
    arduino.sendDigital(13, ARD_HIGH); //this will switch the on-board Arduino LED on

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
    arduino.sendDigital(13, ARD_LOW); //this will switch the on-board Arduino LED OFF

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
