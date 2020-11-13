// The Nature of Code
// Daniel Shiffman
// http://natureofcode.com


class mover {
public:
    
    ofPoint location, velocity, acceleration;
    float mass;
	float radius;

	
    
    mover() {

		mass = ofRandom(0.8, 1.2);
		//float random1 = ofRandom(6.28);
		radius = ofRandom(6, 10);
		//float v = ofRandom(1.4, 1.6);
		location.set(ofRandom(0,1080), 768);
        velocity.set(ofRandom(-3,3),ofRandom(-5,-3));
        acceleration.set(0,0);
    }

    void applyForce(ofPoint force) {
        force /= mass;
        acceleration += force;
    }
    
    void update() {
        velocity += acceleration;
        location += velocity;
        acceleration.set(0,0);
    }
    
    void display() {
        ofSetLineWidth(2);
        //ofSetColor(0,127);
		float v = velocity.x*velocity.x + velocity.y * velocity.y;
		v = pow(v, 0.5);
		float hue = ofMap(v,0,8,255,150);
		
			//ofSetColor(0, 0);

			ofColor c;
			c.setHsb(hue, 220, 220);
			ofSetColor(c);
		
			//cout << v << endl;
			ofPoint p1, p2, p3, p4, p5;
			p1 = ofVec2f(location.x + 1.707 * radius, location.y + 0.707*radius);
			p2 = ofVec2f(location.x - 1.707 * radius, location.y + 0.707*radius);
			p3 = ofVec2f(location.x, location.y + 2.121*radius);
			p4 = ofVec2f(location.x - radius, location.y);
			p5 = ofVec2f(location.x + radius, location.y);
			ofDrawCircle(location.x - radius, location.y, radius);
			ofDrawCircle(location.x + radius, location.y, radius);
			ofDrawTriangle(p1, p2, p3);
			ofDrawTriangle(p4, p5, p3);
    }
    
};