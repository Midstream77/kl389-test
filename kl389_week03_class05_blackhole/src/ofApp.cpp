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

	movers.push_back(mover());
    for (int i=1;i<250;i++) {
        movers.push_back(mover());
    }
}

//--------------------------------------------------------------
void ofApp::update(){
	a.hover(mouseX, mouseY);
	b.hover(mouseX, mouseY);
    
    for (int i=0;i<movers.size();i++) {
		float distance = pow(pow((movers[i].location.x - a.location.x), 2) + pow((movers[i].location.y - a.location.y), 2), 0.5);
        ofPoint force = a.attract(movers[i]);
		ofPoint force2 = b.attract(movers[i]);
		if (distance < 100) {
			movers[i].applyForce(force);
		}
		movers[i].applyForce(force2);
		if (distance < a.mass) {
			movers[i].dead = true;
		}
        movers[i].update();
    }
}
//--------------------------------------------------------------
void ofApp::draw(){
    a.display();
	b.display();
    //C++11 syntax to call for each member in vector
    for (auto& m: movers){
		if (m.dead == true)
			continue;
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
	//b.drag();
}
//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    a.clicked(mouseX, mouseY);
	//b.clicked(mouseX, mouseY);
}
//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    a.stopDragging();
	//b.stopDragging();
}
//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){ }
//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){ }
//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ }