#include "input.h"
#include "ofApp.h"


void input::setDefault(float Depth) {

	pressTime = -1;
	depth = Depth;
	ispress = false;
	lift = 0;

	r1 = 40;
	fp1 = ofVec3f(-400, 0, depth);
	fp2 = ofVec3f(-30, 260, depth);
	mp1 = ofVec3f(r1*cos(time) + fp1.x, r1*sin(time) + fp1.y, depth);
	mp2 = ofVec3f(r1*cos(time) + fp2.x, r1*sin(time) + fp2.y, depth);
	//mp2 = ofApp().getPoint1(mp1, fp2, 450, 60, depth);
	mp3 = ofApp().getPoint1(mp1, mp2, 600, 150, depth);
	mp4 = ofApp().getPoint1(mp2, fp2, 80, 20, depth);
}

void input::press() {

	pressTime = time;
	ispress = true;

}

void input::update() {

	time = ofGetElapsedTimef();
	lift = 0;
	
	

	if (ispress && (time - pressTime < 0.1)) {
		lift = ofMap((time - pressTime),0,0.1,0,PI);
		lift = 0.8*sin(lift);
		ispress = true;
	}
	else
		ispress = false;

	mp1 = ofVec3f(-r1 * cos(lift + 0.1) + fp1.x, r1*sin(lift + 0.1) + fp1.y, depth);
	mp2 = ofVec3f(-r1 * cos(lift + 0.1) + fp2.x, r1*sin(lift + 0.1) + fp2.y, depth);
	//mp2 = ofApp().getPoint1(mp1, fp2, 450, 60, depth);
	mp3 = ofApp().getPoint1(mp1, mp2, 600, 148, depth);
	mp4 = ofApp().getPoint1(mp2, fp2, 80, 41, depth);

	//std::cout << lift << "\n";
}

void input::draw() {

	ofDrawSphere(fp1, 4);
	ofDrawSphere(fp2, 4);
	ofDrawSphere(mp1, 3);
	ofDrawSphere(mp2, 3);
	ofDrawSphere(mp3, 7);
	ofDrawSphere(mp4, 3);

	ofDrawLine(fp1, mp1);
	ofDrawLine(mp2, mp1);
	//ofDrawLine(mp3, mp1);
	ofDrawLine(fp2, mp4);
	ofDrawLine(fp2, mp2);
	ofDrawLine(mp2, mp3);

}