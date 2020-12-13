#pragma once
#include "ofMain.h"
#include <vector>

class bump {
	
public:

	float time;
	float sound;
	float depth;
	float hight;
	float speed;
	float born;
	float noteLength;
	ofPoint target;
	ofSpherePrimitive sphere;
	vector<bump> bumps;

	void setDefault(float speed,float Depth);
	bool check();
	void update();
	void draw(float speed);
	void output();
};