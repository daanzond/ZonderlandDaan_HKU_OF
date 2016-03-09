#include "ofApp.h"

void ofApp::setup() {
    ofSetFrameRate(60);
    fbo.allocate(ofGetWidth(),ofGetHeight(), GL_RGBA16);
    fbo.begin();
    ofBackground(ofColor::black);
    fbo.end();
    
    time = ofGetElapsedTimef();
    
    gui.setup();
    gui.setPosition(10,10);
    
    paramGroupParticle.setName("Particle Settings");
    paramGroupParticle.add(paramlife.set("Life",1,5,1));
    paramGroupParticle.add(paramradius.set("Radius",60, 1, 100));
    paramGroupParticle.add(paramrotate.set("Rotate", 1,0,360));
    gui.add(paramGroupParticle);
    

}

void ofApp::update() {
    
    parameters.radius = paramradius;
    parameters.lifeTime = paramlife;
    parameters.rotate = paramrotate;
    
    float currentTime = ofGetElapsedTimef();
    float elapsedTime = ofClamp(currentTime - time, 0, 0.1);
    time = currentTime;
    
    
    int i = 0;
    while (i <particles.size()){
        if (!particles[i].isAlive){
            particles.erase(particles.begin() +i);
        } else {
            i++;
        }
    }
    
    int newParticles = birthRate * elapsedTime;
    
    for(int i=0; i<newParticles; i++){
        Particle newParticle(&parameters);
        newParticle.setup();
        particles.push_back(newParticle);
        
    }
    
    for(int i=0; i < particles.size(); i++){
        particles[i].update(elapsedTime);
    }
}
void ofApp::draw() {
    ofBackground(ofColor::black);
    
    fbo.begin();
    ofEnableAlphaBlending();
    ofSetColor(ofColor::black, 2);
    ofFill();
    ofDrawRectangle(0,0,ofGetWidth(), ofGetHeight());
    ofDisableAlphaBlending();
    
    ofFill();
    for (int i=0; i < particles.size(); i++){
        particles[i].draw();
    }
    fbo.end();
    
    ofSetColor(ofColor::white);
    fbo.draw(0,0);
    
    gui.draw();

}
