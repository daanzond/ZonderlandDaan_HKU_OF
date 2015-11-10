#include "paddle.h"
Paddle::Paddle(){
}

void Paddle::setup(){
    
    height = 100;
    width = 20;
    
    x = 20;      // positioning of paddle
    y = (ofGetHeight() / 2);
    
    speedY = 20;
    
    color.set(ofRandom(255),ofRandom(255),ofRandom(255)); // one way of defining digital color is by adddressing its 3 components individually (Red, Green, Blue) in a value from 0-255, in this example we're setting each to a random value
}

void Paddle::moveup(){
    if (y - speedY > 0)
        y -= speedY;
    
}
void Paddle::movedown(){
    if (y + speedY < ofGetHeight())
    y += speedY;

}



void Paddle::draw(){
    
    ofSetColor(color);
    ofRect(x, y-(height)/2, width, height);
}
