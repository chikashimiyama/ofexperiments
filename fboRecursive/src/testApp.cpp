#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    fbo.allocate(ofGetWidth(), ofGetHeight());
    processFbo.allocate(ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void testApp::update(){
    
}

//--------------------------------------------------------------
void testApp::draw(){
    int x,y;
    x = ofGetMouseX();
    y = ofGetMouseY();
    fbo.begin();
    ofBackground(0);
    processFbo.draw(0, 0);
    ofSetColor(255);
    ofSphere(x, y, 0, 100);
    fbo.end();

    processFbo.begin();
    ofBackground(0);
    ofSetColor(250);
    fbo.getTextureReference().bind();
    glBegin(GL_QUADS);
        glTexCoord2f(10,0), glVertex2d(0, 0);
        glTexCoord2f(ofGetWidth(),0), glVertex2d(ofGetWidth(), 0);
        glTexCoord2f(ofGetWidth(),ofGetHeight()), glVertex2d(ofGetWidth(), ofGetHeight());
        glTexCoord2f(10,ofGetHeight()), glVertex2d(0, ofGetHeight());
    glEnd();
    fbo.getTextureReference().unbind();
    processFbo.end();

    fbo.draw(0,0); // render to the window
}

