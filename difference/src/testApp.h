#pragma once

#include "ofMain.h"
#include "ofxKinect.h"
#define WIDTH 640
#define HEIGHT 480

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

        ofxKinect kinect;
        ofTexture tex[2];
        ofShader shader;
        int current;
};
