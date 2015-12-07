#include "ofApp.h"

void ofApp::setup() {

    ofSetFrameRate(60);

    ofBackground(10,10,10);

    light.setPointLight();
    light.setPosition(500,500,500);

    image.loadImage("planet.png");
    ofEnableDepthTest();
}

void ofApp::update() {
}

void ofApp::draw() {

    // push scaled texture
    glMatrixMode(GL_TEXTURE);
    glPushMatrix();
    ofScale(image.getWidth(),image.getHeight());
    glMatrixMode(GL_MODELVIEW);

    // cam on
    cam.begin();

    light.enable();
    light.draw();

    image.bind();
    ofDrawSphere(200);
    image.unbind();

    light.disable();

    cam.end();

    // kill texture
    glMatrixMode(GL_TEXTURE);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
}
