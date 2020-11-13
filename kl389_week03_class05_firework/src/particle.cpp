#include "particle.h"

particle::particle( ofPoint l ) {
    acceleration.set(0,0.03);
    velocity.set(ofRandom(-2,2), ofRandom(-2,2));
    location = l;
    lifespan = 255.0;
}

void particle::update() {
    velocity += acceleration;
    location += velocity;
    lifespan -= 1.3;
}

void particle::display() {
	float hue = fmodf(ofGetElapsedTimef() * 8, 255);
	ofColor c;
	c.setHsb(ofMap(hue+2*lifespan,150,750,255,100), 255, 220);
	ofSetColor(c);
	ofSetColor(c, lifespan);
	ofDrawCircle(location, ofMap(lifespan,0,255,15,3));
}

bool particle::isDead() {
    if (lifespan < 0.0) {
        return true;
    } else {
        return false;
    }
}