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
    
    particleCount = 200;
    
    w = ofGetWindowWidth();
    h = ofGetWindowHeight();
    
    
    for (int i = 0; i < particleCount; i++){
        Particle myParticle;
        myParticle.setInitCondition(ofRandom(ofGetWindowWidth()), ofRandom(0,ofGetWindowHeight()+20), 0, 0);
        myParticle.damping = ofRandom(0.01,0.05);
        particles.push_back(myParticle);
    }
    ship.loadImage("ship.png");
    ship.rotate90(1);
    ship.setAnchorPoint(20, 25);
    
    particleAlpha = ofRandom(40,110);
    
    particleR = 255;
    
}

//--------------------------------------------------------------
void testApp::update(){
    checkOsc();
    
    ballPos.set(fader1Value*ofGetWindowWidth(),ofGetWindowHeight()/2);
    
    for (int i = 0; i < particleCount; i++){
        particles[i].resetForce();
        particles[i].addAttraction(ballPos.x, ballPos.y, 1000, fader2Value);
        particles[i].addRepulsion(ballPos.x, ballPos.y, 30, 35);
        particles[i].addRepulsion(shipPos.x, shipPos.y, 30, 35);

        particles[i].addDamping();
        particles[i].update();
        
        if(particles[i].pos.x < 0){
            particles[i].pos.x = ofGetWindowWidth()+2;
            particles[i].pos.y = ofRandom(ofGetWindowHeight());
        }
        
        // Have particles trail one another
//        if (i == 0){
//            particles[i].trail(ballPos.x, ballPos.y);
//        }else{
//            particles[i].trail(particles[i-1].pos.x, particles[i-1].pos.y);
//        }
    }
    
    counter = counter + 0.0013f;
}
//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(255);
    ofCircle(ballPos, 20);

   ofColor crazyColor = ofColor(particleR,255,255,255);
    
    // Why is one line thicker?
    
    for (int i = 1; i < particles.size()-1; i++){
        //Lines//
        //
        ofLine(particles[i].pos.x, particles[i].pos.y, particles[i-1].pos.x, particles[i-1].pos.y);
        
        //check size of particles
        if (particles[i].size == 2){
            
        }
        
        particles[i].draw(fader2, crazyColor);
    }
    
 
//    particles[0].draw(fader2, crazyColor);
    ofSetColor(255);
    
    shipPos.x = 20+ 500* sin(counter);
    if (shipPos.x < -60) {
        shipPos.x *= -1;
    }
    shipPos.y = ofGetWindowHeight()/2;
        
    ship.draw(shipPos.x,shipPos.y, ship.getWidth()/5, ship.getWidth()/5);

    
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
            fader1Value = ofMap(fader1, 0, 127, 0, 1);
        }
        if(addr == "/1/fader2"){
            
            fader2 = m.getArgAsFloat(0);
            fader2Value = ofMap(fader2, 0, 127, 0.03, 0.5);
        }
        if(addr == "/1/fader3"){
            
            fader3 = m.getArgAsFloat(0);
            fader3Value = ofMap(fader3, 0, 127, 0, 100);
        }
        //Rotary Knobs
        if(addr == "/1/rotary1"){
            
            rotary1 = m.getArgAsFloat(0);
        
            
        }
        if(addr == "/1/rotary2"){
            
            rotary2 = m.getArgAsFloat(0);
            
        }
        if(addr == "/1/rotary3"){
            
            rotary3 = m.getArgAsFloat(0);
            
            
        }
        if(addr == "/1/push1"){
            
            push1 = m.getArgAsFloat(0);
            if (push1 == 127) {
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
    if (key == '1') {
        particleR = 0;
    }
    
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
