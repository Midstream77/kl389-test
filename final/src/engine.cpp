#include "ofApp.h"
#include "engine.h"
#include <algorithm>;


void engine::setDefault() {

	ofVec3f X = ofVec3f(1, 0, 0);
	ofVec3f Y = ofVec3f(0, 1, 0);
	ofVec3f Z = ofVec3f(0, 0, 1);

	o = ofVec3f(276, 0, 380);
	fp1 = ofVec3f(400, -150, 380);
	fp2 = ofVec3f(400, -100, 480);
	fp3 = ofVec3f(700, 0, 380);
	fp4 = ofVec3f(640, 0, 480);

	c1.setHeight(150);
	c1.setRadius(56);
	c1.setCapped(true);
	c1.setResolutionCap(1);
	c1.setResolutionRadius(12);
	c1.setResolutionHeight(2);
	c1.rotateDeg(90, Z);

	c2.setHeight(240);
	c2.setRadius(60);
	c2.setCapped(false);
	c2.setResolutionCap(1);
	c2.setResolutionRadius(13);
	c2.setResolutionHeight(2);
	c2.rotateDeg(90, Z);
	c2.setPosition(fp3);

	c3.setHeight(70);
	c3.setRadius(36);
	c3.setCapped(true);
	c3.setResolutionCap(1);
	c3.setResolutionRadius(9);
	c3.setResolutionHeight(2);
	c3.rotateDeg(90, Z);

	c4.setHeight(140);
	c4.setRadius(40);
	c4.setCapped(false);
	c4.setResolutionCap(1);
	c4.setResolutionRadius(9);
	c4.setResolutionHeight(2);
	c4.rotateDeg(90, Z);
	c4.setPosition(fp4);

	mp0.z = 480;
	mp1.z = 380;
	mp2.z = 380;
	mp3.z = 380;
	mp4.z = 480;
	mp5.z = 480;
	mp6.z = 480;
	mp7.z = 380;
	mp8.z = 480;
	mp3.y = o.y;
	mp6.y = o.y;
	mp7.y = 0;
	mp8.y = 0;
}

void engine::update(float Speed) {

	speed = 5*Speed/360*2*PI;
	mp1.x = o.x + sin(speed) * 46;
	mp1.y = o.y + cos(speed) * 46;
	mp0.x = mp1.x;
	mp0.y = mp1.y;
	mp2.x = o.x - sin(speed) * 46;
	mp2.y = o.y - cos(speed) * 46;
	//cout << time << "\n";
	mp3.x = ofApp().getX(mp1, mp3.y, 250);
	mp4 = ofApp().getPoint2(mp1, fp1, 160, 130, mp4.z);
	mp5 = ofApp().getPoint1(mp4, fp1, 210, 130, mp5.z);
	mp6.x = ofApp().getX(mp5, mp6.y, 100);
	mp7.x = mp3.x + 175;
	mp8.x = mp6.x + 120;

	c1.setPosition(mp7);
	c3.setPosition(mp8);

}

void engine::draw() {

	ofDrawSphere(o,3);
	ofDrawSphere(fp2, 3);
	ofDrawSphere(mp0, 3);
	ofDrawSphere(mp1, 3);
	ofDrawSphere(mp2, 3);
	ofDrawSphere(mp3, 3);
	ofDrawSphere(mp4, 3);
	ofDrawSphere(mp5, 3);
	ofDrawSphere(mp6, 3);
	ofDrawSphere(mp7, 2);
	ofDrawSphere(mp8, 2);

	ofNoFill();
	ofDrawCircle(o, 46);

	ofDrawLine(mp1, mp0);
	ofDrawLine(mp1, mp3);
	ofDrawLine(mp0, mp4);
	ofDrawLine(fp2, mp4);
	ofDrawLine(fp2, mp5);
	ofDrawLine(mp6, mp5);
	ofDrawLine(mp4, mp5);
	ofDrawLine(mp3, mp7);
	ofDrawLine(mp6, mp8);

	ofSetColor(100);
	c1.draw();
	c3.draw();
	ofSetColor(0);
	c1.drawWireframe();
	c2.drawWireframe();
	c3.drawWireframe();
	c4.drawWireframe();

}