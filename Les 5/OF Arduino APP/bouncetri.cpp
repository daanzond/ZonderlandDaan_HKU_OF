//
//  bouncetri.cpp
//  BounceVector
//
//  Created by Daan Zonderland on 07-10-15.
//
//

#include "bouncetri.h"

bouncetri::bouncetri(){

}


void bouncetri::draw(){
    
    ofSetCircleResolution(3);
    ofSetColor(color);
    ofCircle(x, y, radius);
    ofSetCircleResolution(100);
}