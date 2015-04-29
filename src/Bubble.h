//
//  Bubble.h
//  spriteAnimation
//
//  Created by William Karges on 4/28/15.
//
//

#ifndef __spriteAnimation__Bubble__
#define __spriteAnimation__Bubble__

#include "ofMain.h"

class Bubble {
    
public:
    Bubble() ;
    void setup(float x, float y) ;
    void update() ;
    void draw() ;
    
    
    ofVec2f pos ;
    ofVec2f vel ;
    ofVec2f birth ;
    ofImage bubble ;
    
    
};
#endif /* defined(__spriteAnimation__Bubble__) */
