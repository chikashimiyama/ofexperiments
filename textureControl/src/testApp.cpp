#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofLog(OF_LOG_VERBOSE);
    noiseImg.loadImage("noise.jpg");
    sourceImg.loadImage("car.jpg");
    shader.load("process");
    phase = 0.0;
    ofSetVerticalSync(true);
}

//--------------------------------------------------------------
void testApp::update(){
    phase++;
    
}

//--------------------------------------------------------------
void testApp::draw(){

    sourceImg.bind();
    noiseImg.bind();

    shader.begin();
    shader.setUniform1f("phase", phase);

    shader.setUniformTexture("tex1", sourceImg, sourceImg.getTextureReference().getTextureData().textureID);
    shader.setUniformTexture("tex2", noiseImg, noiseImg.getTextureReference().getTextureData().textureID);

    glBegin(GL_QUADS);
    glTexCoord2d(0, 0);
    glVertex2d(0, 0);
    glTexCoord2d(WIDTH, 0);
    glVertex2d(WIDTH, 0);
    glTexCoord2d(WIDTH, HEIGHT);
    glVertex2d(WIDTH, HEIGHT);
    glTexCoord2d(0, HEIGHT);
    glVertex2d(0, HEIGHT);
    glEnd();

    shader.end();
    sourceImg.unbind();
    noiseImg.unbind();

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