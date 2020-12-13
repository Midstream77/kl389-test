#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){

	ofBackground(255);
	ofSetCircleResolution(100);
	ofSetFrameRate(60);
	roll.setDefault();
	Engine.setDefault();
	show = 3;
	speedKey = 50;
	
	for (int i = 0; i < 36; i++) {
		float depth = (i + 1) * 20 - 400;
		inputs[i].setDefault(depth);
		outputs[i].setDefault(depth);
	}

	F1p.load("22-F#.mp3");
	G1.load("23-G.mp3");
	G1p.load("24-G#.mp3");
	A1.load("25-A.mp3");
	A1p.load("26-A#.mp3");
	B1.load("27-B.mp3");
	C2.load("28-C.mp3");
	C2p.load("29-C#.mp3");
	D2.load("30-D.mp3");
	D2p.load("31-D#.mp3");
	E2.load("32-E.mp3");
	F2.load("33-F.mp3");
	F2p.load("34-F#.mp3");
	G2.load("35-G.mp3");
	G2p.load("36-G#.mp3");
	A2.load("37-A.mp3");
	A2p.load("38-A#.mp3");
	B2.load("39-B.mp3");
	C3.load("40-C.mp3");
	C3p.load("41-C#.mp3");
	D3.load("42-D.mp3");
	D3p.load("43-D#.mp3");
	E3.load("44-E.mp3");
	F3.load("45-F.mp3");
	F3p.load("46-F#.mp3");
	G3.load("47-G.mp3");
	G3p.load("48-G#.mp3");
	A3.load("49-A.mp3");
	A3p.load("50-A#.mp3");
	B3.load("51-B.mp3");
	C4.load("52-C.mp3");
	C4p.load("53-C#.mp3");
	D4.load("54-D.mp3");
	D4p.load("55-D#.mp3");
	E4.load("56-E.mp3");
	F4.load("57-F.mp3");


}

//--------------------------------------------------------------
void ofApp::update(){

	time = ofGetElapsedTimef();
	float defaultSpeed = 360 * time;
	speed = defaultSpeed / speedKey;

	for (int i = 0; i < 36; i++) {
		if (show == 0) {
			inputs[i].update();
			outputs[i].update();
		}
		else if (show == 1) {
			inputs[i].update();
		}
		else if (show == 2) {
			outputs[i].update();
		}
	}
	
		Engine.update(speed);

}

