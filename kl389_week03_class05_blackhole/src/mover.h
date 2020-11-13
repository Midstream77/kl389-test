// The Nature of Code
// Daniel Shiffman
// http://natureofcode.com


class mover {
public:
    
    ofPoint location, velocity, acceleration;
    float mass;
	bool dead;
	
    
    mover() {
		dead = false;
		mass = ofRandom(0.8, 1.2);
		float random1 = ofRandom(6.28);
		float radius = ofRandom(39, 62);
		float v = ofRandom(1.4, 1.6);
		location.set(300 + radius*sin(random1), 300 + radius*cos(random1));
		//float p = ofRandom(1.4, 1.6);
		//float v = ofRandom(1.4, 1.6);
        velocity.set(v*sin(random1+1.57),v*cos(random1 + 1.57));
        acceleration.set(0,0);
    }

    void applyForce(ofPoint force) {
        // Divide by mass
        force /= mass;
        // Accumulate all forces in acceleration
        acceleration += force;
    }
    
    void update() {
        // Velocity changes according to acceleration
        velocity += acceleration;
        // Location changes by velocity
        location += velocity;
        // We must clear acceleration each frame        
        acceleration.set(0,0);
    }
    
    void display() {
        ofSetLineWidth(2);
        //ofSetColor(0,127);
		float v = velocity.x*velocity.x + velocity.y * velocity.y;
		v = pow(v, 0.5);
		float hue = ofMap(v,0,4,150,255);
		
			//ofSetColor(0, 0);

			ofColor c;
			c.setHsb(hue, 220, 220);
			ofSetColor(c);
		
			//cout << v << endl;
        ofDrawCircle(location.x,location.y,mass*8);
    }
    
};