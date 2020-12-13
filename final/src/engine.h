#pragma once
#include "ofMain.h"

class engine {

public:

	ofPoint o;
	ofPoint mp1, mp0, mp2, mp3, mp4, mp5, mp6, mp7, mp8, mp9, mp10;
	ofPoint fp1, fp2, fp3, fp4;
	ofCylinderPrimitive c1, c2, c3, c4;
	float speed;

	void setDefault();
	void update(float Speed);
	void draw();

};