//--------------------------------------------------------------
void ofApp::draw(){

	cam.begin();
	ofEnableDepthTest();

	
		Engine.draw();

	for (int i = 0; i < 36; i++) {
		if (show == 0) {
			inputs[i].draw();
			outputs[i].draw();
		}
		else if (show == 1) {
			inputs[i].draw();
		}
		else if (show == 2) {
			outputs[i].draw();
		}
	}

	roll.draw(speed);
	if (bumps.size() > 0) {
		for (int i = 0; i < bumps.size(); i++) {
			bumps[i].speed = speed;
			if (bumps[i].check()) {
				bumps[i].time = time;
				int t = (bumps[i].depth + 400) / 20 - 1;
				//std::cout << bumps[i].depth<<endl;
				//std::cout << t << endl;
				if (bumps[i].time-bumps[i].sound>0.2) {
					if (show == 0 || show == 2) {
						outputs[t].match = true;
					}
					bumps[i].sound = time;
					arr[t].play();
					arr[t].setPositionMS(arr2[t]);
				}
			}
			bumps[i].draw(speed);
		}
	}

	ofDisableDepthTest();
	cam.end();

	stringstream ss;
	ss << "FPS: " << ofToString(ofGetFrameRate(), 0) << endl << endl;
	ofDrawBitmapStringHighlight(ss.str().c_str(), 20, 20);

	//cout << speed << "\n";
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	if (key == '1') {
		if (!bumps.empty()) {
			for (int i = 0; i < bumps.size(); i++) {
				bumps[i].output();
			}
		}
	}

	if (key == ' ') {
		if(!bumps.empty())
			
				bumps.pop_back();
		
	}

	if (key == '+')
		speedKey++;
	if (key == '_')
		speedKey--;

	if (key == '4') {
		cout << show << endl;
		if (show == 3) {
			show = 0;
		}
		else
			show++;
	}
	if (key == 'a') {
		bump newbump;
		newbump.setDefault(speed, -380);
		bumps.push_back(newbump);
		
		inputs[0].press();
		F1p.play();
		F1p.setPositionMS(1300);
		
	}
	if (key == 'z') {
		bump newbump;
		newbump.setDefault(speed, -360);
		bumps.push_back(newbump);

		inputs[1].press();
		G1.play();
		G1.setPositionMS(1300);
	}
	if (key == 's') {
		bump newbump;
		newbump.setDefault(speed, -340);
		bumps.push_back(newbump);

		inputs[2].press();
		G1p.play();
		G1p.setPositionMS(1200);
	}
	if (key == 'x') {
		bump newbump;
		newbump.setDefault(speed, -320);
		bumps.push_back(newbump);

		inputs[3].press();
		A1.play();
		A1.setPositionMS(1000);
	}
	if (key == 'd') {
		bump newbump;
		newbump.setDefault(speed, -300);
		bumps.push_back(newbump);

		inputs[4].press();
		A1p.play();
		A1p.setPositionMS(1000);
	}
	if (key == 'c') {
		bump newbump;
		newbump.setDefault(speed, -280);
		bumps.push_back(newbump);

		inputs[5].press();
		B1.play();
		B1.setPositionMS(1000);
	}
	if (key == 'v') {
		bump newbump;
		newbump.setDefault(speed, -260);
		bumps.push_back(newbump);

		inputs[6].press();
		C2.play();
		C2.setPositionMS(1000);
	}
	if (key == 'g') {
		bump newbump;
		newbump.setDefault(speed, -240);
		bumps.push_back(newbump);

		inputs[7].press();
		C2p.play();
		C2p.setPositionMS(1000);
	}
	if (key == 'b') {
		bump newbump;
		newbump.setDefault(speed, -220);
		bumps.push_back(newbump);

		inputs[8].press();
		D2.play();
		D2.setPositionMS(1000);
	}
	if (key == 'h') {
		bump newbump;
		newbump.setDefault(speed, -200);
		bumps.push_back(newbump);

		inputs[9].press();
		D2p.play();
		D2p.setPositionMS(1000);
	}
	if (key == 'n') {
		bump newbump;
		newbump.setDefault(speed, -180);
		bumps.push_back(newbump);

		inputs[10].press();
		E2.play();
		E2.setPositionMS(1000);
	}
	if (key == 'm') {
		bump newbump;
		newbump.setDefault(speed, -160);
		bumps.push_back(newbump);

		inputs[11].press();
		F2.play();
		F2.setPositionMS(800);
	}
	if (key == 'k') {
		bump newbump;
		newbump.setDefault(speed, -140);
		bumps.push_back(newbump);

		inputs[12].press();
		F2p.play();
		F2p.setPositionMS(800);
	}
	if (key == ',') {
		bump newbump;
		newbump.setDefault(speed, -120);
		bumps.push_back(newbump);

		inputs[13].press();
		G2.play();
		G2.setPositionMS(800);
	}
	if (key == 'l') {
		bump newbump;
		newbump.setDefault(speed, -100);
		bumps.push_back(newbump);

		inputs[14].press();
		G2p.play();
		G2p.setPositionMS(800);
	}
	if (key == '.') {
		bump newbump;
		newbump.setDefault(speed, -80);
		bumps.push_back(newbump);

		inputs[15].press();
		A2.play();
		A2.setPositionMS(800);
	}
	if (key == ';') {
		bump newbump;
		newbump.setDefault(speed, -60);
		bumps.push_back(newbump);

		inputs[16].press();
		A2p.play();
		A2p.setPositionMS(800);
	}
	if (key == '/') {
		bump newbump;
		newbump.setDefault(speed, -40);
		bumps.push_back(newbump);

		inputs[17].press();
		B2.play();
		B2.setPositionMS(800);
	}
	if (key == 'q') {
		bump newbump;
		newbump.setDefault(speed, -20);
		bumps.push_back(newbump);

		inputs[18].press();
		C3.play();
		C3.setPositionMS(500);
	}
	if (key == '2') {
		bump newbump;
		newbump.setDefault(speed, 0);
		bumps.push_back(newbump);

		inputs[19].press();
		C3p.play();
		C3p.setPositionMS(500);
	}
	if (key == 'w') {
		bump newbump;
		newbump.setDefault(speed, 20);
		bumps.push_back(newbump);

		inputs[20].press();
		D3.play();
		D3.setPositionMS(500);
	}
	if (key == '3') {
		bump newbump;
		newbump.setDefault(speed, 40);
		bumps.push_back(newbump);

		inputs[21].press();
		D3p.play();
		D3p.setPositionMS(600);
	}
	if (key == 'e') {
		bump newbump;
		newbump.setDefault(speed, 60);
		bumps.push_back(newbump);

		inputs[22].press();
		E3.play();
		E3.setPositionMS(400);
	}
	if (key == 'r') {
		bump newbump;
		newbump.setDefault(speed, 80);
		bumps.push_back(newbump);

		inputs[23].press();
		F3.play();
		F3.setPositionMS(400);
	}
	if (key == '5') {
		bump newbump;
		newbump.setDefault(speed, 100);
		bumps.push_back(newbump);

		inputs[24].press();
		F3p.play();
		F3p.setPositionMS(400);
	}
	if (key == 't') {
		bump newbump;
		newbump.setDefault(speed, 120);
		bumps.push_back(newbump);

		inputs[25].press();
		G3.play();
		G3.setPositionMS(400);
	}
	if (key == '6') {
		bump newbump;
		newbump.setDefault(speed, 140);
		bumps.push_back(newbump);

		inputs[26].press();
		G3p.play();
		G3p.setPositionMS(600);
	}
	if (key == 'y') {
		bump newbump;
		newbump.setDefault(speed, 160);
		bumps.push_back(newbump);

		inputs[27].press();
		A3.play();
		A3.setPositionMS(500);
	}
	if (key == '7') {
		bump newbump;
		newbump.setDefault(speed, 180);
		bumps.push_back(newbump);

		inputs[28].press();
		A3p.play();
		A3p.setPositionMS(300);
	}
	if (key == 'u') {
		bump newbump;
		newbump.setDefault(speed, 200);
		bumps.push_back(newbump);

		inputs[29].press();
		B3.play();
		B3.setPositionMS(300);
	}
	if (key == 'i') {
		bump newbump;
		newbump.setDefault(speed, 220);
		bumps.push_back(newbump);

		inputs[30].press();
		C4.play();
		C4.setPositionMS(300);
	}
	if (key == '9') {
		bump newbump;
		newbump.setDefault(speed, 240);
		bumps.push_back(newbump);

		inputs[31].press();
		C4p.play();
		C4p.setPositionMS(300);
	}
	if (key == 'o') {
		bump newbump;
		newbump.setDefault(speed, 260);
		bumps.push_back(newbump);

		inputs[32].press();
		D4.play();
		D4.setPositionMS(300);
	}
	if (key == '0') {
		bump newbump;
		newbump.setDefault(speed, 280);
		bumps.push_back(newbump);

		inputs[33].press();
		D4p.play();
		D4p.setPositionMS(300);
	}
	if (key == 'p') {
		bump newbump;
		newbump.setDefault(speed, 300);
		bumps.push_back(newbump);

		inputs[34].press();
		E4.play();
		E4.setPositionMS(300);
	}
	if (key == '[') {
		bump newbump;
		newbump.setDefault(speed, 320);
		bumps.push_back(newbump);

		inputs[35].press();
		F4.play();
		F4.setPositionMS(300);
	}
	
	
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

float ofApp::getX(ofPoint X, float y, float r) {

	float m, n, b, c, result;
	m = X.x;
	n = X.y;
	b = -2*m;
	c = m * m + n * n - r * r - 2 * n*y + y * y;
	result = (-b + pow(b*b - 4 * c, 0.5)) / 2;
	return result;

}

ofPoint ofApp::getRealPoint1(ofPoint x, ofPoint y, float R1, float R2,float z) {
	float a = x.x, b = x.y, m = y.x, n = y.y;
	float t = (R1*R1 - R2 * R2 + m * m + n * n - a * a - b * b) / (2 * (m - a));
	//cout << "t=" << t << endl;
	float t1 = t - a;
	float s = (n - b) / (m - a);
	//cout << "s=" << s << endl;
	float A = (s*s + 1);
	float B = -(2 * s*t1 + 2 * b);
	float C = t1 * t1 + b * b - R1 * R1;
	float Y = (-B - pow(B*B - 4 * A*C, 0.5)) / (2 * A);
	//cout << "Y=" << Y << endl;

	//float t = (R1*R1 - R2 * R2 + m * m + n * n - a * a - b * b) / (2 * (m - a));
	//float s = (n - b) / (m - a);
	//float Y = getY1(a, b, m, n, R1, R2);
	float X = t - s * Y;
	//cout << "X=" << X << endl;

	ofPoint result = ofVec3f(X, Y, z);
	return result;

}

ofPoint ofApp::getRealPoint2(ofPoint x, ofPoint y, float R1, float R2, float z) {
	float a = x.x, b = x.y, m = y.x, n = y.y;
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

	//float t = (R1*R1 - R2 * R2 + m * m + n * n - a * a - b * b) / (2 * (m - a));
	//float s = (n - b) / (m - a);
	//float Y = getY1(a, b, m, n, R1, R2);
	float X = t - s * Y;
	//cout << "X=" << X << endl;

	ofPoint result = ofVec3f(X, Y, z);
	return result;

}

ofPoint ofApp::getPoint1(ofPoint x, ofPoint y, float R1, float R2, float z) {
	if (x.x > y.x)
		return getRealPoint1(x, y, R1, R2, z);
	else
		return getRealPoint2(x, y, R1, R2, z);
}

ofPoint ofApp::getPoint2(ofPoint x, ofPoint y, float R1, float R2, float z) {
	if (x.x < y.x)
		return getRealPoint1(x, y, R1, R2, z);
	else
		return getRealPoint2(x, y, R1, R2, z);
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
