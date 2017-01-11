//
//  seed.hpp
//  01-DandelionInterface
//
//  Created by Joelle Aeschlimann on 04.01.17.
//
//

#ifndef seed_hpp
#define seed_hpp

#include "ofMain.h"

class seed {
    public :
    seed();
    void setup();
    void draw();
    void update();
    
    
    void resetForce();
    void addForce(float x, float y);
    void addDampingForce();
    void setInitialCondition(float px, float py,float vx, float vy);
    void setParameter(int radius, ofVec2f startPoint, int angle);
    void detectPositionInScreen();
    void changeColor();
    
    ofColor circleColor;
    
    ofVec2f pos;

    int x = 0;
    int y = 0;
    ofVec2f vel;
    ofVec2f startPoint;
    
    
    ofVec2f gravity;
    ofVec2f wind;
    
    ofVec2f frc;
    
    
    bool kill = false;
    
    int rad;
    float damping;
    int angle;
    float aRotationSeed = 0;
    float aVel = 0.0;
    float aAcc = 0.00;
    
    bool drawImage;
    ofImage imageSeed;
    
    
    
    
};

#endif /* seed_hpp */
