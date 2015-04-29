//
//  Diver.cpp
//  spriteAnimation
//
//  Created by William Karges on 4/28/15.
//
//

#include "Diver.h"

Diver::Diver() {
    pos = ofVec2f(100, 150) ;
    vel = ofVec2f(ofRandom(2, 5), 0) ;
}
void Diver::setup(float _x, float _y) {
    pos = ofVec2f(_x, _y) ;
}
void Diver::update() {
    pos += vel ;
}