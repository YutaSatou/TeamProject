//
//  StageEdit.cpp
//  PSStageCreate
//
//  Created by 星共法 on 2015/10/25.
//
//

#include "Editer/StageEdit/StageEdit.h"

#include "System/Widget/Button/Button.h"
#include "System/Math/SystemMath.h"

#include "Editer/StageEdit/StageEditer/StageEditer.h"

using namespace Utility::FileIO;
using namespace System::Widget;
using namespace System::Math;

StageEdit::StageEdit()
{
    
}

StageEdit::~StageEdit()
{
    
}

bool StageEdit::init(CONST_REF(CallBack) cb)
{
    if(!Node::init()) return false;
    
    mReturnScene = cb;
    
    const Vec2 scrSize { Director::getInstance()->getVisibleSize() };
    
    mStageList = ButtonTable::create(Vec2(2, 4), Vec2::ZERO);
    
    Button* returnSceneButton { Button::create("res/texture/return_scene.png") };
    returnSceneButton->setCallBackOnTouchEnded([this](Ref*)
    {
        LOG("return scene")
        this->mReturnScene(this);
    });
    mStageList->pushback(returnSceneButton);
    
    Button* stage0 { Button::create("res/texture/stageselect_label.png") };
    stage0->setCallBackOnTouchEnded([this](Ref*)
    {
        if(mIsEnable){
            this->exitOut();
            mPlist.onRead("res/document/mPlist/Sample.mPlist");
            StageEditer* editer { StageEditer::create(mPlist, [this](Ref*)
                {
                    //  ステージセレクトを復帰させる
                    this->enterIn();
                }) };
            this->addChild(editer);
            LOG("stage_0")
        }
    });
    mStageList->pushback(stage0);
    
    Button* stage1 { Button::create("res/texture/stageselect_label.png") };
    stage1->setCallBackOnTouchEnded([](Ref*){ LOG("1") });
    mStageList->pushback(stage1);
    
    Button* stage2 { Button::create("res/texture/stageselect_label.png") };
    stage2->setCallBackOnTouchEnded([](Ref*){ LOG("2") });
    mStageList->pushback(stage2);
    
    this->addChild(mStageList);
    
    return true;
}

//  エディターから返ってくる時の処理
void StageEdit::enterIn()
{
    const Vec2 scrSize { Director::getInstance()->getVisibleSize() };
    CallFunc* activate { CallFunc::create(std::bind(&StageEdit::enableStagelist, this)) };
    MoveTo* move { MoveTo::create(ANIMATION_TIME, Vec2(scrSize.x / 2, scrSize.y / 2)) };
    Sequence* seq { Sequence::create(move, activate, NULL) };
    this->mStageList->runAction(seq);
}

//  エディターへ以降する時の処理
void StageEdit::exitOut()
{
    const Vec2 dist { 1000, this->getPosition().y };
    MoveTo* move { MoveTo::create(ANIMATION_TIME, dist) };
    this->mStageList->runAction(move);
    this->mStageList->setTouchEnable(false);
}

//  ステージリストの有効状態を設定
void StageEdit::setStageListEnable(bool enable)
{
    this->mStageList->setTouchEnable(enable);
}

//  ステージリストを有効にする
void StageEdit::enableStagelist()
{
    this->mStageList->setTouchEnable(true);
}
