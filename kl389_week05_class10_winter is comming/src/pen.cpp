#include"ofApp.h"
#include"pen.h"

using namespace std;

spen::spen() {
	ofPoint ori = ofVec3f(0, 0, 0);
	pos.push_back(ori);
	color;
	radius;
	des = ofVec3f(0, 0, 0);
	gap = des - pos.back();
	float t = gap.length();
	dir = gap / t;
	//check = ofVec3f(0, 0, 0);
}

void spen::setThickness(float thickness) {
	radius = thickness;
}

void spen::setColor(ofColor c) {
	color = c;
}

void spen::setDes(ofPoint Des) {
	des = Des;
	gap = des - pos.back();
	float t = gap.length();
	dir = gap / t;
}

void spen::setPos(ofPoint Pos) {
	pos.push_back(Pos);
}

void spen::update() {
	gap = des - pos.back();
	float x = gap.length();
	//cout << x << endl;
	if (x > 3) {
		ofPoint newpos = pos.back() + dir * 0.4;
		pos.push_back(newpos);
	}
}

void spen::draw() {
	
	ofSetColor(color);
	for(int i=0;i<pos.size();i++)
		ofDrawSphere(pos[i], radius);

}