//
//  seed.cpp
//  01-DandelionInterface
//
//  Created by Joelle Aeschlimann on 04.01.17.
//
//

#include "seed.hpp"

seed::seed(){
    drawImage = false;
    imageSeed.load("dandelion_seed.png");
    setInitialCondition(0,0,0,0);
    damping = 0.00f;
        
}

void seed::setup(){
}


void seed::setInitialCondition(float _px, float _py, float _vx, float _vy){
   pos.set(_px,_py);
   vel.set(_vx,_vy);


}

void seed::setParameter(int _radius, ofVec2f _startPoint, int _angle){
    rad = _radius;
    startPoint = _startPoint;
    angle = _angle;
}

void seed::draw(){
    
   
    int imageSize = 60;
    
    ofPushMatrix();
        ofTranslate(startPoint.x, startPoint.y );
        //ofRotate(angle);
            ofPushStyle();
                circleColor = 220;
                ofSetColor(circleColor);
                //ofDrawCircle(pos.x,pos.y,rad);
            ofPopStyle();
            ofPushStyle();
                ofSetColor(255, 0, 0);
                ofTranslate(pos.x, pos.y);
                ofRotate(angle+aRotationSeed);
    
                ofDrawLine(0,-rad,0,rad);
            ofPopStyle();
    ofPopMatrix();
    
    
    
    ofPushMatrix();
        ofSetColor(255);
        ofTranslate(startPoint.x, startPoint.y);
        imageSeed.setAnchorPoint(imageSize/2, imageSize/2);
        ofTranslate(pos.x, pos.y);
        ofRotate(angle+aRotationSeed);
        if(drawImage) imageSeed.draw(0, 0, imageSize, imageSize);
    

    ofPopMatrix();
    
    ofSetColor(0, 255, 0);
    ofDrawRectangle(startPoint.x+ pos.x,startPoint.y+pos.y,2,2);
  
}


void seed::resetForce(){
    // we reset the forces every frame
    frc.set(0,0);
}

void seed::addForce(float x, float y){
    // add in a force in X and Y for this frame.
    frc.x = frc.x + x;
    frc.y = frc.y + y;
}
void seed::addDampingForce(){
    
    // the usual way to write this is  vel *= 0.99
    // basically, subtract some part of the velocity
    // damping is a force operating in the oposite direction of the
    // velocity vector
    
    frc.x = frc.x - vel.x * damping;
    frc.y = frc.y - vel.y * damping;
}


void seed::update(){
    
    
    aRotationSeed += aVel;
    aVel += aAcc;
    vel = vel + frc;
    pos = pos + vel;
    
    detectPositionInScreen();
   
}


void seed::detectPositionInScreen(){
    
    ofVec2f actualPos = startPoint + pos ;
    //cout<<actualPos<<endl;
    if((actualPos.x >=1900)||(actualPos.x<=20)){
   
    cout<<"y0ooos"<<endl;
        kill = true;
    
    }
    
    if((actualPos.y >=1000)||(actualPos.y<=20)){
        
        kill = true;
    }


}


