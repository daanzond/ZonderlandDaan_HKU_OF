#include "ofApp.h"
#include "Ball.h"

Ball ball;
ofSoundPlayer lose;
ofSoundPlayer boink;
ofSoundPlayer boinks;
ofSoundPlayer down;

//--------------------------------------------------------------
void ofApp::setup() {
        ball.setup();
        player.setup();
        keyup = false;
        keydown = false;
        score = 0;
    
    lose.loadSound("gameover.mp3");
    boink.loadSound("boink.wav");
    boinks.loadSound("boinks.wav");
    down.loadSound("down.wav");
}

//--------------------------------------------------------------
void ofApp::update() {
    
    //movement paddle
    
        if (keyup)
        player.moveup();
        else if (keydown)
        player.movedown();
    
    if (!butwhatifballwaskill)
        lose.play();
        ball.update();
    
    
    //collision detection
    
    
    if((ball.x - ball.radius - player.x - player.width) <= 0)
    {
        
        if (std::abs(ball.y - player.y) < (player.height/2)) //als het verschil tussen de y posities van de ball en paddle kleiner is dan de helft van de hoogte van de paddle
            
        {
            score++;
            //win
            ball.speedX *= -1.1;
            boink.play();
            
        }
        else
        {
            butwhatifballwaskill = true;
            //dood
        }
        
    }
    
}

//--------------------------------------------------------------
void ofApp::draw() {
    if (!butwhatifballwaskill)
        ball.draw();
    
    player.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
        if (key == 'w')
        {
            keyup = true;
        }
    else if (key == 's')
    {
        keydown = true;
    }
    else if (key == OF_KEY_RETURN && butwhatifballwaskill)
    {
        ball.setup();
        butwhatifballwaskill = false;
        
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
    if (key == 'w')
    {
        keyup = false;
    }
    else if (key == 's')
    {
        keydown = false;
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
