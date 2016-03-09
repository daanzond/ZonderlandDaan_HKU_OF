//
//  bouncerekt.cpp
//  BounceVector
//
//  Created by Daan Zonderland on 10-11-15.
//
//

#include "bouncerekt.h"


bouncerekt::bouncerekt(){
    
}


void bouncerekt::draw(){
    
    ofSetCircleResolution(4);
    ofSetColor(color);
    ofCircle(x, y, radius);
    ofSetCircleResolution(100);
}