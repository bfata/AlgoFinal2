//
//  Particle.h
//  wk6_attractorRepulsor
//
//  Created by TheAlkimist on 10/5/13.
//  Modified by BFata in an attempt to make it more awesome
//

#include "ofMain.h"

class Particle{
public:
    
    Particle();     // particle constructor
    virtual ~Particle(){};
    
    ofVec2f pos;    // vector position
    ofVec2f vel;    // vector velocity
    ofVec2f force;    // vector force
    
    void resetForce();
    void addDamping();                      // damping
    void setInitCondition(float px, float py, float vx, float vy);  // starting force
    void update();
    void draw(float fader2, ofColor particleColor);
    
    void addRepulsion(float px, float py, float radius, float strength);
    void addAttraction( float px, float py, float radius, float strength);
    void addClockwise( float px, float py, float radius, float strength);
    void addCounterClockwise( float px, float py, float radius, float strength);
    void trail(float catchX, float catchY);
    
    float damping;
    float size;
    
    int r, g, b, a;
    float dist;
    
    ofColor particleColor;
    
    
};
