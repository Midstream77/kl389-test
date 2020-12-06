#include "ofApp.h"

ofVec3f X = ofVec3f(1, 0, 0);
ofVec3f Y = ofVec3f(0, 1, 0);
ofVec3f Z = ofVec3f(0, 0, 1);
//--------------------------------------------------------------
void ofApp::setup() {

	ofSetBackgroundColor(200);

	mesh.setMode(OF_PRIMITIVE_LINES);
	mesh.enableColors();
	mesh.enableIndices();

	box1.setPosition(0, 0, 0);
	box1.set(20, 350, 20);
	box1.setResolution(1);
	box1.setResolutionHeight(7);

	box5.setPosition(0, -175, 0);
	box5.set(2000, 1, 2000);
	box5.setResolution(8);
	box5.setResolutionHeight(1);

	cylinder.setPosition(-100, 175, 0);
	cylinder.set(14, 600, true);
	ofPrimitiveMode mode = OF_PRIMITIVE_TRIANGLE_STRIP;
	cylinder.setMode(mode);
	cylinder.setResolutionCap(1);
	cylinder.setResolutionHeight(8);
	cylinder.setResolutionRadius(3);
	
	cylinder.rotateDeg(90, Z);
	
	cone.setPosition(0, 230, 0);
	cone.set(13, 120);
	cone.setResolutionRadius(4);
	cone.setResolutionCap(1);
	cone.rotateDeg(180, X);
	cone.rotateDeg(45, Y);

	ofPoint pos = cylinder.getPosition();
	box2.setPosition(-pos.x*1.7, pos.y - 10, -pos.z*1.7);
	box2.set(20, 40, 20);

	
}

//--------------------------------------------------------------
void ofApp::update(){

	

}

//--------------------------------------------------------------
void ofApp::draw(){

	float time = ofGetElapsedTimef()*0.15;
	float noise = ofNoise(time);
	float noise3 = ofNoise(time*0.8);
	float noise4 = ofNoise((0.728+time)*1.3);
	ofPoint pos = cylinder.getPosition();

	cam.begin();
	ofEnableDepthTest();

	box3.setPosition(pos.x*1.7, pos.y - 10, pos.z*1.7);
	box3.set(20, 40, 20);


	ofNoFill();
	ofSetColor(0, 0, 0);
	//box1.setScale(1.01f);

	
	ofPushMatrix();
	
		ofPoint end = ofVec3f(-pos.x*2, pos.y, -pos.z*2);
		ofPoint front = ofVec3f(pos.x * 4, pos.y + 14, pos.z * 4);
		ofPoint top = ofVec3f(0, 290, 0);
		box3.setPosition(pos.x*4*noise3, pos.y - 10, pos.z*1.7);
		box3.set(20, 10, 20);
		box4.setPosition(pos.x * 4 * noise3, pos.y - 380*noise4, pos.z*1.7);
		box4.set(20, 10, 20);
		ofRotateYDeg(noise*270);
		cylinder.drawWireframe();
		box2.drawWireframe();
		box3.drawWireframe();
		box4.drawWireframe();
		ofDrawLine(end, top);
		ofDrawLine(front, top);
		ofDrawLine(box3.getPosition(), box4.getPosition());


	ofPopMatrix();

	box1.drawWireframe();
	cone.drawWireframe();
	box5.drawWireframe();
	

	ofDisableDepthTest();
	cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
