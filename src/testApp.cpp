#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    //OSC Receiver Port
    mReceiver.setup( 12345 );
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    //    ofBackground(230,190,50);
    ofBackground(0);
    ofEnableAlphaBlending();
    ofEnableSmoothing();
    
    for (int i = 0; i < 20000; i++){
        Particle myParticle;
        myParticle.setInitCondition(ofRandom(0,1000), ofRandom(0,1000), 0, 0);
        myParticle.damping = ofRandom(0.01,0.05);
        particles.push_back(myParticle);
    }
}

//--------------------------------------------------------------
void testApp::update(){
    checkOsc();
    
    for (int i = 0; i < particles.size(); i++){
        particles[i].resetForce();
        particles[i].addAttraction(mouseX, mouseY, 1000, 0.05);
        particles[i].addRepulsion(mouseX, mouseY, 30, 35);
        particles[i].addDamping();
        particles[i].update();
        
        if (i == 0){
            particles[i].trail(mouseX, mouseY);
        }else{
            particles[i].trail(particles[i-1].pos.x, particles[i-1].pos.y);
        }
        
    }

    
}

void testApp::checkOsc(){
    
    while (mReceiver.hasWaitingMessages() ) {
        ofxOscMessage  m;
        mReceiver.getNextMessage(&m);
        
        string addr = m.getAddress();
        
        if(addr == "/1/slider"){
            
            int xPos = m.getArgAsInt32(0);
            int yPos = m.getArgAsInt32(1);
            
            mousePos.set(xPos, yPos);
        }else if(addr == "/1/fader1"){
            //int to float problem here for the Vector2 ballPos
            float xPos = m.getArgAsFloat(0);
            int yPos = 1;//m.getArgAsInt32(1);
            
            ballPos.set(xPos, yPos);
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(255);
    ofCircle(ballPos * 100, 20);
    
    
    for (int i = 0; i < particles.size(); i++){
        
        particles[i].draw();
    }

    
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    for (int i = 0; i < particles.size(); i++){
        particles[i].resetForce();
        particles[i].addRepulsion(x, y, 50, 80);
        particles[i].addDamping();
        particles[i].update();
    }

    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 
    
}