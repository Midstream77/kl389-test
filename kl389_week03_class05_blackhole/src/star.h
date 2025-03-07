// The Nature of Code
// Daniel Shiffman
// http://natureofcode.com

// A class for a draggable attractive body in our world

class star {
public:

	float mass;    // Mass, tied to size
	float G;       // Gravitational Constant
	ofPoint location;   // Location
	bool dragging = false; // Is the object being dragged?
	bool rollover = false; // Is the mouse over the ellipse?
	ofPoint dragOffset;  // holds the offset for when object is clicked on

	star() {
		location.set(300, 300);
		mass = 20;
		G = 5;
		dragOffset.set(0, 0);
	}

	ofPoint attract(mover m) {
		ofPoint force;
		force.set(location);
		force -= m.location;                                // Calculate direction of force
		float d = force.length();                           // Distance between objects
		d = ofClamp(d, 8.0, 1000);                          // Limiting the distance to eliminate "extreme" results for very close or very far objects
		force.normalize();                                  // Normalize vector (distance doesn't matter here, we just want this vector for direction)
		float strength = (G * mass * m.mass) / (d * d);     // Calculate gravitional force magnitude
		force *= strength;                                  // Get force vector --> magnitude * direction
		return force;
	}

	// Method to display
	void display() {
		//if (dragging) ofSetColor(50);
		//else if (rollover) ofSetColor(100);
		ofSetColor(255,220,0, 200);
		ofDrawCircle(location.x, location.y, mass);
	}

	// The methods below are for mouse interaction
	void clicked(int mx, int my) {
		ofPoint a;
		ofPoint b;
		a.set(mx, my);
		b.set(location.x, location.y);
		b -= a;
		float d = b.length();
		if (d < mass) {
			dragging = true;
			dragOffset.x = location.x - mx;
			dragOffset.y = location.y - my;
		}
	}

	void hover(int mx, int my) {
		ofPoint a;
		ofPoint b;
		a.set(mx, my);
		b.set(location.x, location.y);
		b -= a;
		float d = b.length();
		if (d < mass) {
			rollover = true;
		}
		else {
			rollover = false;
		}
	}

	void stopDragging() {
		dragging = false;
	}



	void drag() {
		if (dragging) {
			location.x = ofGetMouseX() + dragOffset.x;
			location.y = ofGetMouseY() + dragOffset.y;
		}
	}

};