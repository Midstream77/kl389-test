#pragma once
#include "ofMain.h"

class output {

public:

	float time;
	float slideTime;
	float depth;
	float slide;
	bool match;

	ofPoint fp;
	ofPoint mp1;
	ofPoint mp2;
	ofPoint mp3;
	ofPoint mp4;
	ofPoint st1;
	ofPoint st2;

	void setDefault(float Depth);
	void update();
	void draw();

};