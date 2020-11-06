#include "ofApp.h"
#include "math.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255);
	ofSetFrameRate(60);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofTranslate(900, 400);
	float angle = ofGetElapsedTimef()*3.5;
	float y1 = 100 + 50 * cos(angle);
	float x1 = 80 + 50 * sin(angle);
	ofPoint o1 = ofVec2f(x1, y1);
	ofPoint o2 = ofVec2f(80, 100);
	ofPoint o4 = ofVec2f(140, -83);
	ofSetColor(0);
	ofDrawCircle(o1, 5);
	ofDrawCircle(o2, 8);
	ofDrawCircle(o4, 8);
	ofDrawLine(o1, o2);


	float y3 = getY1(x1, y1, 140, -80, 180, 100);
	float x3 = getX1(x1, y1, 140, -80, 180, 100);
	ofSetColor(0);
	ofPoint o3 = ofVec2f(x3, y3);
	ofDrawCircle(o3, 5);
	ofDrawLine(o1, o3);

	float x5 = 3 * 140 - 2 * x3;
	float y5 = 3 * (-83) - 2 * y3;
	ofPoint o5 = ofVec2f(x5, y5);
	ofDrawCircle(o5, 5);
	ofDrawLine(o5, o3);

	float x6 = ((x1 + x3)*0.5 + x3)*0.5;
	float y6 = ((y1 + y3)*0.5 + y3)*0.5;
	ofPoint o6 = ofVec2f(x6, y6);
	ofDrawCircle(o6, 5);

	float x7 = getX2(x6, y6, x5, y5, 305, 47);
	float y7 = getY2(x6, y6, x5, y5, 305, 47);
	ofPoint o7 = ofVec2f(x7, y7);
	ofDrawCircle(o7, 5);
	ofDrawLine(o7, o6);
	ofDrawLine(o7, o5);

	float x8 = getX1(x5, y5, x7, y7, 397, 377);
	float y8 = getY1(x5, y5, x7, y7, 397, 377);
	ofPoint o8 = ofVec2f(x8, y8);
	ofDrawCircle(o8, 5);
	ofDrawLine(o8, o5);
	ofDrawLine(o8, o7);

	ofPoint p1 = ofVec2f(-x1, y1);
	ofPoint p2 = ofVec2f(-80, 100);
	ofPoint p4 = ofVec2f(-140, -83);
	ofPoint p3 = ofVec2f(-x3, y3);
	ofPoint p5 = ofVec2f(-x5, y5);
	ofPoint p7 = ofVec2f(-x7, y7);
	ofPoint p8 = ofVec2f(-x8, y8);
	ofPoint p6 = ofVec2f(-x6, y6);
	ofDrawCircle(p1, 5);
	ofDrawCircle(p2, 8);
	ofDrawCircle(p3, 5);
	ofDrawCircle(p4, 8);
	ofDrawCircle(p5, 5);
	ofDrawCircle(p6, 5);
	ofDrawCircle(p7, 5);
	ofDrawCircle(p8, 5);
	ofDrawLine(p8, p5);
	ofDrawLine(p8, p7);
	ofDrawLine(p7, p6);
	ofDrawLine(p7, p5);
	ofDrawLine(p5, p3);
	ofDrawLine(p1, p2);
	ofDrawLine(p1, p3);
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}
float ofApp::getY1(float a, float b, float m, float n, float R1, float R2){
	float t = (R1*R1 - R2 * R2 + m * m + n * n - a * a - b * b) / (2 * (m - a));
	//cout << "t=" << t << endl;
	float t1 = t - a;
	float s = (n - b) / (m - a);
	//cout << "s=" << s << endl;
	float A = (s*s + 1);
	float B = -(2 * s*t1 + 2*b);
	float C = t1 * t1 + b * b - R1 * R1;
	float Y = (-B - pow(B*B - 4 * A*C, 0.5)) / (2 * A);
	//cout << "Y=" << Y << endl;
	return Y;
}
float ofApp::getY2(float a, float b, float m, float n, float R1, float R2) {
	float t = (R1*R1 - R2 * R2 + m * m + n * n - a * a - b * b) / (2 * (m - a));
	//cout << "t=" << t << endl;
	float t1 = t - a;
	float s = (n - b) / (m - a);
	//cout << "s=" << s << endl;
	float A = (s*s + 1);
	float B = -(2 * s*t1 + 2 * b);
	float C = t1 * t1 + b * b - R1 * R1;
	float Y = (-B + pow(B*B - 4 * A*C, 0.5)) / (2 * A);
	//cout << "Y=" << Y << endl;
	return Y;
}
float ofApp::getX1(float a, float b, float m, float n, float R1, float R2) {
	float t = (R1*R1 - R2 * R2 + m * m + n * n - a * a - b * b) / (2 * (m - a));
	float s = (n - b) / (m - a);
	float Y = getY1(a, b, m, n, R1, R2);
	float X = t - s * Y;
	//cout << "X=" << X << endl;
	return X;
}
float ofApp::getX2(float a, float b, float m, float n, float R1, float R2) {
	float t = (R1*R1 - R2 * R2 + m * m + n * n - a * a - b * b) / (2 * (m - a));
	float s = (n - b) / (m - a);
	float Y = getY2(a, b, m, n, R1, R2);
	float X = t - s * Y;
	//cout << "X=" << X << endl;
	return X;
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
void ofApp::mousePressed(int x, int y, int button){

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
