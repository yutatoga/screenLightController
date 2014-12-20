#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
		ofBackground(0, 0, 0);
		
		//ofxOsc
		sender.setup(HOST, PORT);
		
		// ofxUI
		gui = new ofxUICanvas();
		gui->setPosition(10, 20);
		gui->addSlider("color R", 0.0, 255.0, &sliderR);
		gui->addSlider("color G", 0.0, 255.0, &sliderG);
		gui->addSlider("color B", 0.0, 255.0, &sliderB);
		ofAddListener(gui->newGUIEvent, this, &ofApp::guiEvent);
		gui->loadSettings("settings.xml");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp::guiEvent(ofxUIEventArgs &e){
		string name = e.widget->getName();
		//    int kind = e.widget->getKind();
		if (name == "color R" && e.getSlider()->getValue()) {
				ofColor backgroundColor = ofGetBackground();
				backgroundColor.r = e.getSlider()->getValue();
				ofBackground(backgroundColor);
				
				//ofxOsc
				ofxOscMessage m;
				m.setAddress("/color/red");
				m.addFloatArg(e.getSlider()->getValue());
				sender.sendMessage(m);
		}else if(name == "color G" && e.getSlider()->getValue()){
				ofColor backgroundColor = ofGetBackground();
				backgroundColor.g = e.getSlider()->getValue();
				ofBackground(backgroundColor);

				//ofxOsc
				ofxOscMessage m;
				m.setAddress("/color/green");
				m.addFloatArg(e.getSlider()->getValue());
				sender.sendMessage(m);
		}else if (name == "color B" && e.getSlider()->getValue()){
				ofColor backgroundColor = ofGetBackground();
				backgroundColor.b = e.getSlider()->getValue();
				ofBackground(backgroundColor);
				
				//ofxOsc
				ofxOscMessage m;
				m.setAddress("/color/blue");
				m.addFloatArg(e.getSlider()->getValue());
				sender.sendMessage(m);
		}
}

void ofApp::exit(){
		gui->saveSettings("settings.xml");
		delete gui;
}