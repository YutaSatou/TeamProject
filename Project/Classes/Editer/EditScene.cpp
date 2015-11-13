//
//  EditScene.cpp
//  PSStageCreate
//
//  Created by 星共法 on 2015/10/16.
//
//

#include "Editer/EditScene.h"

#include "System/Math/SystemMath.h"
#include "System/Widget/Button/Button.h"

#include "Editer/StageEdit/StageEdit.h"
#include "Editer/StageView/StageView.h"

using namespace System;
using namespace System::Math;
using namespace System::Widget;

EditScene::EditScene()
{
    
}

EditScene::~EditScene()
{
    
}

Scene* EditScene::createScene()
{
    Scene* scene { Scene::create() };
    EditScene* title { new EditScene() };
    if(title && title->init())
    {
        title->autorelease();
        scene->addChild(title);
        return scene;
    }
    return nullptr;
}

bool EditScene::init()
{
    if(!Layer::init()) return false;
    
    const Vec2 scrSize { Director::getInstance()->getVisibleSize() };
    
    //  タイルの作成
    //  タイルのサイズ
    const Vec2 tileSize { scrSize.x / ALIGNMENT_WIDTH_NUM, scrSize.y / ALIGNMENT_HEIGHT_NUM };
    
    mPlayTable = ButtonTable::create(Vec2(2, 3), Vec2(0, 0));
    
    Button* edit { Button::create(spriteNameList.at(PLAY_TYPE::EDIT)) };
    edit->setCallBackOnTouchEnded([this](Ref*)
    {
        LOG("edit")
        this->onPlay(PLAY_TYPE::EDIT);
    });
    mPlayTable->pushback(edit);
    
    Button* view { Button::create(spriteNameList.at(PLAY_TYPE::VIEW)) };
    view->setCallBackOnTouchEnded([this](Ref*)
    {
        LOG("edit")
        this->onPlay(PLAY_TYPE::VIEW);
    });
    mPlayTable->pushback(view);
    
    this->addChild(mPlayTable);
    
    return true;
}

//  作業を開始する
void EditScene::onPlay(PLAY_TYPE type)
{
    const Vec2 scrSize { Director::getInstance()->getVisibleSize() };
    
    const float animationTime { 0.2f };
    const Vec2 centerPos { scrSize.x / 2, scrSize.x / 2 };  //  画面センター
    const Vec2 enterPos { 0.0f, 0.0f };              //  起動したオブジェクトの初期位置
    const Vec2 exitPos { scrSize.x, centerPos.y };          //  終了したオブジェクトの向かう座標
    
    //  退出用アニメーション
    ScaleTo* exitScaling { ScaleTo::create(animationTime, 0.5f) };
    MoveTo* exitTranslation { MoveTo::create(animationTime, exitPos) };
    //  入室用アニメーション
    ScaleTo* enterScaling { ScaleTo::create(animationTime, 1.0f) };
    MoveTo* enterTranslation { MoveTo::create(animationTime, enterPos) };
    
    //  プレイタグがNoneの時のみテーブルを復帰させる
    if(type == PLAY_TYPE::NONE)
    {
        CallFunc* tableActivation = CallFunc::create(std::bind(&EditScene::tableActivate, this));
        CallFunc* playObjectDestroy = CallFunc::create(std::bind(&EditScene::playObjectDestroy, this));
        Spawn* exitAnim { Spawn::create(exitScaling, exitTranslation, NULL) };
        Spawn* enterAnim { Spawn::create(enterScaling, enterTranslation, NULL) };
        mPlayObject->runAction(Sequence::create(exitAnim, playObjectDestroy, NULL));
        mPlayTable->runAction(Sequence::create(enterAnim, tableActivation, NULL));
    }
    else
    {
        Spawn* exitAnim { Spawn::create(exitScaling, exitTranslation, NULL) };
        Spawn* enterAnim { Spawn::create(enterScaling, enterTranslation, NULL) };
        //  作業モードからの復帰は必ずNoneタグ
        switch (type) {
            case PLAY_TYPE::EDIT :
                mPlayObject = StageEdit::create([this](Ref*)
                {
                    this->onPlay(PLAY_TYPE::NONE);
                });
                break;
            case PLAY_TYPE::VIEW :
                mPlayObject = StageView::create([this](Ref*)
                {
                    this->onPlay(PLAY_TYPE::NONE);
                });
                break;
            default:
                break;
        }
        this->addChild(mPlayObject);
        mPlayObject->setPosition(Vec2(-scrSize.x, 0.0f));
        mPlayObject->runAction(enterAnim);
        mPlayTable->setTouchEnable(false);
        mPlayTable->runAction(exitAnim);
    }
}

//  テーブルを有効にする
void EditScene::tableActivate()
{
    this->mPlayTable->setTouchEnable(true);
}

//  作業オブジェクトの破棄
void EditScene::playObjectDestroy()
{
    this->removeChild(mPlayObject);
    this->mPlayObject = nullptr;
}


