//
//  bouncingobject.h
//  BounceVector
//
//  Created by Daan Zonderland on 07-10-15.
//
//

#ifndef BounceVector_bouncingobject_h
#define BounceVector_bouncingobject_h


#include "ofMain.h"

class bouncingobject {
public:
    
    bouncingobject();
    
    void setup();
    void update();
    void draw();
    
    // variables
    float x;
    float y;
    float speedY;
    float speedX;
    int radius;
    ofColor color;
    
private:

    
};

#endif
