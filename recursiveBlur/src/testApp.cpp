#include "testApp.h"
#define WIDTH 1024
#define HEIGHT 768
//--------------------------------------------------------------
void testApp::setup(){
    tex.allocate(WIDTH, HEIGHT, GL_RGB);
    ofEnableAlphaBlending();
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
}

//--------------------------------------------------------------
void testApp::update(){
    x = ofGetMouseX();
    y = ofGetMouseY();
}

//--------------------------------------------------------------
void testApp::draw(){
    ofClear(0);
    glColor4f(1, 1, 1, 0.98);
    int squeeze = 5;
    tex.bind();
    glBegin(GL_QUADS);
    glTexCoord2d(0+squeeze, HEIGHT);
    glVertex2d(0, 0);
    
    glTexCoord2d(WIDTH-squeeze, HEIGHT);
    glVertex2d(WIDTH , 0);
    
    glTexCoord2d(WIDTH-squeeze, 0);
    glVertex2d(WIDTH , HEIGHT);
    
    glTexCoord2d(0+squeeze, 0);
    glVertex2d(0, HEIGHT);
    glEnd();
    tex.unbind();
    
    tex.loadScreenData(0, 0, 1024, 768);
  
    ofSphere(x, y, 0, 50);
    tex.loadScreenData(0, 0, 1024, 768);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}