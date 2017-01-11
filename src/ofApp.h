#pragma once

#include "ofMain.h"
#include "seed.hpp"
#include "ofxBox2d.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{
    
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
    
    
    void initiateSeeds( int number);
    void drawDandelion();
    void drawSeed();
    void addSeeds(int number,int idSeed);
    
    bool debug;
    int press;
    float angle = 0;
    
    
    int rDandelionBulb;
    int rSeedPosition;
    int rSeedDandelion;
    int numberOfSeeds;
    int intervalleSeedRotation;
    
    ofVec2f startPoint;
    ofVec2f positionDandelion;
    ofVec2f positionSeed;
    
    
    ofVec2f force;
    ofVec2f wind;
    ofVec2f gravity;
    int count;
    int countSeed = 0;
    bool isInitiate = false;
    
    vector<seed> seeds;
    //seed seed;
    
    //GUI PANEL
    ofxFloatSlider forceSlider;
    ofxPanel gui;
    
    
};
