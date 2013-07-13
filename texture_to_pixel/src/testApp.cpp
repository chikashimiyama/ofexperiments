#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    car.loadImage("car.jpg");
    shader.load("displacement");
    cam.setPosition(0, 5, 200);
    cam.lookAt(ofVec3f(0,0,0));
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(0);
    ofColor(255);

    cam.begin();
    cam.setPosition(0, 40, 900);
    
    car.bind();
    shader.begin();
    shader.setUniformTexture("displacementMap",car, car.getTextureReference().getTextureData().textureID);
    
//    glBegin(GL_QUADS);
//    glTexCoord2d(0, 0);
//    glVertex2d(0, 0);
//    glTexCoord2d(WIDTH, 0);
//    glVertex2d(WIDTH , 0);
//    glTexCoord2d(WIDTH, HEIGHT);
//    glVertex2d(WIDTH , HEIGHT);
//    glTexCoord2d(0, HEIGHT);
//    glVertex2d(0, HEIGHT);
//    glEnd();
    glBegin(GL_POINTS);
    for(int i = 0;i < 1280; i++){
        for(int j = 0;j < 720;j++){
            glTexCoord2i(i, j);
            glVertex2f(i-640, j-360);
        }
    }
    glEnd();

    shader.end();
    car.unbind();
    cam.end();
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