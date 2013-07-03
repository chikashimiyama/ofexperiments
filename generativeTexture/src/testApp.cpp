#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    fbo.allocate(WIDTH, HEIGHT);
    ofSetVerticalSync(true);
    shader.load("multitex");
    image.loadImage("car.jpg");
}

//--------------------------------------------------------------
void testApp::update(){
    position = sin(phase++* 0.01744) * 100;
    phase %= 360;
    phase++;
}

//--------------------------------------------------------------
void testApp::draw(){
    fbo.begin();
    ofClear(0);
    light.setPosition(300,400,300);
    light.enable();
    ofEnableLighting();
    glEnable(GL_DEPTH_TEST);
    ofSphere(position+620, 400, 0, 300);
    light.disable();
    ofDisableLighting();
    fbo.end();
    
    fbo.getTextureReference().bind();
    image.bind();
    shader.begin();
    shader.setUniformTexture("fbo", fbo, fbo.getTextureReference().getTextureData().textureID);
    shader.setUniformTexture("image", image, image.getTextureReference().getTextureData().textureID);
    glBegin(GL_QUADS);
    glTexCoord2d(0, 0);
    glVertex2d(0, 0);
    glTexCoord2d(WIDTH, 0);
    glVertex2d(WIDTH , 0);
    glTexCoord2d(WIDTH, HEIGHT);
    glVertex2d(WIDTH , HEIGHT);
    glTexCoord2d(0, HEIGHT);
    glVertex2d(0, HEIGHT);
    glEnd();
    
    shader.end();
    fbo.getTextureReference().unbind();
    image.unbind();
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