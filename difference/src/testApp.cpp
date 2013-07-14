#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	kinect.init(true, true, false);
	kinect.open();
    for(int i = 0; i< 2;i ++){
        tex[i].allocate(WIDTH, HEIGHT, GL_LUMINANCE);
    }
    current = 0;
    shader.load("subtraction");
    ofSetVerticalSync(true);
}

//--------------------------------------------------------------
void testApp::update(){
    kinect.update();

}

//--------------------------------------------------------------
void testApp::draw(){
    
    tex[current].loadData(kinect.getDepthPixels(),WIDTH,HEIGHT, GL_LUMINANCE);
    
    tex[current].bind();
    tex[!current].bind();
    shader.begin();
    shader.setUniform1f("threshold", 0.1);
    shader.setUniformTexture("tex1", tex[current], 0);
    shader.setUniformTexture("tex2", tex[!current], 1);
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
    current = !current;
}
