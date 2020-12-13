#pragma once
#include "ofMain.h"

class input {

public:

	float time;
	float pressTime;
	float lift;
	float depth;
	bool ispress;
	float r1;
	ofPoint fp1;
	ofPoint fp2;
	ofPoint fp3;
	ofPoint mp1;
	ofPoint mp2;
	ofPoint mp3;
	ofPoint mp4;

	void setDefault(float Depth);
	void press();
	void update();
	void draw();
};