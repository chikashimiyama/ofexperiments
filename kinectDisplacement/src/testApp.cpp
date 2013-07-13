#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    // kinect init
    kinect.init(false); // enable infrared
 	kinect.open();
    shader.load("displacement");
}

//--------------------------------------------------------------
void testApp::update(){
	kinect.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    ofClear(0);
    ofTexture tex = kinect.getDepthTextureReference();
    camera.lookAt(ofVec3f(0,0,0));
    camera.setPosition(0, 0, 1000);
    camera.begin();
    tex.bind();
    shader.begin();
    shader.setUniformTexture("displacementMap", tex, tex.getTextureData().textureID);
    glBegin(GL_POINTS);
    for(int i = 0;i < 640; i++){
        for(int j = 0;j < 480;j++){
            glTexCoord2i(640-i, 480-j);
            glVertex2f(i*2-640, j*2-480);
        }
    }
    glEnd();
    shader.end();
    tex.unbind();
    camera.end();
}
