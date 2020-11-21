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
	mass = m;
	radius = 1.5 * m;
	location.set(x, y);
	velocity.set(0, 0);
	acceleration.set(0, 0);
	friction.set(1.0025);
	isdisplay = false;
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

	ofColor c;
	float v = pow(pow(velocity.x, 2) + pow(velocity.y, 2), 0.5);
	c.setHsb(ofMap(v,0,7,180,0), 200, 220);
	ofSetColor(c, 180);
	ofDrawCircle(location.x, location.y, radius );

}

void mover::checkEdges() {
	if (location.x > ofGetWidth()) {
		location.x = ofGetWidth();
		velocity.x *= -0.3;
	}
	else if (location.x < 0) {
		velocity.x *= -0.3;
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

ofPoint mover::attract(mover m) {
	ofPoint force;
	force.set(location);
	force -= m.location;
	float d = force.length();                           // Distance between objects
	d = ofClamp(d, 3.3, 15);                          // Limiting the distance to eliminate "extreme" results for very close or very far objects
	force.normalize();                                  // Normalize vector (distance doesn't matter here, we just want this vector for direction)
	float strength = ( 3*mass * m.mass) / (d * d);     // Calculate gravitional force magnitude
	force *= -strength;                                  // Get force vector --> magnitude * direction
	return force;
}

void mover::reject(mover movers[],int num) {
	float Xdistance, Ydistance, distance;
	float Xvgap, Yvgap;
	
	for (int i = 0; i < num; i++) {
		for (int j = i; j < num; j++) {
			float r1 = movers[i].radius;
			float r2 = movers[i].radius;

			Xdistance = movers[i].location.x - movers[j].location.x;
			Ydistance = movers[i].location.y - movers[j].location.y;
			//ofSetColor(20);
			//ofDrawLine(movers[i].location, movers[j].location);
			if (Xdistance > 3 * (r1 + r2) || Ydistance > 3 * (r1 + r2))
				continue;
			else {
				distance = pow(pow(Xdistance, 2) + pow(Ydistance, 2), 0.5);
				if (distance <= 4 + (r1 + r2)) {
					ofPoint force1 = movers[i].attract(movers[j]);
					ofPoint force2 = movers[j].attract(movers[i]);
					movers[i].applyForce(force2);
					movers[j].applyForce(force1);
				}

				/*
				if (distance <= 2*r) {
					Xvgap = movers[i].velocity.x - movers[j].velocity.x;
					Yvgap = movers[i].velocity.y - movers[j].velocity.y;
					movers[i].velocity.x -= Xvgap;
					movers[j].velocity.x += Xvgap;
					movers[i].velocity.y -= Yvgap;
					movers[j].velocity.y += Yvgap;
				}
				*/

			}

		}
	}
}
