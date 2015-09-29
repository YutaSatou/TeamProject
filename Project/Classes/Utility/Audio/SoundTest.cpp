//
//  SoundTest.cpp
//  TeamProject
//
//  Created by Satou yuta on 2015/07/29.
//
//
#include "Utility/Audio/SoundTest.h"
#include "Utility/Audio/ADX2Manager.h"

using namespace cocos2d;


#include "Utility/Audio/SoundTest.h"
#include "Utility/Audio/ADX2Manager.h"

SoundTest::SoundTest(){
}

SoundTest::~SoundTest(){
	ply->release();
}

SoundTest* SoundTest::createScene(){
    
    SoundTest* inst = new SoundTest();
    
    if ( inst && inst->init() )
    {
        inst->autorelease();
        return inst;
    }
    
    CC_SAFE_DELETE( inst );
    return nullptr;
}

bool SoundTest::init(){
    
    if (!Layer::init()){
        return false;
    }
	
	scheduleUpdate();
    
    ply = ADX2Player::create("Basic.acb", "Basic.awb");
    ply->play(2, SoundType::SE, 1.0f);
	ply->retain();
    return true;
}

void SoundTest::update(float dt){
    ADX2Manager::getInstance().update();
}
