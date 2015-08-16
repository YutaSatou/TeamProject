//
//  SoundTest.cpp
//  TeamProject
//
//  Created by Satou yuta on 2015/07/29.
//
//
#include "Utility/Audio/SoundTest.h"
#include "Utility/Audio/ADX2Manager.h"

#define VISIBLESIZE Director::getInstance()->getVisibleSize()
#define ORIGINSIZE Director::getInstance()->getVisibleOrigin()

using namespace cocos2d;

SoundTest::SoundTest(){
}

SoundTest::~SoundTest(){
    CC_SAFE_RELEASE(ply);
}

Scene* SoundTest::createScene(){
    Scene* scene = Scene::create();
    Layer* layer = SoundTest::create();
    scene->addChild(layer);
    return scene;
}

bool SoundTest::init(){
    
    if (!Layer::init()){
        return false;
    }
    scheduleUpdate();
    log("StartSoundScene");
    /*Label* soundTestLabel = Label::createWithTTF("SoundTestScene", "Arial.ttf", 64);
    soundTestLabel->setPosition(Vec2(VISIBLESIZE.width / 2 + ORIGINSIZE.x, VISIBLESIZE.height / 2 + ORIGINSIZE.y));
    this->addChild(soundTestLabel, 1);*/
    
    ply = ADX2Player::create("Basic.acb", "Basic.awb");
    ply->play(2);
    CC_SAFE_RETAIN(ply);
    return true;
}

void SoundTest::update(float dt){
    ADX2Manager::getInstance().update();
}
