#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofSetCircleResolution(100);
    
    //gravity.set(0,0);
    //force.set(ofRandom(-1,2), ofRandom(-1,2));
    
    debug = false;
    press = 0;
    isInitiate = true;
    ofBackground(0);
    startPoint.set( ofGetWidth()/2,ofGetHeight()/2);
    
    
    rDandelionBulb = 50;
    rSeedPosition = 50;
    rSeedDandelion = 10;
    numberOfSeeds = 20;
    
    
    positionDandelion.set(startPoint.x,startPoint.y);
    
    //addSeeds(numberOfSeeds);
    
    
}


//--------------------------------------------------------------
void ofApp::update(){
    
    
    if(isInitiate) initiateSeeds(numberOfSeeds);
    
   
    
    
    for (int i = 0; i < seeds.size(); i++){
        seeds[i].resetForce();
        seeds[i].addForce(gravity.x,gravity.y);
        seeds[i].addForce(force.x,force.y);
        seeds[i].addDampingForce();
        
        seeds[i].update();
        seeds[i].startPoint = startPoint;
        
        if(seeds[i].kill == true) {
            seeds.erase(seeds.begin() + i);
            
        }
        
    }
    
    
    
    // Check if il n'y a pas trop de seeds, si oui en ajoute tout les 500frs
    if(seeds.size()<2*numberOfSeeds) count ++;
    if(count == 500){
        countSeed = 0;
        isInitiate = true;
        count=0;
    }
    
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    if(debug){
        ofBackground(196);
        ofSetColor(100);
        ofDrawCircle(startPoint.x, startPoint.y, 10);
        ofSetColor(0);
        ofDrawBitmapString("Debug Mode", 10, 20);
    }else{
        ofBackground(0);
        ofDrawCircle(startPoint.x, startPoint.y, 2);
    }
    
    drawSeed();
    drawDandelion();
    
    
}

/*void ofApp::incrementNumberofSeed(){
 int increment = 10;
 
 cout<<ofGetFrameRate()<<endl;
 if(int(ofGetFrameRate()) % increment ==0){
 cout<<"yo"<<(int(ofGetFrameRate()) % increment)<<endl;
 
 }
 
 }*/
void ofApp::initiateSeeds(int number){
    
    if(countSeed<number){
        
        addSeeds(1,countSeed);
        countSeed ++;
    }else{
        isInitiate = false;
        cout<<"return"<<endl;
        return;
    }
}

void ofApp::addSeeds(int number, int idSeed){
    intervalleSeedRotation = (2*PI*rDandelionBulb)/numberOfSeeds;
    positionSeed.set(startPoint.x,startPoint.y);
    
    
    for (int i = 0; i < number; i++){
        seed seed;
        //seed.damping = ofRandom(0.01, 0.05);
        gravity.set(0,0);
        force.set(0,0);
        wind.set(0,0);
        
        
        angle=idSeed*intervalleSeedRotation;
        positionSeed.x = (rSeedPosition+rSeedDandelion) * cos(ofDegToRad(90+angle));
        positionSeed.y = (rSeedPosition+rSeedDandelion) * sin(ofDegToRad(90+angle));
        
        
        seed.setParameter(rSeedDandelion, startPoint,angle);
        seed.setInitialCondition(positionSeed.x, positionSeed.y, 0,0 );
        //seed.setInitialCondition(positionSeed.x, positionSeed.y, rSeedDandelion,0.1,0.1);
        seeds.push_back(seed);
        
    }
    
    
}



void ofApp::drawDandelion(){
    
    //drawDandelion
    
    int widthStemDandelion = 4;
    positionDandelion.set(startPoint.x,startPoint.y);
    
    ofSetColor(190);
    ofDrawCircle(positionDandelion.x, positionDandelion.y, rDandelionBulb);
    if(debug)ofDrawRectangle(positionDandelion.x-widthStemDandelion/2, positionDandelion.y, widthStemDandelion , ofGetHeight()/2);
}

void ofApp::drawSeed(){
    //drawSeed
    for (int i = 0; i < seeds.size(); i++){
        seeds[i].draw();
        
    }
    
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch(key){
        case ' ':
            if (press<1){
                press++;
                debug = true;
                
            }else {
                debug = false;
                press = 0;
                
            }
            break;
        case 'k':
            seeds.clear();
            
            break;
        case 'j':
            countSeed = 0;
            isInitiate = true;
            break;
        case 'g':
            gravity.set(0,ofRandom(0.1,0.04));
            
            
            break;
            
    }
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    if(debug) startPoint.set(ofGetMouseX(),ofGetMouseY());
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    
    
    wind.set(2,-4);
    for (int i = 0; i < seeds.size(); i++){
        
        
        force.set(ofRandom(-0.1,0.1), ofRandom(-0.1,0.1));
        
        seeds[i].resetForce();
        seeds[i].addForce(force.x, force.y);
        //seeds[i].addForce(0,ofRandom(0.1,0.04));
        seeds[i].addForce(wind.x,wind.y);
        seeds[i].addDampingForce();
        seeds[i].aAcc = 0.01;
        seeds[i].update();
        
        
    }
    
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    
    
}

