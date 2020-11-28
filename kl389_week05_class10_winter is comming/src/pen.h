//#include"ofApp.h"
#pragma once
#include<vector>

class spen {

public:
	
	spen();
	ofPoint des;
	float radius;
	ofColor color;
	ofVec3f dir, gap;
	vector<ofPoint> pos;

	void setThickness(float radius);
	void setColor(ofColor c);
	void setDes(ofPoint Des);
	void setPos(ofPoint Pos);
	void update();
	void draw();
	
};