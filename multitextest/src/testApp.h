#pragma once

#include "ofMain.h"
#define WIDTH 1280
#define HEIGHT 720
class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        ofImage img1;
        ofTexture tex1;
        ofImage img2;
        ofTexture tex2;
        ofTexture tex3;
        ofShader mix;
		
};
