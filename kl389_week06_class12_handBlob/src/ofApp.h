#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxOpenCv.h"

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
	
	
	//ofVideoPlayer video;
	
	ofxCvColorImage colorImg;
	ofxCvGrayscaleImage threshImg;
	
	ofxCvContourFinder blobFinder;
	
	vector<ofPath> blobs;
	
	
	ofxPanel gui;
	ofxFloatSlider threshold;
	ofxFloatSlider minArea;
	ofxFloatSlider maxArea;
	ofxIntSlider maxBlobs;
	ofxToggle bFindHoles;
	
	//ofVideoGrabber vidGrabber;
	ofVideoGrabber video;
	int camWidth;
	int camHeight;
};