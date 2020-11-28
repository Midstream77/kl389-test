#include "ofApp.h"
int mode = 0;
//--------------------------------------------------------------
void ofApp::setup(){

	
	ofSetBackgroundColor(255);

	spen spen1;
	ofPoint Des;
	//Des = ofVec3f(200, 0, 0);
	ofColor pencolor = ofColor(90, 40);
	spen1.setColor(pencolor);
	spen1.setThickness(7);
	for (int i = 0; i < 6; i++) {
		
		float x = cos(i*PI / 3) * 250;
		float y = sin(i*PI / 3) * 250;
		Des = ofVec3f(x, y, 0);
		spen1.setDes(Des);
		pens.push_back(spen1);
	}

}

//--------------------------------------------------------------
void ofApp::update() {
	for (int i = 0; i < pens.size(); i++) {
		pens[i].update();
	}
	for (int i = 0; i < subPens.size(); i++) {
		subPens[i].update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	camera.begin();
	ofEnableDepthTest();

	//ofSetBackgroundAuto(false);
	for (int i = 0; i < pens.size(); i++) {
		pens[i].draw();
	}
	for (int i = 0; i < subPens.size(); i++) {
		subPens[i].draw();
	}
	/*
	ofSetColor(255, 0, 0, 255);
	if(subPens.size()!=0)
		ofDrawSphere(subPens.back().des, 10);
		*/

	ofDisableDepthTest();
	camera.end();

	string info = "press 'k'and's'and'r'to change mode";
	info += "click 'c' to crate snowflake";
	ofDrawBitmapStringHighlight(info, 20, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'w') {
		mode = 0;
	}
	if (key == 's') {
		mode = 1;
	}
	if (key == 'r') {
		mode = 2;
	}


	if (key == 'c') {

		float random = ofRandom(1.3);
		if (mode == 1) {
			random = ofRandom(-1.3);
		}
		if (mode == 0) {
			random = ofRandom(1.3);
		}
		if (mode == 2) {
			random = ofRandom(-1.8, 1.8);
		}

		for (int i = 6; i >= 1; i--) {

			ofPoint opos = pens[pens.size() - i].pos.back();
			//cout << pens.size() << endl;
			spen newpen1, newpen2;
			ofPoint Des;
			ofVec3f Gap = pens[pens.size() - i].des - opos;
			float len = (sin(ofMap(Gap.length(), 0, 250, 0, PI)) * 100)*random;

			float x1, y1, x2, y2;
			x1 = opos.x + cos((i + 1)*PI / 3) * len;
			x2 = opos.x + cos((i - 1)*PI / 3) * len;
			y1 = opos.y + sin((i + 1)*PI / 3) * len;
			y2 = opos.y + sin((i - 1)*PI / 3) * len;

			if (i == 1 || i == 4) {
				x1 = opos.x + cos((i - 1)*PI / 3) * len;
				y1 = opos.y + sin((i - 1)*PI / 3) * len;
				x2 = opos.x + cos((i - 3)*PI / 3) * len;
				y2 = opos.y + sin((i - 3)*PI / 3) * len;
			}

			if (i == 6 || i == 3) {
				x2 = opos.x + cos((i - 1)*PI / 3) * len;
				y2 = opos.y + sin((i - 1)*PI / 3) * len;
			}

			if (i == 2 || i == 5) {
				x2 = opos.x + cos((i - 3)*PI / 3) * len;
				y2 = opos.y + sin((i - 3)*PI / 3) * len;
			}
			ofColor pencolor = ofColor(90, 40);
			newpen1.setColor(pencolor);
			newpen1.setThickness(6);
			newpen2.setColor(pencolor);
			newpen2.setThickness(6);
			ofPoint Des1 = ofVec3f(x1, y1, 0);
			ofPoint Des2 = ofVec3f(x2, y2, 0);
			newpen1.setPos(opos);
			newpen2.setPos(opos);
			newpen1.setDes(Des1);
			newpen2.setDes(Des2);

			subPens.push_back(newpen1);
			subPens.push_back(newpen2);

			//ofSetBackgroundAuto(false);
			//ofSetColor(255, 0, 0, 255);
			//ofDrawSphere(opos, 10);
			cout << Des1 << endl;
			cout << Des2 << endl;
		}
		//cout << subPens.back().gap.length() << endl;
	}

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

	

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
