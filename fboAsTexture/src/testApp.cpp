#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    fbo.allocate(WIDTH, HEIGHT);
    
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    fbo.begin();
    ofClear(0);
    ofLight light;
    light.setPosition(500, 100, 500);
    light.enable();
    glEnable(GL_DEPTH_TEST);
    ofEnableLighting();
    ofSphere(WIDTH/2, HEIGHT/2, 0, 50);
    ofDisableLighting();
    light.disable();
    glDisable(GL_DEPTH_TEST);
    fbo.end();
    
    ofTexture tex;
    fbo.getTextureReference().bind();
    glBegin(GL_QUADS);
    glTexCoord2d(0, 0);
    glVertex2d(0, 0);
    glTexCoord2d(WIDTH , 0);
    glVertex2d(WIDTH, 0);
    glTexCoord2d(WIDTH, HEIGHT);
    glVertex2d(WIDTH, HEIGHT);
    glTexCoord2d(0, HEIGHT);
    glVertex2d(0, HEIGHT);
    glEnd();
    fbo.getTextureReference().unbind();
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