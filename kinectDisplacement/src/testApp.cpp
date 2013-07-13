#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    // kinect init
    kinect.init(false); // enable infrared
 	kinect.open();
    shader.load("displacement");
    ofVec3f vertices[PIXELS];
    ofVec2f texCoords[PIXELS];

    for(int i = 0;i < 480; i++){
        for(int j = 0;j < 640;j++){
            int index = 640*i + j;
            texCoords[index].x = (float)640-j;
            texCoords[index].y = (float)480-i;
            vertices[index].x = (float)j-320;
            vertices[index].y = (float)i-240;
            vertices[index].z = 0.0f;

        }
    }
    vbo.setTexCoordData(&texCoords[0], PIXELS , GL_STATIC_DRAW );
    vbo.setVertexData( &vertices[0], PIXELS , GL_STATIC_DRAW );
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
    camera.setPosition(0, 100, 500);
    camera.begin();
    tex.bind();
    shader.begin();
    shader.setUniformTexture("displacementMap", tex, tex.getTextureData().textureID);
    vbo.draw(GL_POINTS, 0, PIXELS);
    shader.end();
    tex.unbind();
    camera.end();
}
