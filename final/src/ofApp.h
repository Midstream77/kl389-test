#pragma once

#include "ofMain.h"
#include "roll.h"
#include "bump.h"
#include "input.h"
#include "output.h"
#include "engine.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);

		float getX(ofPoint X, float y, float r);
		ofPoint getRealPoint1(ofPoint x, ofPoint y, float R1, float R2, float z);
		ofPoint getRealPoint2(ofPoint x, ofPoint y, float R1, float R2, float z);
		ofPoint getPoint1(ofPoint x, ofPoint y, float R1, float R2, float z);
		ofPoint getPoint2(ofPoint x, ofPoint y, float R1, float R2, float z);


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
		
		float speedKey;
		float speed;
		float time;
		int show;
		ofEasyCam cam;
		vector<bump> bumps;
		Roll roll;

		
		ofSoundPlayer F1p;
		ofSoundPlayer G1;
		ofSoundPlayer G1p;
		ofSoundPlayer A1;
		ofSoundPlayer A1p;
		ofSoundPlayer B1;
		ofSoundPlayer C2;
		ofSoundPlayer C2p;
		ofSoundPlayer D2;
		ofSoundPlayer D2p;
		ofSoundPlayer E2;
		ofSoundPlayer F2;
		ofSoundPlayer F2p;
		ofSoundPlayer G2;
		ofSoundPlayer G2p;
		ofSoundPlayer A2;
		ofSoundPlayer A2p;
		ofSoundPlayer B2;
		ofSoundPlayer C3;
		ofSoundPlayer C3p;
		ofSoundPlayer D3;
		ofSoundPlayer D3p;
		ofSoundPlayer E3;
		ofSoundPlayer F3;
		ofSoundPlayer F3p;
		ofSoundPlayer G3;
		ofSoundPlayer G3p;
		ofSoundPlayer A3;
		ofSoundPlayer A3p;
		ofSoundPlayer B3;
		ofSoundPlayer C4;
		ofSoundPlayer C4p;
		ofSoundPlayer D4;
		ofSoundPlayer D4p;
		ofSoundPlayer E4;
		ofSoundPlayer F4;

		ofSoundPlayer arr[37] = { F1p,G1,G1p,A1,A1p,B1,C2,C2p,D2,D2p,E2,F2,F2p,G2,G2p,A2,A2p,B2,
			C3,C3p,D3,D3p,E3,F3,F3p,G3,G3p,A3,A3p,B3,C4,C4p,D4,D4p,E4,F4 };
		int arr2[37] = { 1300,1300,1200,1200,1200,1200,1100,1100,1100,1000,1000,1000,800,800,800,800,
			800,800,800,800,800,800,700,700,500,500,500,500,300,300,300,300,300,300,300,300 };
		input inputs[37];
		output outputs[37];
		engine Engine;
};
