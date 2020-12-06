#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	camWidth = 1080;
	camHeight = 720;

	video.setDesiredFrameRate(60);
	video.initGrabber(camWidth, camHeight);
	ofSetVerticalSync(true);

	float vidArea = video.getWidth() * video.getHeight();
	
	gui.setup();
	gui.add( threshold.setup("threshold", 122, 0, 255));
	
}

//--------------------------------------------------------------
void ofApp::update(){
	
	ofBackground(100, 100, 100);
	video.update();
	
	if (video.isFrameNew())
	{
		colorImg.setFromPixels(video.getPixels());
		threshImg = colorImg;
		threshImg.threshold(threshold);
		
		blobFinder.findContours(threshImg, 0, 640*480, maxBlobs, false);
		
		for (int i=0; i<blobFinder.nBlobs; i++)

		{
			auto& pts = blobFinder.blobs[i].pts;
			
			ofPath path;
			path.moveTo(pts[0]);
			
			for (int j=1; j<pts.size(); j++)
			{
				path.lineTo(pts[j]);
			}
			
			path.lineTo(pts[0]);	
			path.close();
			
		}
	}
	
}

//--------------------------------------------------------------
void ofApp::draw(){

	ofSetHexColor(0xffffff);
	
	threshImg.draw(0,0);
	
	blobFinder.draw(0,0);

	gui.draw();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

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
