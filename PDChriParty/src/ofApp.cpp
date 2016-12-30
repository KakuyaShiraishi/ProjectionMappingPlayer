#include "ofApp.h"
#include "stdio.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //ofSetDataPathRoot("../Resources/data/");
    ofEnableAlphaBlending();
    ofBackground(0);
    
    image.load("sources/pd0.5.png");
    imageleft.load("sources/left.png");
    imageright.load("sources/right.png");
    Limage.load("sources/L.png");
    Rimage.load("sources/R.png");
    playbu.load("sources/play.png");
    pausebu.load("sources/pause.png");
    
    ofxTrueTypeFontUC::setGlobalDpi(400);
    fontXS.load("sources/AxisStd-ExtraLight.otf",ofGetHeight()/245.0,true,true,true); //5
    fontS.load("sources/AxisStd-ExtraLight.otf",ofGetHeight()/150.0,true,true,true); //8
    fontM.load("sources/AxisStd-ExtraLight.otf",ofGetHeight()/110.0,true,true,true); //10
    fontM1.load("sources/AxisStd-ExtraLight.otf",ofGetHeight()/160.0,true,true,true); //7
    
    video1.load("sources/black.mp4");
    
    
    now = false;
    ofHideCursor();
    
    button = false;
    
    
    video1load = true;
    video2load = false;
    gridload = false;
    
    
    increment = 0.04f;
    decrement = -0.04f;
    alphaBlend1 = 0.0;
    alphaBlend2 = 1.0;
    alphaBlend3 = 0.0;
    alphaBlend4 = 1.0;
    
    movieswitch1 = false;
    movieswitch2 = false;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    video1.update();
    alphaBlend1 += increment;
    if (alphaBlend1>1.0) {
        alphaBlend1=1.0;
    }
    if(movieswitch1 == true){
        alphaBlend2 += decrement;
        if (alphaBlend2<0.0){
            video1.closeMovie();
            movieswitch1 = false;
            alphaBlend1 = 0.0;
            alphaBlend2 = 1.0;
        }
    }
    
    video2.update();
    alphaBlend3 += increment;
    if (alphaBlend3>1.0) {
        alphaBlend3=1.0;
    }
    if(movieswitch2 == true){
        alphaBlend4 += decrement;
        if (alphaBlend4<0.0){
            video2.closeMovie();
            movieswitch2 = false;
            alphaBlend3 = 0.0;
            alphaBlend4 = 1.0;
        }
    }
    
    if(gridload == true){
        grid.update();
    }
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(255*alphaBlend1*alphaBlend2);
    video1.draw(x,y,1280+1280,1024);
    
    ofSetColor(255*alphaBlend3*alphaBlend4);
    video2.draw(x-300,y,1280+1280,1024);
    
    
    ofSetColor(255);
    if(gridload == true){
        grid.draw(x,y,1280+1280,1024);
    }else if(gridload == false){
        grid.closeMovie();
    }
    
    
    
    ofSetColor(255);
    image.draw((ofGetWidth()/10)*4.5,(ofGetHeight()/10)*1.5,ofGetWidth()/2,ofGetWidth()/2); //プロダクトクリスマスデザインん
    
    imageleft.draw((ofGetWidth()/10)*0.5,(ofGetHeight()/10)*7.5,ofGetHeight()/1.12/*1074*/,ofGetHeight()/5.46/*220*/); //左用
    //imageright.draw((ofGetWidth()/10)*0.5,(ofGetHeight()/10)*7.5,ofGetHeight()/1.12/*1074*/,ofGetHeight()/5.46/*220*/); //右用
    Limage.draw((ofGetWidth()/10)*9,(ofGetHeight()/100)*5,ofGetHeight()/10,ofGetHeight()/6.66); //左用
    //Rimage.draw((ofGetWidth()/10)*9,(ofGetHeight()/100)*5,ofGetHeight()/10,ofGetHeight()/6.66); //右用
    
    
    
    

        ofSetColor(255*alphaBlend1*alphaBlend2);
        video1.draw((ofGetWidth()/10)*0.574,(ofGetHeight()/10)*7.6,ofGetHeight()/2.35,ofGetHeight()/6.15); //左用
        //video1.draw((ofGetWidth()/10)*3.346,(ofGetHeight()/10)*7.6,ofGetHeight()/2.35,ofGetHeight()/6.15); //右用

        ofSetColor(255*alphaBlend3*alphaBlend4);
        video2.draw((ofGetWidth()/10)*0.574,(ofGetHeight()/10)*7.6,ofGetHeight()/2.35,ofGetHeight()/6.15); //左用
        //video2.draw((ofGetWidth()/10)*3.346,(ofGetHeight()/10)*7.6,ofGetHeight()/2.35,ofGetHeight()/6.15); //右用

    if(gridload == true){
        grid.draw((ofGetWidth()/10)*0.574,(ofGetHeight()/10)*7.6,ofGetHeight()/2.35,ofGetHeight()/6.15);
        //grid.draw((ofGetWidth()/10)*3.346,(ofGetHeight()/10)*7.6,ofGetHeight()/2.35,ofGetHeight()/6.15);
    }else if(gridload == false){
        grid.closeMovie();
    }
    
    
    
    ofSetColor(255);
    fontM.drawString("プロジェクションマッピング用アプリ(左２画面用)", (ofGetWidth()/50),(ofGetHeight()/20)*2.3); //左用
    //fontM.drawString("プロジェクションマッピング用アプリ(右２画面用)", (ofGetWidth()/50),(ofGetHeight()/20)*2.5); //右用
    fontM1.drawString("   　　 　　　　　　プロダクトデザイン学科特別仕様版", (ofGetWidth()/50),(ofGetHeight()/20)*3.5);
    
    fontXS.drawString("※終了はescキー",((ofGetWidth()/50)*5),((ofGetHeight()/40)*1.3));
    
    fontS.drawString("操作方法", ((ofGetWidth()/50)*4),((ofGetHeight()/40)*8.5));
    fontXS.drawString("スペース：再生、一時停止",((ofGetWidth()/50)*6),((ofGetHeight()/40)*10));
    fontXS.drawString("←↑→↓：映像の位置調節",((ofGetWidth()/50)*6),((ofGetHeight()/40)*11.3));
    fontXS.drawString("　　　ｒ：位置リセット",((ofGetWidth()/50)*6),((ofGetHeight()/40)*12.6));
    fontXS.drawString("　　　１：魔法の粉１",((ofGetWidth()/50)*6),((ofGetHeight()/40)*14.3));
    fontXS.drawString("　　　２：街[橋本](リピート)",((ofGetWidth()/50)*6),((ofGetHeight()/40)*15.6));
    fontXS.drawString("　　　３：魔法の粉２",((ofGetWidth()/50)*6),((ofGetHeight()/40)*16.9));
    fontXS.drawString("　　　４：街[ヨーロッパ](リピート)",((ofGetWidth()/50)*6),((ofGetHeight()/40)*18.2));
    fontXS.drawString("　　　５：ゲーム１(リピート)",((ofGetWidth()/50)*6),((ofGetHeight()/40)*19.5));
    fontXS.drawString("　　　６：ゲーム２(リピート)",((ofGetWidth()/50)*6),((ofGetHeight()/40)*20.8));
    fontXS.drawString("　　　７：ゲーム３(リピート)",((ofGetWidth()/50)*6),((ofGetHeight()/40)*22.1));
    fontXS.drawString("　　　８：ゲーム４(リピート)",((ofGetWidth()/50)*6),((ofGetHeight()/40)*23.4));
    fontXS.drawString("　　　９：待機画面(ブラックスクリーン)",((ofGetWidth()/50)*6),((ofGetHeight()/40)*25.1));
    fontXS.drawString("　　　０：設置用グリッド表示",((ofGetWidth()/50)*6),((ofGetHeight()/40)*26.4));
    
    fontS.drawString("プレビュー", ((ofGetWidth()/50)*2),((ofGetHeight()/20)*14.8));
    
    if(button == false){
        playbu.draw(((ofGetWidth()/50)*9),((ofGetHeight()/20)*16.4),50,50); //左用
        //playbu.draw(((ofGetWidth()/50)*23.3),((ofGetHeight()/20)*16.4),50,50); //右用
    }else if(button == true){
        pausebu.draw(((ofGetWidth()/50)*9),((ofGetHeight()/20)*16.4),50,50); //左用
        //pausebu.draw(((ofGetWidth()/50)*23.3),((ofGetHeight()/20)*16.4),50,50); //右用
    }
    
    ofDrawBitmapString(ofToString(ofGetYear())+"/"+ofToString(ofGetMonth())+"/"+ofToString(ofGetDay())+" "+ofToString(ofGetHours())+":"+ofToString(ofGetMinutes())+":"+ofToString(ofGetSeconds()), 10, 15);
    ofDrawBitmapString(ofToString(ofGetWidth())+" x "+ofToString(ofGetHeight()), 10, 30);
    ofDrawBitmapString(ofToString(ofGetFrameRate())+"fps", 10, 45);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(now==false){
        if (key == ' '){
            button = true;
            if(video1load == true && video2load == false){
                video1.play();
            }else if(video1load == false && video2load == true){
                video2.play();
            }
            now = true;
        }
    }else if(now==true){
        if (key == ' '){
            button = false;
            if(video1load == true && video2load == false){
                video1.setPaused(true);
            }else if(video1load == false && video2load == true){
                video2.setPaused(true);
            }
            now = false;
        }
    }
    
    
    switch(key){
        case OF_KEY_UP:
            y -= 1;
            break;
        case OF_KEY_DOWN:
            y += 1;
            break;
        case OF_KEY_RIGHT:
            x += 1;
            break;
        case OF_KEY_LEFT:
            x -= 1;
            break;
            
        case '1':
            gridload = false;


            if(video1load == true && video2load == false){
                alphaBlend1 = 0.0;
                movieswitch1 = true;
                video2.load("movie/01.mp4");
                video2.play();
                video2.setLoopState(OF_LOOP_NONE);
                video1load = false;
                video2load = true;
            }else if(video1load == false && video2load == true){
                alphaBlend3 = 0.0;
                movieswitch2 = true;
                video1.load("movie/01.mp4");
                video1.play();
                video1.setLoopState(OF_LOOP_NONE);
                video1load = true;
                video2load = false;
            }
            button = true;
            now = true;
            break;
        case '2':
            gridload = false;
            if(video1load == true && video2load == false){
                alphaBlend1 = 0.0;
                movieswitch1 = true;
                video2.load("movie/02.mp4");
                video2.play();
                video2.setLoopState(OF_LOOP_NORMAL);
                video1load = false;
                video2load = true;
            }else if(video1load == false && video2load == true){
                alphaBlend3 = 0.0;
                movieswitch2 = true;
                video1.load("movie/02.mp4");
                video1.play();
                video1.setLoopState(OF_LOOP_NORMAL);
                video1load = true;
                video2load = false;
            }
            button = true;
            now = true;
            break;
        case '3':
            gridload = false;
            alphaBlend1 = 0.0;
            if(video1load == true && video2load == false){
                video1.closeMovie();
                video2.load("movie/03.mp4");
                video2.play();
                video2.setLoopState(OF_LOOP_NONE);
                video1load = false;
                video2load = true;
            }else if(video1load == false && video2load == true){
                video2.closeMovie();
                video1.load("movie/03.mp4");
                video1.play();
                video1.setLoopState(OF_LOOP_NONE);
                video1load = true;
                video2load = false;
            }
            button = true;
            now = true;
            break;
        case '4':
            gridload = false;
            alphaBlend1 = 0.0;
            if(video1load == true && video2load == false){
                video1.closeMovie();
                video2.load("movie/04.mp4");
                video2.play();
                video2.setLoopState(OF_LOOP_NORMAL);
                video1load = false;
                video2load = true;
            }else if(video1load == false && video2load == true){
                video2.closeMovie();
                video1.load("movie/04.mp4");
                video1.play();
                video1.setLoopState(OF_LOOP_NORMAL);
                video1load = true;
                video2load = false;
            }
            button = true;
            now = true;
            break;
        case '5':
            gridload = false;
            alphaBlend1 = 0.0;
            if(video1load == true && video2load == false){
                video1.closeMovie();
                video2.load("movie/05.mp4");
                video2.play();
                video2.setLoopState(OF_LOOP_NORMAL);
                video1load = false;
                video2load = true;
            }else if(video1load == false && video2load == true){
                video2.closeMovie();
                video1.load("movie/05.mp4");
                video1.play();
                video1.setLoopState(OF_LOOP_NORMAL);
                video1load = true;
                video2load = false;
            }
            button = true;
            now = true;
            break;
        case '6':
            gridload = false;
            alphaBlend1 = 0.0;
            if(video1load == true && video2load == false){
                video1.closeMovie();
                video2.load("movie/06.mp4");
                video2.play();
                video2.setLoopState(OF_LOOP_NORMAL);
                video1load = false;
                video2load = true;
            }else if(video1load == false && video2load == true){
                video2.closeMovie();
                video1.load("movie/06.mp4");
                video1.play();
                video1.setLoopState(OF_LOOP_NORMAL);
                video1load = true;
                video2load = false;
            }
            button = true;
            now = true;
            break;
        case '7':
            gridload = false;
            alphaBlend1 = 0.0;
            if(video1load == true && video2load == false){
                video1.closeMovie();
                video2.load("movie/07.mp4");
                video2.play();
                video2.setLoopState(OF_LOOP_NORMAL);
                video1load = false;
                video2load = true;
            }else if(video1load == false && video2load == true){
                video2.closeMovie();
                video1.load("movie/07.mp4");
                video1.play();
                video1.setLoopState(OF_LOOP_NORMAL);
                video1load = true;
                video2load = false;
            }
            button = true;
            now = true;
            break;
        case '8':
            gridload = false;
            alphaBlend1 = 0.0;
            if(video1load == true && video2load == false){
                video1.closeMovie();
                video2.load("movie/08.mp4");
                video2.play();
                video2.setLoopState(OF_LOOP_NORMAL);
                video1load = false;
                video2load = true;
            }else if(video1load == false && video2load == true){
                video2.closeMovie();
                video1.load("movie/08.mp4");
                video1.play();
                video1.setLoopState(OF_LOOP_NORMAL);
                video1load = true;
                video2load = false;
            }
            button = true;
            now = true;
            break;
        case '9':
            gridload = false;
            alphaBlend1 = 0.0;
            video1.closeMovie();
            video2.closeMovie();
            video1load = true;
            video2load = false;
            button = false;
            now = false;
            break;
        case '0':
            alphaBlend1 = 0.0;
            video1.closeMovie();
            video2.closeMovie();
            video1load = true;
            video2load = false;
            grid.load("sources/grid.mp4");
            grid.play();
            grid.setLoopState(OF_LOOP_NORMAL);
            gridload = true;
            button = true;
            now = true;
            break;
        case 'r':
            x = 1440;
            y = 0;
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
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
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
