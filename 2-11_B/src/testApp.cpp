#include "testApp.h"
#define NUM 1000 //円の数を表す定数NUMを1000と定義

float loc_x[NUM]; //円のx座標
float loc_y[NUM]; //円のy座標
float speed_x[NUM]; //x軸方向のスピード
float speed_y[NUM]; //y軸方向のスピード
float radius[NUM]; //円の半径
int red[NUM]; //Red成分
int green[NUM]; //Green成分
int blue[NUM]; //Blue成分
bool mouse_pressed; //マウスはクリックされているか?
float gravity;
float friction;

//--------------------------------------------------------------
void testApp::setup(){
    ofSetBackgroundAuto(false);
    ofBackground(0, 0, 0); //背景色の設定
    ofSetFrameRate(60); //フレームレートの設定
    ofSetCircleResolution(64); //円の解像度設定
    ofEnableAlphaBlending(); //アルファチャンネルを有効に
    mouse_pressed = false; //マウス状態を「クリックされていない」に
    gravity = 0.1; //重力
    friction = 0.999;
    
    
    //NUMの数だけ初期値の生成を繰り返す
    for(int i = 0; i < NUM; i++){
        loc_x[i] = ofGetWidth() / 2; //円のx座標初期位置
        loc_y[i] = ofGetHeight() / 2; //円のy座標初期位置
        speed_x[i] = ofRandom(-10, 10); //x軸方向スピード初期値
        speed_y[i] = ofRandom(-10, 10); //y軸方向スピード初期値
        radius[i] = ofRandom(1, 10); //円の半径を設定
        red[i] = ofRandom(0, 255); //Red成分を設定
        green[i] = ofRandom(0, 255); //Green成分を設定
        blue[i] = ofRandom(0, 255); //Blue成分を設定
    }
}

//--------------------------------------------------------------
void testApp::update(){
    //NUMの数だけ座標の更新を繰り返す
    for(int i = 0; i < NUM; i++){
        
        //マウスの現在位置からスピードを//もしマウスがクリックされていたらマウスに集ってくる
        if(mouse_pressed){
            //マウスの現在位置から円のスピードを再計算
            speed_x[i] = (mouseX - loc_x[i]) / 8.0; //マウスのx座標と円のx座標の距離の1/8だけ接近
            speed_y[i] = (mouseY - loc_y[i]) / 8.0;
        }
        
        speed_x[i] = speed_x[i] * friction;
        speed_y[i] = speed_y[i] * friction;
        speed_y[i] = speed_y[i] + gravity;
        
        loc_x[i] = loc_x[i] + speed_x[i]; //円のx座標を更新
        loc_y[i] = loc_y[i] + speed_y[i]; //円のy座標を更新
        
        //円の跳ね返り条件
        if(loc_x[i] < 0){
            loc_x[i] = 0;
            speed_x[i] = speed_x[i] * -1.0;
        }
        if(loc_x[i] > ofGetWidth()){
            loc_x[i] = ofGetWidth();
            speed_x[i] = speed_x[i] * -1.0;
        }
        if(loc_y[i] < 0){
            loc_y[i] = 0;
            speed_y[i] = speed_y[i] * -1.0;
        }
        if(loc_y[i] > ofGetHeight()){
            loc_y[i] = ofGetHeight();
            speed_y[i] = speed_y[i] * -1.0;
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    //全画面を半透明の黒でフェード
    ofSetColor(0, 0, 0, 23);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    
    //NUMの数だけ円を描画する
    for(int i = 0; i < NUM; i++){
        ofSetColor(red[i], green[i], blue[i], 127); //描画色の設定
        ofCircle(loc_x[i], loc_y[i], radius[i]); //円1を描画
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    mouse_pressed = true; //マウスが押されている状態に
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    mouse_pressed = false; //マウスが押されていない状態に
    
    //円のスピードを再初期化
    for(int i = 0; i < NUM; i++){
        speed_x[i] = ofRandom(-10, 10); //x軸方向スピード初期値
        speed_y[i] = ofRandom(-10, 10); //y軸方向スピード初期値
    }
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

