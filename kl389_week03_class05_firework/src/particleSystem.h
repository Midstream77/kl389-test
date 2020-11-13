#pragma once
#include "ofMain.h"
#include "particle.h"

class particleSystem{

public:
    particleSystem(ofPoint,float);
    void update();
    void display();
    void addParticle();
    
    ofPoint origin;
	ofPoint Alocation;
	float borntime;
    vector<particle*> particles;
};
