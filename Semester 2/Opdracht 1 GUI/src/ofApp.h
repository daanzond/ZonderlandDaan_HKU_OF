#pragma once

#include "ofMain.h"
#include "Parameters.h"
#include "Particle.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp {
 public:
  void setup();
  void update();
  void draw();
    
  ofFbo fbo;
    
  float time;
    
  Parameters parameters;
    
    vector<Particle> particles;
    
    ofxPanel gui;
    
    ofParameterGroup    paramGroupParticle;
    ofParameter<float>  paramradius;
    ofParameter<float>  paramlife;
    ofParameter<float>  paramrotate;
    float birthRate = 1500;
    
    
};
