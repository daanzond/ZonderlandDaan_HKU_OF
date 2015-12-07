//
//  Planet.h
//  Planetarium
//
//  Created by Daan Zonderland on 13-11-15.
//
//

#pragma once

#include "ofMain.h"

class Planet{
public:
    Planet();
    virtual ~Planet();
    void setup(string name);
    void update();
    void draw();
    
    float rotation;
    ofParameterGroup planetParamGroup;
    ofParameter<float> rotateSpeed;
    ofParameter<float> distance;
    ofParameter<int> red;
    ofParameter<int> green;
    ofParameter<int> blue;
};
