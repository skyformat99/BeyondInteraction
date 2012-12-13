#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(47, 47, 47); //背景色の設定
    ofEnableAlphaBlending(); //透明度(アルファチャンネル)を有効にする
}

//--------------------------------------------------------------
void testApp::update(){
    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(242, 242, 242, 127); //描画色の設定(アルファ付き)
    ofLine(100, 300, 800, 500); //線を描く
    ofSetColor(242, 204, 47, 127); //描画色の再設定(アルファ付き)
    ofRect(200, 250, 200, 300); //四角形を描く
    ofSetColor(174, 221, 60, 127); //描画色の再設定(アルファ付き)
    ofCircle(450, 300, 150); //真円を描く
    ofSetColor(116, 193, 206, 127); //描画色の再設定(アルファ付き)
    ofEllipse(550, 500, 400, 300); //楕円を描く
    ofSetColor(211, 24, 24, 127); //描画色の再設定(アルファ付き)
    ofTriangle(700, 150, 450, 400, 750, 400); //三角形を描く
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
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}
