#pragma once

#include "ofMain.h"
#include "ofxKinect.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        ofxKinect kinect;
        ofShader shader;
        ofCamera camera;
};
