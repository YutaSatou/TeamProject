//
//  ResultEvaluation.cpp
//  TeamProject
//
//  Created by Satou yuta on 2015/11/28.
//
//

#include "ResultEvaluation.h"
#include "ui/CocosGUI.h"
#include "Evaluation.h"
#include "EvaluationTag.h"
#include "../../Utility/DataIO/StageNumber.h"
#include "../../Utility/DataIO/ResultData.h"
#include "../../Utility/Audio/ADX2Player.h"

using namespace cocos2d;
using namespace ui;

namespace  {
 
 static const std::map< EvaluationTag, std::string > EvaluationPath{
 
     { EvaluationTag::BAD,       "Bad" },
     { EvaluationTag::GOOD,      "Good" },
     { EvaluationTag::EXCELLENT, "Excellent" },
     { EvaluationTag::PERFECT,   "Perfect" },
 };
 
}

bool ResultEvaluation::init(){
    
    playAnimation();
    return true;
}

ResultEvaluation* ResultEvaluation::create(){
    
    ResultEvaluation* inst = new ResultEvaluation();
    
    if ( inst && inst->init() ){
        inst->autorelease();
        return inst;
    }
    
    CC_SAFE_DELETE( inst );
    return nullptr;
}

void ResultEvaluation::playAnimation(){
    
    Evaluation* e = Evaluation::create();
    addChild( e );
	
    Sequence* animation = nullptr;
	StageNumber stageNumber;
	ResultData resultData;
	int stageNum = stageNumber.loadStageNumber();
	int ColorR = resultData.readColorR( stageNum );
    int ColorG = resultData.readColorG( stageNum );
    int ColorB = resultData.readColorB( stageNum );
    
    if ( e->getTag() == EvaluationTag::BAD ){
        
        animation = Sequence::create( DelayTime::create( 0.5f ), CallFunc::create( [ = ] (){
            mIsAnimation = true;
            Sprite* sprite = Sprite::create("Texture/GameResult/" + EvaluationPath.at( EvaluationTag::BAD ) + ".png" );
            sprite->setColor( Color3B( ColorR, ColorG, ColorB ) );
            //sprite->setPosition( 360, 930 );
			ADX2Player::getInstance().play( 9 );
			sprite->setAnchorPoint( Vec2::ANCHOR_MIDDLE );
            this->addChild(sprite);
        }), nullptr);

    }
    
    if ( e->getTag() == EvaluationTag::GOOD ){
        
        animation = Sequence::create( DelayTime::create( 0.5f ), CallFunc::create( [ = ] (){
            mIsAnimation = true;
            Sprite* sprite = Sprite::create("Texture/GameResult/" + EvaluationPath.at( EvaluationTag::GOOD ) + ".png" );
            sprite->setColor( Color3B( ColorR, ColorG, ColorB ) );
            //sprite->setPosition( 360, 930 );
			ADX2Player::getInstance().play( 9 );
			sprite->setAnchorPoint( Vec2::ANCHOR_MIDDLE );
            this->addChild(sprite);
        }), nullptr);

    }
    
    if ( e->getTag() == EvaluationTag::EXCELLENT ){
    
        animation = Sequence::create( DelayTime::create( 0.5f ), CallFunc::create( [ = ] (){
            mIsAnimation = true;
            Sprite* sprite = Sprite::create("Texture/GameResult/" + EvaluationPath.at( EvaluationTag::EXCELLENT ) + ".png" );
            sprite->setColor( Color3B( ColorR, ColorG, ColorB ) );
            //sprite->setPosition( 360, 930 );
			ADX2Player::getInstance().play( 9 );
			sprite->setAnchorPoint( Vec2::ANCHOR_MIDDLE );
            this->addChild(sprite);
        }), nullptr);

    }
    
    if ( e->getTag() == EvaluationTag::PERFECT ){
    
        animation = Sequence::create( DelayTime::create( 0.5f ), CallFunc::create( [ = ] (){
            mIsAnimation = true;
            Sprite* sprite = Sprite::create("Texture/GameResult/" + EvaluationPath.at( EvaluationTag::PERFECT ) + ".png" );
            sprite->setColor( Color3B( ColorR, ColorG, ColorB ) );
            //sprite->setPosition( 360, 930 );
			ADX2Player::getInstance().play( 9 );
			sprite->setAnchorPoint( Vec2::ANCHOR_MIDDLE );
            this->addChild(sprite);
        }), nullptr);

    }
    
    animation->setTag( 0 );
    this->runAction( animation );
}

void ResultEvaluation::skipAnimation(){
    
    Sequence* seqAction = ( Sequence* )this->getActionByTag( 0 );
    
    if ( !seqAction ){ return; }
    seqAction->setDuration( 0.0f );
}