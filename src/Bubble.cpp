//
//  Bubble.cpp
//  spriteAnimation
//
//  Created by William Karges on 4/28/15.
//
//

#include "Bubble.h"
Bubble::Bubble() {
    pos = ofVec2f(550, 360) ;
    vel = ofVec2f(ofRandom(-1,1), ofRandom(-4,-1)) ;
}

void Bubble::setup(float _x, float _y) {
    pos = ofVec2f(_x, _y) ;
    birth = pos ;
}

void Bubble::update() {
    pos += vel ;
}

void Bubble::draw() {
    ofPushMatrix() ;
    ofTranslate(pos) ;
    bubble.draw(0,0) ;
    ofPopMatrix() ;
}