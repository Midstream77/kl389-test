#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
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

		ofMesh mesh;
		ofEasyCam cam;
		ofPlanePrimitive plane;
		ofVboMesh deformPlane;
		ofConePrimitive cone;
		ofBoxPrimitive box1;
		ofBoxPrimitive box2;
		ofBoxPrimitive box3;
		ofBoxPrimitive box4;
		ofBoxPrimitive box5;
		ofCylinderPrimitive cylinder;
		ofVboMesh boxSides[ofBoxPrimitive::SIDES_TOTAL];
		
};
