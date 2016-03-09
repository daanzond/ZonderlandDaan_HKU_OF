#include "Ball.h"
Ball::Ball(){
}

void Ball::setup(){
    x = ofGetWidth() / 2;      // give some random positioning
    y = ofGetHeight() / 2;

    int smoother = 2;
    speedX = 10;           // and random speed and direction
    if (abs(speedX) < 1)
        speedX = 1;
    speedY = ofRandom(-(speedX/smoother), (speedX/smoother));

     radius = 20;

    color.set(ofRandom(255),ofRandom(255),ofRandom(255)); // one way of defining digital color is by adddressing its 3 components individually (Red, Green, Blue) in a value from 0-255, in this example we're setting each to a random value
}


void Ball::update(){
    if(x < 0 ){
        x = 0;
        //speedX *= -1;
   } else if(x > ofGetWidth()){
        x = ofGetWidth();
        speedX *= -1;
       play.boinks();
    }

    if(y < 0 ){
        y = 0;
        speedY *= -1;
    } else if(y > ofGetHeight()){
        y = ofGetHeight();
        speedY *= -1;
    }

    x+=speedX;
    y+=speedY;
}

void Ball::draw(){
    ofSetColor(255);
    ofCircle(x, y, radius);
}
