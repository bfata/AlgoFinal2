#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    //OSC Receiver Port
    mReceiver.setup( 12345 );
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(0);
    ofEnableAlphaBlending();
    ofEnableSmoothing();
    
    for (int i = 0; i < 10000; i++){
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
        particles[i].addAttraction(ballPos.x, ballPos.y, 1000, fader2Value);
        particles[i].addRepulsion(ballPos.x, ballPos.y, 30, 35);
        particles[i].addDamping();
        particles[i].update();
        
        // Have particles trail one another
//        if (i == 0){
//            particles[i].trail(ballPos.x, ballPos.y);
//        }else{
//            particles[i].trail(particles[i-1].pos.x, particles[i-1].pos.y);
//        }
        
    }
}
//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(255);
    ofCircle(ballPos, 20);
    
    
    for (int i = 0; i < particles.size(); i++){
        //Lines//
        //
//        ofLine(particles[i].pos.x, particles[i].pos.y, particles[i-1].pos.x, particles[i-1].pos.y);
        
        particles[i].draw(fader2);
    }
    
    
    
}

//--------------------------------------------------------------

void testApp::checkOsc(){
    
    while (mReceiver.hasWaitingMessages() ) {
        ofxOscMessage  m;
        mReceiver.getNextMessage(&m);
        
        string addr = m.getAddress();
        //Faders
        if(addr == "/1/fader1"){
            
             fader1 = m.getArgAsFloat(0);
            fader1Value = ofMap(fader1, 0, 1, 0, ofGetWindowWidth());
            ballPos.set(fader1Value,ofGetWindowHeight()/2);
//            cout << fader1 << endl;
        }
        if(addr == "/1/fader2"){
            
            fader2 = m.getArgAsFloat(0);
            fader2Value = ofMap(fader2, 0, 1, 0.03, 0.5);
            
            
        }
        if(addr == "/1/fader3"){
            
            fader3 = m.getArgAsFloat(0);
        }
        //Rotary Knobs
        if(addr == "/1/rotary1"){
            
            rotary1 = m.getArgAsFloat(0);
            cout << rotary1 << endl;
            
            
        }
        if(addr == "/1/rotary2"){
            
            rotary2 = m.getArgAsFloat(0);
            
        }
        if(addr == "/1/rotary3"){
            
            rotary3 = m.getArgAsFloat(0);
            
        }
        if(addr == "/1/push1"){
            
            push1 = m.getArgAsFloat(0);
            if (push1 == 1) {
                push = true;
                // SPLODE
                if( push ==true){
                    for (int i = 0; i < particles.size(); i++){
                        
                        
                        particles[i].resetForce();
                        particles[i].addRepulsion(ballPos.x, ballPos.y, 50, 65);
                        particles[i].addDamping();
                        particles[i].update();
                    }
                }

            }else{
            push = false;
            }
        }



        
        //Button "Push"
        if(addr == "/2/xyz"){
            float accX = m.getArgAsFloat(0);
            float accY = m.getArgAsFloat(1);
            float accZ = m.getArgAsFloat(2);
            
            cout << accX << endl;
            
            
        }
        
//        else if(addr == "/1/fader1"){
//            float xPos = m.getArgAsFloat(0);
//            int yPos = 1;//m.getArgAsInt32(1);
//            
//            ballPos.set(xPos, yPos);
//        }
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
//    for (int i = 0; i < particles.size(); i++){
//        particles[i].resetForce();
//        particles[i].addRepulsion(x, y, 50, 80);
//        particles[i].addDamping();
//        particles[i].update();
//    }

    
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
