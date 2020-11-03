//
//  mover.cpp
//  NOC_1_7_motion101
//
//  Created by Firm Read on 2/22/13.
//
//

#include "mover.h"
#include "ofApp.h"

void mover::setup(float m, float x, float y) {
	mass = 16*m;
	location.set(x, y);
	velocity.set(0, 0);
	acceleration.set(0, 0);
	friction.set(1.002);
}

void mover::applyForce(ofPoint force) {
	ofPoint a;
	a = force / mass;
	acceleration += a;
}

void mover::update() {
	velocity += acceleration;
	location += velocity;
	acceleration *= 0;
	velocity /= friction;
}

//emulate friction


void mover::display() {

	ofSetColor(0, 100);
	ofDrawCircle(location.x, location.y, mass );

}

void mover::checkEdges() {
	if (location.x > ofGetWidth()) {
		location.x = ofGetWidth();
		velocity.x *= -1;
	}
	else if (location.x < 0) {
		velocity.x *= -1;
		location.x = 0;
	}

	if (location.y > ofGetHeight()) {
		velocity.y *= -1;
		location.y = ofGetHeight();
	}
	else if (location.y < 0) {
		velocity.y *= -1;
		location.y = 0;
	}
}
