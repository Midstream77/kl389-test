#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		float getY1(float a, float b, float m, float n, float R1, float R2);
		float getY2(float a, float b, float m, float n, float R1, float R2);
		float getX1(float a, float b, float m, float n, float R1, float R2);
		float getX2(float a, float b, float m, float n, float R1, float R2);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		
};
