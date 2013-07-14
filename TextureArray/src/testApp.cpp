#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    kinect.init(false); // enable infrared
    ofSetVerticalSync(true);
    kinect.setUseTexture(false);
 	kinect.open();
    current = 0;
    for(int i = 0; i < MEM_SIZE; i++){
        kinectFrames[i].allocate(640, 480, GL_LUMINANCE);
    }
    
}

//--------------------------------------------------------------
void testApp::update(){
	kinect.update();

}

//--------------------------------------------------------------
void testApp::draw(){
    int x;
    kinectFrames[current].loadData( kinect.getDepthPixels(), 640, 480, GL_LUMINANCE);
    current++;
    if(current >= MEM_SIZE){
        current = 0;
    }
    //reverse
    kinectFrames[MEM_SIZE-1-current].draw(0,0);

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