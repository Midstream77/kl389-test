#include "output.h"
#include "ofApp.h"

void output::setDefault(float Depth) {

	match = false;
	time = ofGetElapsedTimef();
	depth = Depth;
	fp = ofVec3f(350, 250, depth+10);
	mp1 = ofVec3f(slide, 235, depth);
	mp4 = ofVec3f(slide + 20, 240, depth + 10);
	mp2 = ofApp().getPoint1(fp, mp4, 25, 345, depth + 10);
	mp3 = ofApp().getPoint1(mp2, fp, 170, 146, depth + 10);
	st1 = ofVec3f(-600, 380, depth);
	st2 = ofVec3f(600, 370, depth);
}

void output::update() {

	time = ofGetElapsedTimef();
	if (match) {
		slideTime = time;
		match = false;
	}
	if (time - slideTime < 0.2) {
		slide = ofMap((time - slideTime), 0, 0.2, 0, PI);
		slide = -15 * sin(slide);
	}
	else
		slide = 0;
	mp1 = ofVec3f(slide, 235, depth);
	mp4 = ofVec3f(slide + 20, 240, depth + 10);
	mp2 = ofApp().getPoint1(fp, mp4, 25, 350, depth + 10);
	mp3 = ofApp().getPoint1(mp2, fp, 150, 126, depth + 10);
}

void output::draw() {
	
	ofDrawSphere(fp, 4);
	ofDrawSphere(mp1, 3);
	ofDrawSphere(mp4, 3);
	ofDrawSphere(mp2, 3);
	ofDrawSphere(mp3, 5);

	ofDrawSphere(st1, 3);
	ofDrawSphere(st2, 3);
	ofDrawLine(st1, st2);

	ofDrawLine(mp1, mp4);
	ofDrawLine(mp4, mp2);
	ofDrawLine(mp2, fp);
	ofDrawLine(mp3, fp);

}