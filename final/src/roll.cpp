#include "roll.h"
#include "ofApp.h"


void Roll::setDefault() {

	ofSetColor(0);
	cylinder.setPosition(0, 0, 0);
	cylinder.set(230, 800, true);
	ofPrimitiveMode mode = OF_PRIMITIVE_TRIANGLE_STRIP;
	cylinder.setMode(mode);
	cylinder.setResolutionCap(2);
	cylinder.setResolutionHeight(4);
	cylinder.setResolutionRadius(25);

}

void Roll::draw(float speed) {

	float degree;
	ofPushMatrix();

		ofRotateZDeg(speed);
		ofRotateXDeg(90);
		ofSetColor(0, 0, 0);
		cylinder.drawWireframe();

	ofPopMatrix();

}
