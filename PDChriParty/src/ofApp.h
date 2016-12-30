#pragma once

#include "ofMain.h"
#include "ofxTrueTypeFontUC.h"

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
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
private:
    ofVideoPlayer video1;
    ofVideoPlayer video2;
    ofVideoPlayer grid;
    
    bool now;
    bool button;
    
    ofImage image;
    ofImage imageleft;
    ofImage imageright;
    ofImage Limage;
    ofImage Rimage;
    ofImage playbu;
    ofImage pausebu;
    
    ofxTrueTypeFontUC fontXS;
    ofxTrueTypeFontUC fontS;
    ofxTrueTypeFontUC fontM;
    ofxTrueTypeFontUC fontM1;
    
    float x = 1440;
    float y = 0;
    
    ofFbo fbo;
    
    bool video1load;
    bool video2load;
    bool gridload;
    
    bool movieswitch1;
    bool movieswitch2;
    
    float increment;
    float decrement;
    float alphaBlend1;
    float alphaBlend2;
    float alphaBlend3;
    float alphaBlend4;
};
