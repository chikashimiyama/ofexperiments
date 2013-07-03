#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofLog(OF_LOG_VERBOSE);
    mix.load("mix");
    img1.loadImage("car.jpg");
    tex1.allocate(WIDTH, HEIGHT, GL_RGB);
    tex1.loadData(img1.getPixels(), WIDTH, HEIGHT, GL_RGB);
    img2.loadImage("horse.jpg");
    tex2.allocate(WIDTH, HEIGHT, GL_RGB);
    tex2.loadData(img2.getPixels(), WIDTH, HEIGHT, GL_RGB);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    ofClear(0, 0, 0);

//    tex1.draw(0,0);
    tex1.bind();
    tex2.bind();
    mix.begin();
    mix.setUniformTexture("tex1", tex1, tex1.getTextureData().textureID);
    mix.setUniformTexture("tex2", tex2, tex2.getTextureData().textureID);


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
//
    mix.end();
    tex1.unbind();
    tex2.unbind();
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