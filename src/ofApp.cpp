#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    for( int i = 0; i<10; i++ )
    {
        int stepSize = i * lengthSide/10;
        top.emplace_back(    lengthSide/2 - stepSize, -lengthSide/2);
        bottom.emplace_back( lengthSide/2 - stepSize,  lengthSide/2);
        right.emplace_back( -lengthSide/2,  lengthSide/2 - stepSize);
        left.emplace_back(   lengthSide/2,  lengthSide/2 - stepSize);
    }

    for( int i = 0; i<10; i++ )
    {
        double angle = i*(PI/2) / 10.0;
        topCircle.emplace_back( cos( angle ) * circleRadius, sin( angle ) * circleRadius);
        angle += PI/2;
        bottomCircle.emplace_back( cos( angle )* circleRadius, sin( angle  ) * circleRadius);
        angle += PI/2;
        rightCircle.emplace_back( cos( angle ) * circleRadius, sin( angle ) * circleRadius);
        angle += PI/2;
        leftCircle.emplace_back( cos( angle ) * circleRadius, sin( angle ) * circleRadius);
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground( ofColor::darkBlue );
    auto t = ofGetElapsedTimeMillis() / 300.0;

//    ofNoFill();

    
    // --- draw sketch
//    ofDrawCircle( ofPoint( centerSize, centerSize ), circleRadius );

//    ofPushMatrix();
//    ofTranslate( ofPoint( centerSize, centerSize ) );

//    ofRotate( t );
//    ofDrawRectangle( ofPoint ( - lengthSide/2, - lengthSide/2 ),
//                     lengthSide, lengthSide );
//    ofPopMatrix();


//    ofSetColor( ofColor::white );


    // ---
    ofSetColor( ofColor::lightBlue);
    for( int i = 0; i<10; i++ )
    {
        ofDrawLine( topCircle[i] + centerPoint, rotatePt(top[i], t) + centerPoint);
        ofDrawLine( bottomCircle[i] + centerPoint, rotatePt(bottom[i], t) + centerPoint);
        ofDrawLine( leftCircle[i] + centerPoint, rotatePt(left[i], t) + centerPoint);
        ofDrawLine( rightCircle[i] + centerPoint, rotatePt(right[i], t) + centerPoint);

//        ofDrawCircle( rotatePt(bottom[i], t) + centerPoint, smallRad);
//        ofDrawCircle( rotatePt(left[i], t) + centerPoint, smallRad);
//        ofDrawCircle( rotatePt(right[i], t) + centerPoint, smallRad);
    }

    // --- Draw Circles
    ofSetColor( ofColor::orange);
    for( int i = 0; i<10; i++ )
    {
        ofDrawCircle( rotatePt(top[i], t) + centerPoint, smallRad/2);
        ofDrawCircle( rotatePt(bottom[i], t) + centerPoint, smallRad/2);
        ofDrawCircle( rotatePt(left[i], t) + centerPoint, smallRad/2);
        ofDrawCircle( rotatePt(right[i], t) + centerPoint, smallRad/2);

        ofDrawCircle( topCircle[i] + centerPoint, smallRad);
        ofDrawCircle( bottomCircle[i] + centerPoint, smallRad);
        ofDrawCircle( leftCircle[i] + centerPoint, smallRad);
        ofDrawCircle( rightCircle[i] + centerPoint, smallRad);

    }
}

ofPoint ofApp::rotatePt( ofPoint pt, double t ) {
    
    auto newX = cos(t)*pt.x + sin(t)*pt.y;
    auto newY = -sin(t)*pt.x + cos(t)*pt.y;
    return ofPoint(newX, newY);
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
