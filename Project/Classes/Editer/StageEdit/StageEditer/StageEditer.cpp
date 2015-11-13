//
//  StageEditer.cpp
//  PSStageCreate
//
//  Created by 星共法 on 2015/10/26.
//
//

#include "Editer/StageEdit/StageEditer/StageEditer.h"

#include "System/Math/SystemMath.h"
#include "System/Widget/Button/Button.h"

using namespace System::Math;
using namespace System::Widget;

StageEditer::StageEditer()
{
    
}

StageEditer::~StageEditer()
{
    
}

bool StageEditer::init(CONST_REF(Utility::FileIO::PlistIO) plist, CONST_REF(CallBack) cb)
{
    if(!Node::init()) return false;
    
//    //  ステージオブジェクトの作成
//    ValueMap ballStatus { plist.data.at("Data").asValueMap().at("Ball").asValueMap() };
//    Ball* ball { Ball::create() };
//    ball->setPosition(Vec2(ballStatus.at("posX").asFloat(), ballStatus.at("posY").asFloat()));
//    ball->setScale(ballStatus.at("scale").asFloat());
//    ball->setRotation(ballStatus.at("rotate").asFloat());
//    
//    this->addChild(ball);
//    
//    ValueMap slimeStatus { plist.data.at("Data").asValueMap().at("Slime").asValueMap() };
//    Slime* slime { Slime::create() };
//    slime->setPosition(Vec2(ballStatus.at("posX").asFloat(), ballStatus.at("posY").asFloat()));
//    slime->setScale(ballStatus.at("scale").asFloat());
//    slime->setRotation(ballStatus.at("rotate").asFloat());
//    
//    this->addChild(slime);
    
    //  バックボタン
    const Vec2 backButtonSize { 100, 50 };
    Button* backButton { Button::create("res/texture/return_scene.png") };
    backButton->setSize(backButtonSize);
    backButton->setScale(toScale(backButtonSize, backButton->getContentSize()));
    backButton->setCallBackOnTouchEnded(mReturnStageSelect);
    backButton->setPosition(Vec2(backButtonSize.x / 2, backButtonSize.y / 2));
    
    this->addChild(backButton);
    
    return true;
}