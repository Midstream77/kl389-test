#include "bump.h"
#include "roll.h"
#include "ofApp.h"
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

void bump::setDefault(float borntime,float Depth) {

	hight = 230;
	born = borntime;
	depth = Depth;
	target = ofVec3f(0, depth, -hight);
	sphere.setRadius(6);
	sphere.setResolution(10);
	sphere.setPosition(0, depth, -hight);
	noteLength = 0.007;

}

void bump::update() {
	time = ofGetElapsedTimef();
}

bool bump::check() {
	
	bool match;
	ofVec3f O = ofVec3f(0, 0, 0);
	ofVec3f Y = ofVec3f(0, 1, 0);
	sphere.rotateAroundDeg(speed-born,Y,O);
	//cout << "speed is " << speed << "\n";
	//sphere.draw();
	if (abs(sphere.getPosition().z - target.z) < noteLength) {
		//cout << "match" << "\n";
		match=true;
	}
	else {
		//cout << "not match" << "\n";
		match = false;
	}
	sphere.rotateAroundDeg(-speed+born, Y, O);

	//cout << match << endl;
	return match;
}

void bump::draw(float speed) {

	ofPushMatrix();
		
		ofRotateZDeg(speed-born);
		ofRotateXDeg(90);

		sphere.draw();
		//ofDrawSphere(target, 5);

	ofPopMatrix();
	//ofDrawSphere(target, 5);
}

void bump::output() {

	cout << born << ", " << depth << "\n";

}