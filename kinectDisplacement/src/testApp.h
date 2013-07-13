#pragma once

#include "ofMain.h"
#include "ofxKinect.h"
#define PIXELS 640 * 480
class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        ofxKinect kinect;
        ofShader shader;
        ofCamera camera;
        ofVbo vbo;
};
