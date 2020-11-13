#include "particleSystem.h"

particleSystem::particleSystem(ofPoint location,float born) {
    origin = location;
	borntime = born;
	Alocation = ofVec2f(320, 360);
}

void particleSystem::addParticle(){
	if (ofGetElapsedTimef() - borntime < 1.1&&ofGetElapsedTimef() - borntime > 1) {
		for (int i = 0; i < 10; i++) {
			particles.push_back(new particle(origin));
		}
	}
}

void particleSystem::update(){    
	Alocation += (origin - Alocation) / 35;
	for (int i = 0; i < particles.size(); i++) {
		particles[i]->update();
		if (particles[i]->isDead()) {
			particles.erase(particles.begin() + i);
		}
	}
	Alocation += (origin - Alocation) / 60;
	Alocation += (origin - Alocation) / 120;
}

void particleSystem::display() {
	for (auto& p : particles) {
		p->display();
	}
	ofSetColor(240, 10, 0, 200);
	if (ofGetElapsedTimef() - borntime < 1) {
		ofDrawCircle(Alocation, 5);
	}
}