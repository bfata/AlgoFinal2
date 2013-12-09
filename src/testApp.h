#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "Particle.h"
#include "ofxFX.h"

class testApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    
    void checkOsc();
    
    ofVec2f mousePos;
    ofVec2f ballPos;
    ofxOscReceiver mReceiver;
    
    vector<Particle> particles;
    
    float fader1, fader2, fader3;
    float accX, accY, accZ;
};
