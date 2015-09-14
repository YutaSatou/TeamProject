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
    ply->release();
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
    
    ply = ADX2Player::create("Basic.acb", "Basic.awb");
    ply->play(0);
    ply->retain();
    
    return true;
}

void SoundTest::update(float dt){
}
