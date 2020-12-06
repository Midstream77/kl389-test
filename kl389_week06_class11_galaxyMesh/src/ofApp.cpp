#include "ofApp.h"

//--------------------------------------------------------------


//The code of mesh the picture comes from ofbook.
//https://openframeworks.cc/ofBook/chapters/generativemesh.html
//I modify the code by using ofNoise and try to implement a 3D galaxy.


void ofApp::setup(){
	image.load("m51.png");

	mesh.setMode(OF_PRIMITIVE_POINTS);

	mesh.enableColors();

	float intensityThreshold = 145.0;
	int w = image.getWidth();
	int h = image.getHeight();
	for (int x = 0; x < w; ++x) {
		for (int y = 0; y < h; ++y) {
			ofColor c = image.getColor(x, y);
			
			float intensity = c.getLightness();
			if (intensity >= intensityThreshold) {
				float hue = c.getHue();
				float z = 0;
				ofVec4f loc;
				
				if (x > 390 && x < 450 && y>330 && y < 390) {
					z = ofMap(ofNoise(loc*0.003), 0, 1, -70, 70)+ofRandom(-1,7);
					loc = ofVec4f(x * .4, y * .4, hue * 4, c.getSaturation()*0.3);
				}
				else {
					loc = ofVec4f(x * .6, y * .6, hue * 4, c.getSaturation()*0.3);
					z = ofMap(ofNoise(loc*0.003), 0, 1, -50, 50) + ofRandom(-3, 3);
				}
					//float z = ofMap(ofNoise(hue*0.01), 0, 1, -250, 250);
					//float z = ofRandom(-50, 50);
					ofVec3f pos(x+ofRandom(-2,2), y+ofRandom(-2, 2), z);
					mesh.addVertex(pos);
					mesh.addColor(c);
				
			}
		}
	}

}

//--------------------------------------------------------------
void ofApp::update(){
	
}

//--------------------------------------------------------------
void ofApp::draw(){

	ofColor centerColor = ofColor(65, 58, 52);
	ofColor edgeColor(0, 0, 0);
	ofBackgroundGradient(centerColor, edgeColor, OF_GRADIENT_CIRCULAR);

	cam.begin();
	ofPushMatrix();
	ofTranslate(-ofGetWidth() / 2, -ofGetHeight() / 2);
	mesh.draw();
	ofPopMatrix();
	cam.end();
	//cout << mesh.getNumVertices() << endl;
	//image.draw(0, 0);
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
