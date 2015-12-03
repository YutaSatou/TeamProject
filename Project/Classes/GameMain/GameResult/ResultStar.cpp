//
//  ResultStar.cpp
//  TeamProject
//
//  Created by Satou yuta on 2015/11/27.
//
//

#include "ResultStar.h"
#include "ui/CocosGUI.h"
#include "Evaluation.h"
#include "EvaluationTag.h"
#include "../../Utility/Audio/ADX2Player.h"

using namespace cocos2d;
using namespace ui;

bool ResultStar::init(){
    
    playAnimation();
    
    return true;
}

ResultStar* ResultStar::create(){
    
    ResultStar* inst = new ResultStar();
    
    if ( inst && inst->init() ){
        inst->autorelease();
        return inst;
    }
    
    CC_SAFE_DELETE( inst );
    return nullptr;
}

void ResultStar::drawStar( int StarNum, float delay ){
    
    std::string fileName[] = {
        
        "Texture/GameResult/Star_Small.png",
        "Texture/GameResult/Star.png",
        "Texture/GameResult/Star_Small.png"
    };
    
    Vec2 poses[] = {
    
        Vec2( 180, 520 ),
        Vec2( 360, 620 ),
        Vec2( 540, 520 )
    };
    mStarNum = StarNum;
        
    Sequence* animation = Sequence::create( DelayTime::create( delay ), CallFunc::create( [ = ] (){
        mIsAnimation = true;
        Sprite* star = Sprite::create( "Texture/GameResult/Star_Small.png" );
        star->setAnchorPoint( Vec2::ANCHOR_MIDDLE );
        RotateBy* rotate = RotateBy::create( 0.3f, 360 );
        star->runAction( rotate );
        ADX2Player::getInstance().play( 3 );
        star->setPosition( Vec2( 180, 520 ) );
        this->addChild( star );
    }), nullptr );
        
    animation->setTag( 1 );
        
    this->runAction( animation );
}

void ResultStar::playAnimation(){
    
    Evaluation* e = Evaluation::create();
    addChild( e );
    
    if ( e->getTag() == EvaluationTag::BAD ){
        
        drawStar( 1, 1.5f );
    }
    
    if ( e->getTag() == EvaluationTag::GOOD ){
        
        drawStar( 2, 1.5f );
    }
    
    if ( e->getTag() == EvaluationTag::EXCELLENT ){
    
        drawStar( 2, 1.5f );
    }
    
    if ( e->getTag() == EvaluationTag::PERFECT ){
    
        drawStar( 3, 1.5f );
    }
}

void ResultStar::skipAnimation(){
    
    //mIsAnimation = false;
    for ( int i = 0; i < mStarNum; ++i ) {
        Sequence* action = ( Sequence* )this->getActionByTag( i );
        if ( !action ){ return; }
        action->setDuration( 0.0f );
    }
}