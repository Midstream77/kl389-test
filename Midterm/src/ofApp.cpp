#include "ofApp.h"
#include <math.h>

//--------------------------------------------------------------
int num = 550;
bool arrowDisplay = true;
bool moverDisplay;
bool bHelpText = true;
//ofPoint startPoint;
//ofPoint endPoint;
void ofApp::setup() {
	ofSetFrameRate(60);
	ofSetCircleResolution(100);
	ofEnableSmoothing();
	ofEnableAlphaBlending();
	ofBackground(255);
	ofFill();

	

	for (int i = 0; i < 550; i++) {
		//mover tempMover;
		//movers.push_back(tempMover);
		movers[i].setup(6, ofRandom(5,475), ofRandom(5,475));
	}
}

//--------------------------------------------------------------
void ofApp::update() {

	for (int i = 0; i < num; i++) {
		movers[i].update();
		movers[i].checkEdges();
	}
	movers[0].reject(movers, num);

	for (int I = 0; I < f.size(); I++) {
		
		ofPoint startPoint = f[I].startPoint;
		ofPoint endPoint = f[I].endPoint;

		float dis = pow(pow(endPoint.x - startPoint.x, 2) + pow(endPoint.y - startPoint.y, 2), 0.5);
		float a = asin((endPoint.y - startPoint.y) / dis);
		
		ofPoint p1, p2, p3, p4, a3, a4;
		float a1, a2, k;

		//the area which apply force
		if (startPoint.x < endPoint.x) {
			p1 = ofVec2f(startPoint.x + cos(a + 1.57) * 30, startPoint.y + sin(a + 1.57) * 30);
			p2 = ofVec2f(startPoint.x - cos(a + 1.57) * 30, startPoint.y - sin(a + 1.57) * 30);
			p3 = ofVec2f(endPoint.x + cos(a + 1.57) * 30, endPoint.y + sin(a + 1.57) * 30);
			p4 = ofVec2f(endPoint.x - cos(a + 1.57) * 30, endPoint.y - sin(a + 1.57) * 30);
		}
		else {
			p1 = ofVec2f(startPoint.x - cos(a - 1.57) * 30, startPoint.y + sin(a - 1.57) * 30);
			p2 = ofVec2f(startPoint.x + cos(a - 1.57) * 30, startPoint.y - sin(a - 1.57) * 30);
			p3 = ofVec2f(endPoint.x - cos(a - 1.57) * 30, endPoint.y + sin(a - 1.57) * 30);
			p4 = ofVec2f(endPoint.x + cos(a - 1.57) * 30, endPoint.y - sin(a - 1.57) * 30);
		}

		if (p1.x + p1.y > p3.x + p3.y) {
			a1 = p1.x + p1.y;
			a2 = p3.x + p3.y;
		}
		else {
			a1 = p3.x + p3.y;
			a2 = p1.x + p1.y;
		}
		k = (endPoint.y - startPoint.y) / (endPoint.x - startPoint.x);
		if (endPoint.x > startPoint.x) {
			a3 = p3;
			a4 = p4;
		}
		else {
			a3 = p4;
			a4 = p3;
		}

		for (int j = 0; j < num; j++)
		{
			if (movers[j].location.x + movers[j].location.y > a2&&movers[j].location.x + movers[j].location.y < a1&&
				movers[j].location.y < k*(movers[j].location.x - a3.x) + a3.y&&
				movers[j].location.y > k*(movers[j].location.x - a4.x) + a4.y) {
				movers[j].applyForce(f[I].force);
				//movers[j].isdisplay = true;
			}
		}
	}
	//cout << f.size() << endl;
}

//--------------------------------------------------------------
void ofApp::draw() {

	for (int i = 0; i < num; i++) {
		if (moverDisplay) {
			if (movers[i].isdisplay)
				movers[i].display();
		}
		else
			movers[i].display();
	}
	for (int i = 0; i < f.size(); i++) {
		if(arrowDisplay)
		ofDrawArrow(f[i].startPoint, f[i].endPoint, 10);
	}
	
	//ofSetColor(100);
	//ofDrawCircle(startPoint, 5);
	//ofDrawCircle(p1, 5);
	//ofDrawCircle(p2, 5);
	//ofDrawCircle(p3, 5);
	//ofDrawCircle(p4, 5);
	//ofDrawTriangle(p1, p2, p3);
	//ofDrawTriangle(p2, p3, p4);

	if (bHelpText) {
		stringstream ss;
		ss << "FPS: " << ofToString(ofGetFrameRate(), 0) << endl;
		ss << "left click to add movers" << endl;
		ss << "right click and drag to creat forces" << endl;
		ss << "(d): Show Forces" << endl << "(s): Show Background Movers" << endl;
		ss << "(h): Turn off HelpText" << endl;
		ofDrawBitmapStringHighlight(ss.str().c_str(), 5, 15);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	
	
	if (arrowDisplay&&key == 'd') {
		arrowDisplay = false;
		//cout << "pressed" << endl;
	}
	else if (!arrowDisplay&&key == 'd')
		arrowDisplay = true;

	if (moverDisplay&&key == 's') {
		moverDisplay = false;
		//cout << "pressed" << endl;
	}
	else if (!moverDisplay&&key == 's')
		moverDisplay = true;

	if (bHelpText&&key == 'h') {
		bHelpText = false;
		//cout << "pressed" << endl;
	}
	else if (!bHelpText&&key == 'h')
		bHelpText = true;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

	if (button == 2) {
		f[f.size() - 1].endPoint = ofVec2f(ofGetMouseX(), ofGetMouseY());
	}

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	
	if (button == 2) {
		forces newForce;
		newForce.startPoint = ofVec2f(ofGetMouseX(), ofGetMouseY());
		f.push_back(newForce);
	}

	if (button == 0) {
		movers[num].setup(ofRandom(13, 17), ofGetMouseX(), ofGetMouseY());
		movers[num].isdisplay = true;
		num++;
	}
	
	/*
	if (button == 2) {
		for (int i = 0; i < 20; i++) {
			movers[num + n].setup(ofRandom(4, 8), ofRandom(ofGetMouseX()+ 3, ofGetMouseX() -3), ofRandom(ofGetMouseY() + 3, ofGetMouseY() - 3));
			movers[num + n].isdisplay = true;
			num++;
		}
	}
	*/
	//mover newMover;
	//movers[num + 1] = newMover;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
	if (button == 2) {
		f[f.size()-1].endPoint = ofVec2f(ofGetMouseX(), ofGetMouseY());
		f[f.size() - 1].force = 0.0003*(f[f.size() - 1].endPoint - f[f.size() - 1].startPoint);
	}
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
