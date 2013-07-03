#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofVec2f v[10000];
    for(int i= 0; i< 10000;i++){
        v[i].x = (float)i/ 5.0;
        v[i].y =sin((float)i*0.01744) * 100.0 + 320;
    }
    ofEnableSmoothing();
    vertices.setVertexData(v , 10000, GL_STATIC_DRAW);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    ofClear(0);
    vertices.draw(GL_LINE_STRIP, 0, 10000);
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