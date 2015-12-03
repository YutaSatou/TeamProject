//
//  ResultSlime.cpp
//  TeamProject
//
//  Created by Satou yuta on 2015/11/29.
//
//

#include "ResultSlime.h"
#include "Evaluation.h"
#include "../../Utility/Audio/ADX2Player.h"

using namespace cocos2d;

ResultSlime::~ResultSlime(){

    ADX2Player::getInstance().stop( mBGM );
}

bool ResultSlime::init(){
    
    playAnimation();
    return true;
}

ResultSlime* ResultSlime::create(){
    
    ResultSlime* inst = new ResultSlime();
    
    if ( inst && inst->init() ){
        inst->autorelease();
        return inst;
    }
    CC_SAFE_DELETE( inst );
    return nullptr;
}

void ResultSlime::playAnimation(){
    
    Evaluation* e = Evaluation::create();
    addChild( e );
    
    float delay = 0;
    
    if ( e->getTag() == EvaluationTag::BAD ){
       delay = 2.0f;
    }
    
    if ( e->getTag() == EvaluationTag::GOOD ){
        delay = 3.0f;
    }
    
    if ( e->getTag() == EvaluationTag::EXCELLENT ){
        delay = 3.0f;
    }
    
    if ( e->getTag() == EvaluationTag::PERFECT ){
        delay = 4.0f;
    }

    
    Sequence* animation = Sequence::create( DelayTime::create( delay ), CallFunc::create( [ = ] (){
        mIsAnimation = true;
        mBGM = ADX2Player::getInstance().play( 2 );
        Sprite* sprite = Sprite::create("Texture/GameResult/Star.png" );
        sprite->setPosition( 338, 240 );
        this->addChild(sprite);
    }), nullptr);
    
    animation->setTag( 0 );
    
    this->runAction( animation );
}

void ResultSlime::skipAnimation(){
    
    Sequence* seqAction = ( Sequence* )this->getActionByTag( 0 );
    
    if ( !seqAction ){ return; }
    seqAction->setDuration( 0.0f );
}