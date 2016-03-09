#pragma once

#include "ofMain.h"

class Paddle {
    
public:
    
    Paddle();
    
    void setup();
    void moveup();
    void movedown();
    void draw();
    
    // variables
    float x;
    float y;
    float speedY;
    int width;
    int height;
    ofColor color;
    
private:
    
};
