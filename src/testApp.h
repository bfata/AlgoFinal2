#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "Particle.h"
#include "ofxFX.h"
#include "ofxFluid.h"
#include "ofxFft.h"

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
    ofVec2f ballPos, shipPos;
    ofxOscReceiver mReceiver;
    
    vector<Particle> particles;
    
    float particleCount;
    
    float fader1, fader2, fader3, fader1Value, fader2Value, fader3Value;
    float rotary1, rotary2, rotary3, rotary1Value, rotary2Value, rotary3Value;
    float push1, push2, push3;
    float counter;
    
    int particleR, particleG, particleB, particleAlpha;
    int w, h;
    
    bool push, drawLines;
    
    ofImage ship;
};
