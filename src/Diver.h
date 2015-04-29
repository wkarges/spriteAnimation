//
//  Diver.h
//  spriteAnimation
//
//  Created by William Karges on 4/28/15.
//
//

#ifndef __spriteAnimation__Diver__
#define __spriteAnimation__Diver__
#include "ofMain.h"

class Diver {
    
public:
    Diver() ;
    void setup(float x, float y) ;
    void update() ;
    
    ofVec2f pos ;
    ofVec2f vel ;
    float rot;
    
    
};

#endif /* defined(__spriteAnimation__Diver__) */
