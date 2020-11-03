#include "ofApp.h"
#include <math.h>

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(590);
	ofSetCircleResolution(100);
	ofEnableSmoothing();
	ofEnableAlphaBlending();
	ofBackground(255);
	ofFill();

	for (int i = 0; i < NUM_MOVER; i++) {
		movers[i].setup(1, ofRandom(10,470), ofRandom(10,470));
	}
}

//--------------------------------------------------------------
void ofApp::update() {

	ofPoint wind1(0.9, 0.9);
	ofPoint wind2(-0.9, -0.9);
	ofPoint wind3(-0.9, 0.9);
	ofPoint wind4(0.9, -0.9);


	for (int i = 0; i < NUM_MOVER; i++) {
		if (movers[i].location.x > movers[i].location.y + 240 && movers[i].location.x < movers[i].location.y + 360) {
			movers[i].applyForce(wind1);
		}
		if (movers[i].location.x < movers[i].location.y - 240 && movers[i].location.x > movers[i].location.y - 360) {
			movers[i].applyForce(wind2);
		}
		if (movers[i].location.x + movers[i].location.y > 720 && movers[i].location.x + movers[i].location.y < 840) {
			movers[i].applyForce(wind3);
		}
		if (movers[i].location.x + movers[i].location.y > 240 && movers[i].location.x + movers[i].location.y < 480) {
			movers[i].applyForce(wind4);
		}

		movers[i].update();
		movers[i].checkEdges();
	}

	float Xdistance, Ydistance, distance;
	float Xvgap, Yvgap;

	
	for (int i = 0; i < NUM_MOVER; i++) {
		for (int j = i; j < NUM_MOVER; j++) {
			Xdistance = movers[i].location.x - movers[j].location.x;
			Ydistance = movers[i].location.y - movers[j].location.y;
			distance = pow(pow(Xdistance, 2) + pow(Ydistance, 2), 0.5);
			if (distance <= (movers[i].mass + movers[j].mass)) {
				Xvgap = movers[i].velocity.x - movers[j].velocity.x;
				Yvgap = movers[i].velocity.y - movers[j].velocity.y;
				movers[i].velocity.x -= Xvgap;
				movers[j].velocity.x += Xvgap;
				movers[i].velocity.y -= Yvgap;
				movers[j].velocity.y += Yvgap;
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	for (int i = 0; i < NUM_MOVER; i++) {
		movers[i].display();
	}
	ofDrawRectRounded(240, 240, 84, 160, 84, 0.7854);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
