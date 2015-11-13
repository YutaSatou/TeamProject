//
//  StageView.cpp
//  PSStageCreate
//
//  Created by 星共法 on 2015/10/25.
//
//

#include "Editer/StageView/StageView.h"

#include "System/Widget/Button/Button.h"
#include "System/Math/SystemMath.h"

using namespace System::Widget;
using namespace System::Math;

StageView::StageView()
{
    
}

StageView::~StageView()
{
    
}

bool StageView::init(CONST_REF(CallBack) cb)
{
    if(!Node::init()) return false;
    
    const Vec2 scrSize { Director::getInstance()->getVisibleSize() };
    
    //  ボタン作成
    Button* button { Button::create("res/texture/playmode_stageview.png") };
    button->setCallBackOnTouchEnded(cb);
    const Vec2 scale { toScale(scrSize, button->getContentSize()) };
    const Vec2 pos { scrSize.x * 0.5f, scrSize.y * 0.5f };
    button->setScale(scale);
    button->setSize(scrSize);
    button->setPosition(pos);
    this->addChild(button);
    
    return true;
}