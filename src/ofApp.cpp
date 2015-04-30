#include "ofApp.h"
/*
 William Karges
 Background Interaction Project
 Advanced Coding
 This project draws an underwater background and animates a diver .gif and generates bubbles when the space bar is held down.  This project was mostly an expirement to find out how to animate a sprite in open frameworks.  I knew it wouldn't be much of a problem using a gif file but I wanted to see if there was a way I could get my project to read a sprite sheet.  There are a few different spriteSheet addons on the openframeworks website but they either don't work or don't do sprite animations.  I'm sure I could write code to iterate through a spritesheet myself but that seems like more trouble than its worth when the ofxGif addon works just fine.
*/


//--------------------------------------------------------------
void ofApp::setup(){
    index = 0;
    ofSetFrameRate(30) ; //lower the framerate to play the gif slower
    image.loadImage("cave.png") ;
    gifloader.load("diverSwim.gif") ; //Uses the gifaddon to load a .gif file
    bubbleImage.loadImage("bubble2.png") ;
    //Was gonna have varying sized bubbles but ended up scrapping that so the sizes array is kinda pointless
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
    //unused code
    for(int i = 0; i < 4; i++) {
        sizes.insert(sizes.begin(), i*10) ;
    }
    //Places the diver back on the left side of the screen once he reaches a certain distance
    if(theDiver.pos.x >= ofGetWidth()) {
        theDiver.pos.x = -500 ;
        theDiver.pos.y = ofRandom(50,250) ;
    }
//    if(theDiver.pos.x <= -350) {
//        theDiver.pos.x = -250 ;
//        theDiver.vel.x = 1.5 ;
//    }
    //For loop taken from the bubblesExample that erases bubbles once they reach a certain distance
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
    //Code to change the frame of the gif everysecond then reset the gif once it reaces the last frame
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
    image.draw(0,0) ; //Draw the background image
    gifloader.pages[index].draw(theDiver.pos.x, theDiver.pos.y); //draw the diver and update his position
    //Draw the bubbles
    for( int i = 0; i < bubbles.size() ; i++) {
        bubbles[i].draw() ;
    }
    //theDiver.draw() ;
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    //moves the diver right and left
    if(key == OF_KEY_RIGHT) {
        theDiver.vel.x += .25 ;
    }
    if(key == OF_KEY_LEFT) {
        theDiver.vel.x -= .25 ;
        if(theDiver.vel.x < 0) {
            
        }
    }
    //generates bubbles when the spacebar is pressed
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
