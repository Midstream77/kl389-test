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

	//ofTranslate(900, 400);
	//ofRotateZ(180);
	//ofRotateX(180);
	//ofRotateY(180);

	camera.begin();
	ofEnableDepthTest();

	
	float angle = ofGetElapsedTimef()*3.5;
	float y1 = 100 + 50 * cos(angle);
	float x1 = 80 + 50 * sin(angle);
	ofPoint o1 = ofVec3f(x1, y1,100);
	ofPoint o1_1 = ofVec3f(x1, y1, 200);
	ofPoint o2 = ofVec3f(80, 100, 200);
	ofPoint o4 = ofVec3f(140, -83,100);
	o1.y *= -1;
	o1_1.y *= -1;
	o2.y *= -1;
	o4.y *= -1;
	ofSetColor(0);
	ofDrawSphere(o1, 5);
	ofDrawSphere(o1_1, 5);
	ofDrawSphere(o2, 8);
	ofDrawSphere(o4, 8);
	ofDrawLine(o1, o1_1);
	ofDrawLine(o2, o1_1);
	

	float y3 = getY1(x1, y1, 140, -80, 180, 100);
	float x3 = getX1(x1, y1, 140, -80, 180, 100);
	ofSetColor(0);
	ofPoint o3 = ofVec3f(x3, y3,100);
	o3.y *= -1;
	ofDrawSphere(o3, 5);
	ofDrawLine(o1, o3);

	float x5 = 3 * 140 - 2 * x3;
	float y5 = 3 * (-83) - 2 * y3;
	ofPoint o5 = ofVec3f(x5, y5,100);
	o5.y *= -1;
	ofDrawSphere(o5, 5);
	ofDrawLine(o5, o3);

	float x6 = ((x1 + x3)*0.5 + x3)*0.5;
	float y6 = ((y1 + y3)*0.5 + y3)*0.5;
	ofPoint o6 = ofVec3f(x6, y6,100);
	o6.y *= -1;
	ofDrawSphere(o6, 5);

	float x7 = getX2(x6, y6, x5, y5, 305, 47);
	float y7 = getY2(x6, y6, x5, y5, 305, 47);
	ofPoint o7 = ofVec3f(x7, y7,100);
	o7.y *= -1;
	ofDrawSphere(o7, 5);
	ofDrawLine(o7, o6);
	ofDrawLine(o7, o5);

	float x8 = getX1(x5, y5, x7, y7, 397, 377);
	float y8 = getY1(x5, y5, x7, y7, 397, 377);
	ofPoint o8 = ofVec3f(x8, y8,100);
	o8.y *= -1;
	ofDrawSphere(o8, 5);
	ofDrawLine(o8, o5);
	ofDrawLine(o8, o7);

	ofPoint p1 = ofVec3f(-x1, -y1,100);
	ofPoint p1_1 = ofVec3f(-x1, -y1, 200);
	ofPoint p2 = ofVec3f(-80, -100, 200);
	ofPoint p4 = ofVec3f(-140, 83,100);
	ofPoint p3 = ofVec3f(-x3, -y3,100);
	ofPoint p5 = ofVec3f(-x5, -y5,100);
	ofPoint p7 = ofVec3f(-x7, -y7,100);
	ofPoint p8 = ofVec3f(-x8, -y8,100);
	ofPoint p6 = ofVec3f(-x6, -y6,100);

	ofPoint o1b = ofVec3f(x1, -y1, -100);
	ofPoint o1_1b = ofVec3f(x1, -y1, -150);
	ofPoint o2b = ofVec3f(80, -100, -150);
	ofPoint o4b = ofVec3f(140, 83, -100);
	ofPoint o3b = ofVec3f(x3, -y3, -100);
	ofPoint o5b = ofVec3f(x5, -y5, -100);
	ofPoint o5m1 = ofVec3f(x5, -y5, 50);
	ofPoint o5m2 = ofVec3f(x5, -y5, 0);
	ofPoint o5m3 = ofVec3f(x5, -y5, -50);
	ofPoint o7b = ofVec3f(x7, -y7, -100);
	ofPoint o7m1 = ofVec3f(x7, -y7, 50);
	ofPoint o7m2 = ofVec3f(x7, -y7, 0);
	ofPoint o7m3 = ofVec3f(x7, -y7, -50);
	ofPoint o8b = ofVec3f(x8, -y8, -100);
	ofPoint o8m1 = ofVec3f(x8, -y8, 50);
	ofPoint o8m2 = ofVec3f(x8, -y8, 0);
	ofPoint o8m3 = ofVec3f(x8, -y8, -50);
	ofPoint o6b = ofVec3f(x6, -y6, -100);

	ofPoint p1b = ofVec3f(-x1, -y1, -100);
	ofPoint p1_1b = ofVec3f(-x1, -y1, -150);
	ofPoint p2b = ofVec3f(-80, -100, -150);
	ofPoint p4b = ofVec3f(-140, 83, -100);
	ofPoint p3b = ofVec3f(-x3, -y3, -100);
	ofPoint p5b = ofVec3f(-x5, -y5, -100);
	ofPoint p5m1 = ofVec3f(-x5, -y5, 50);
	ofPoint p5m2 = ofVec3f(-x5, -y5, 0);
	ofPoint p5m3 = ofVec3f(-x5, -y5, -50);
	ofPoint p7b = ofVec3f(-x7, -y7, -100);
	ofPoint p7m1 = ofVec3f(-x7, -y7, 50);
	ofPoint p7m2 = ofVec3f(-x7, -y7, 0);
	ofPoint p7m3 = ofVec3f(-x7, -y7, -50);
	ofPoint p8b = ofVec3f(-x8, -y8, -100);
	ofPoint p8m1 = ofVec3f(-x8, -y8, 50);
	ofPoint p8m2 = ofVec3f(-x8, -y8, 0);
	ofPoint p8m3 = ofVec3f(-x8, -y8, -50);
	ofPoint p6b = ofVec3f(-x6, -y6, -100);

	
	ofDrawSphere(p1, 5);
	ofDrawSphere(p1_1, 5);
	ofDrawSphere(p2, 8);
	ofDrawSphere(p3, 5);
	ofDrawSphere(p4, 8);
	ofDrawSphere(p5, 5);
	ofDrawSphere(p6, 5);
	ofDrawSphere(p7, 5);
	ofDrawSphere(p8, 5);

	ofDrawSphere(p1b, 5);
	ofDrawSphere(p1_1b, 5);
	ofDrawSphere(p2b, 8);
	ofDrawSphere(p3b, 5);
	ofDrawSphere(p4b, 8);
	ofDrawSphere(p5b, 5);
	ofDrawSphere(p5m1, 5);
	ofDrawSphere(p5m2, 5);
	ofDrawSphere(p5m3, 5);
	ofDrawSphere(p6b, 5);
	ofDrawSphere(p7b, 5);
	ofDrawSphere(p7m1, 5);
	ofDrawSphere(p7m2, 5);
	ofDrawSphere(p7m3, 5);
	ofDrawSphere(p8b, 5);
	ofDrawSphere(p8m1, 5);
	ofDrawSphere(p8m2, 5);
	ofDrawSphere(p8m3, 5);

	ofDrawSphere(o1b, 5);
	ofDrawSphere(o1_1b, 5);
	ofDrawSphere(o2b, 8);
	ofDrawSphere(o3b, 5);
	ofDrawSphere(o4b, 8);
	ofDrawSphere(o5b, 5);
	ofDrawSphere(o5m1, 5);
	ofDrawSphere(o5m2, 5);
	ofDrawSphere(o5m3, 5);
	ofDrawSphere(o6b, 5);
	ofDrawSphere(o7b, 5);
	ofDrawSphere(o7m1, 5);
	ofDrawSphere(o7m2, 5);
	ofDrawSphere(o7m3, 5);
	ofDrawSphere(o8b, 5);
	ofDrawSphere(o8m1, 5);
	ofDrawSphere(o8m2, 5);
	ofDrawSphere(o8m3, 5);

	ofDrawLine(p8, p5);
	ofDrawLine(p8, p7);
	ofDrawLine(p7, p5);
	ofDrawLine(p7, p6);
	ofDrawLine(p5, p3);
	ofDrawLine(p1_1, p2);
	ofDrawLine(p1, p1_1);
	ofDrawLine(p1, p3);

	ofDrawLine(p8b, p5b);
	ofDrawLine(p8b, p7b);
	ofDrawLine(p7b, p6b);
	ofDrawLine(p7b, p5b);
	ofDrawLine(p5b, p3b);
	ofDrawLine(p1_1b, p2b);
	ofDrawLine(p1b, p1_1b);
	ofDrawLine(p1b, p3b);

	ofDrawLine(o8b, o5b);
	ofDrawLine(o8b, o7b);
	ofDrawLine(o7b, o6b);
	ofDrawLine(o7b, o5b);
	ofDrawLine(o5b, o3b);
	ofDrawLine(o1_1b, o2b);
	ofDrawLine(o1b, o1_1b);
	ofDrawLine(o1b, o3b);

	ofDrawLine(o5, o5b);
	ofDrawLine(p5, p5b);
	ofDrawLine(o1, o1b);
	ofDrawLine(p1, p1b);
	ofDrawLine(o7, o7b);
	ofDrawLine(p7, p7b);
	ofDrawLine(o4, o4b);
	ofDrawLine(p4, p4b);

	ofDrawLine(p8m1, p5m1);
	ofDrawLine(p8m1, p7m1);
	ofDrawLine(p7m1, p5m1);
	ofDrawLine(p8m2, p5m2);
	ofDrawLine(p8m2, p7m2);
	ofDrawLine(p7m2, p5m2);
	ofDrawLine(p8m3, p5m3);
	ofDrawLine(p8m3, p7m3);
	ofDrawLine(p7m3, p5m3);
	ofDrawLine(o8m1, o5m1);
	ofDrawLine(o8m1, o7m1);
	ofDrawLine(o7m1, o5m1);
	ofDrawLine(o8m2, o5m2);
	ofDrawLine(o8m2, o7m2);
	ofDrawLine(o7m2, o5m2);
	ofDrawLine(o8m3, o5m3);
	ofDrawLine(o8m3, o7m3);
	ofDrawLine(o7m3, o5m3);

	ofPoint h1 = ofVec3f(0, 20, 700);
	ofPoint h2 = ofVec3f(50, 30, 440);
	ofPoint h3 = ofVec3f(-50, 30, 440);
	ofDrawSphere(h1, 8);
	ofDrawSphere(h2, 8);
	ofDrawSphere(h3, 8);
	ofDrawLine(h1, h2);
	ofDrawLine(h1, h3);
	ofDrawLine(h3, h2);
	//ofDrawLine(p4, h2);
	//ofDrawLine(o4, h3);
	ofDrawLine(o2, h2);
	ofDrawLine(p2, h3);

	ofPoint t1 = ofVec3f(30, 0, -500);
	ofPoint t2 = ofVec3f(-30, 0, -500);
	ofPoint t3 = ofVec3f(-100, 20, -600);
	ofPoint t4 = ofVec3f(100, 20, -600);
	ofDrawSphere(t1, 8);
	ofDrawSphere(t2, 8);
	ofDrawSphere(t3, 8);
	ofDrawSphere(t4, 8);
	ofDrawLine(t1, o2b);
	ofDrawLine(t2, p2b);
	ofDrawLine(t3, t4);
	ofDrawLine(t1, t2);
	ofDrawLine(t3, t2);
	ofDrawLine(t1, t4);
	
	ofDisableDepthTest();
	camera.end();
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
