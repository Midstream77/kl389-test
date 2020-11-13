// The Nature of Code
// Daniel Shiffman
// http://natureofcode.com

// Example 2-7: Attraction


#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(255);
    ofEnableSmoothing();
    ofEnableAlphaBlending();

    
}

//--------------------------------------------------------------
void ofApp::update(){
	a.hover(mouseX, mouseY);
	//float time = sin(ofGetElapsedTimef());
	//cout << time << endl;
	int k = (int)ofRandom(60);
	if(k<3) {
		movers.push_back(mover());
	}
    
    for (int i=0;i<movers.size();i++) {
		float distance = pow(pow((movers[i].location.x - a.location.x), 2) + pow((movers[i].location.y - a.location.y), 2), 0.5);
        ofPoint force = a.attract(movers[i]);
		ofPoint force2 = ofVec3f(0, 0.03);
		
		if (distance < 120) {
			movers[i].applyForce(force);
			movers[i].velocity = movers[i].velocity*0.96;
		}
		else
			movers[i].applyForce(force2);
		
		
        movers[i].update();
    }
}
//--------------------------------------------------------------
void ofApp::draw(){
    a.display();
    //C++11 syntax to call for each member in vector
    for (auto& m: movers){
        m.display();
    }
}
//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){ }
//--------------------------------------------------------------
void ofApp::keyPressed(int key){ }
//--------------------------------------------------------------
void ofApp::keyReleased(int key){ }
//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    a.drag();
	
}
//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    a.clicked(mouseX, mouseY);
	
}
//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    a.stopDragging();
	
}
//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){ }
//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){ }
//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ }