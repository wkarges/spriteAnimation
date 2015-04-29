#include "ofApp.h"
/*
 William Karges 872538649
 Background Interaction Project
 Advanced Coding
*/


//--------------------------------------------------------------
void ofApp::setup(){
    index = 0;
    ofSetFrameRate(30) ;
    image.loadImage("cave.png") ;
    gifloader.load("diverSwim.gif") ;
    bubbleImage.loadImage("bubble2.png") ;
    sizes.push_back(10) ;
    sizes.push_back(20) ;
    sizes.push_back(30) ;
    sizes.push_back(40) ;
    sizes.push_back(50) ;
    bubbleImage.resize(sizes[2], sizes[2]) ;
}

//--------------------------------------------------------------
void ofApp::update(){
    theDiver.update() ;
    for(int i = 0; i < 4; i++) {
        sizes.insert(sizes.begin(), i*10) ;
    }
    if(theDiver.pos.x >= ofGetWidth()) {
        theDiver.pos.x = -500 ;
        theDiver.pos.y = ofRandom(50,250) ;
    }
//    if(theDiver.pos.x <= -350) {
//        theDiver.pos.x = -250 ;
//        theDiver.vel.x = 1.5 ;
//    }
    for( int i = 0; i < bubbles.size() ; i++) {
        bubbles[i].bubble = bubbleImage ;
        //bubbles[i].bubble.resize(sizes[2], sizes[2]) ;
        bubbles[i].update() ;
        float distance = ofDist(bubbles[i].birth.x, bubbles[i].birth.y , bubbles[i].pos.x, bubbles[i].pos.y) ;
        if(distance > 300) {
            bubbles.erase(bubbles.begin() + i) ;
            i-- ;
        }
    }
    if (ofGetElapsedTimef()) {
        index++;
        if (index > gifloader.pages.size()-1) {
            index = 0;
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255, 255, 255) ;
    image.draw(0,0) ;
    gifloader.pages[index].draw(theDiver.pos.x, theDiver.pos.y);
    for( int i = 0; i < bubbles.size() ; i++) {
        bubbles[i].draw() ;
    }
    //theDiver.draw() ;
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == OF_KEY_RIGHT) {
        theDiver.vel.x += .25 ;
    }
    if(key == OF_KEY_LEFT) {
        theDiver.vel.x -= .25 ;
        if(theDiver.vel.x < 0) {
            
        }
    }
    if(key == ' ') {
        Bubble tempBubble ;
        tempBubble.setup(theDiver.pos.x+600, theDiver.pos.y+250) ;
        bubbles.push_back(tempBubble) ;
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
