//
//  ResultManager.cpp
//  TeamProject
//
//  Created by Satou yuta on 2015/11/29.
//
//

#include "ResultManager.h"
#include "ResultAnimation.h"
#include "ResultEvaluation.h"
#include "ResultSlime.h"
#include "ResultStar.h"
#include "../../Utility/Assistant/SceneChanger.h"
#include "../GameStageSelect/GameStageSelectLayer.h"

ResultManager::ResultManager()
: mTouchCount( 0 )
, mIsAnimationEnd( false )
, mTouchAnimationTag( TouchAnimationTag::SKIP_SPRITE ){

}

ResultManager::~ResultManager(){

}

ResultManager* ResultManager::create(){
    
    ResultManager* inst = new ResultManager();
    
    if ( inst && inst->init() ){
    
        inst->autorelease();
        return inst;
    }
    CC_SAFE_DELETE( inst );
    return nullptr;

}

bool ResultManager::init(){
    
    mEvaluation = ResultEvaluation::create();
    addChild( mEvaluation );
    
    mSlime = ResultSlime::create();
    addChild( mSlime );
    
    mStar = ResultStar::create();
    addChild( mStar );
    
    initFunc();
    
    return true;
}

void ResultManager::touchAction(){
    
    /*switch ( mTouchCount ) {
        case SKIP_SCORE:
            mEvaluation->skipAnimation();
            CCLOG( "評価文字SKIP" );
            break;
            
        case SKIP_SLIME:
            mSlime->skipAnimation();
            CCLOG( "スライムSKIP" );
            break;
            
        case SKIP_STAR:
            mStar->skipAnimation();
            CCLOG( "星SKIP" );
            break;
            
        case SKIP_SCENE:
            mIsAnimationEnd = true;
            CCLOG( "終わり" );
            break;
    }
    
    mTouchCount++;*/
    
    mTouch[ mTouchAnimationTag ]();
}

void ResultManager::initFunc(){

    auto scoreSkip = [ & ](){
        mEvaluation->skipAnimation();
        if ( mEvaluation->isAnimation() ){
            
            mTouchAnimationTag = TouchAnimationTag::SKIP_STAR;
            this->touchAction();
            return;
        }
    };
    
    auto starSkip = [ & ](){
        if ( mStar->isAnimation() ){
            
            mTouchAnimationTag = TouchAnimationTag::SKIP_SLIME;
            this->touchAction();
            return;
        }
        
        mStar->skipAnimation();
        mTouchAnimationTag =  TouchAnimationTag::SKIP_SLIME;
    };

    
    auto slimeSkip = [ & ](){
        if ( mSlime->isAnimation() ){
            
            mTouchAnimationTag = TouchAnimationTag::SCENE_CHANGE;
            this->touchAction();
            return;
        }
        
        mSlime->skipAnimation();
        mTouchAnimationTag = TouchAnimationTag::SCENE_CHANGE;
    };
    
    auto sceneChange = [ & ](){
        SceneChanger::switchScene( GameStageSelectLayer::create() );
    };
    
    mTouch[ TouchAnimationTag::SKIP_SPRITE ]	= scoreSkip;
    mTouch[ TouchAnimationTag::SKIP_STAR ] = starSkip;
    mTouch[ TouchAnimationTag::SKIP_SLIME ] = slimeSkip;
    mTouch[ TouchAnimationTag::SCENE_CHANGE ] = sceneChange;
}
