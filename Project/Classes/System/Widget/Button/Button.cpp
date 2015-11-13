//
//  Button.cpp
//  PSStageCreate
//
//  Created by 星共法 on 2015/10/19.
//
//

#include "System/Widget/Button/Button.h"

#include "System/SystemCommon.h"
#include "System/Math/SystemMath.h"

using namespace System::Math;

namespace System{
namespace Widget{
    Button::Button()
    {
        mCallbackBegan = [](Ref*){  };
        mCallbackMoved = [](Ref*){  };
        mCallbackEnded = [](Ref*){  };
        mCallbackCancel = [](Ref*){  };
    }

    Button::~Button()
    {

    }

    bool Button::init(CONST_REF(std::string) path)
    {
        //  タッチイベントの追加
        mTouchDesc.began = [this](Touch* touch, Event* event) { return this->isContains(&mCallbackBegan, touch, event); };
        mTouchDesc.moved = [this](Touch* touch, Event* event) { return this->isContains(&mCallbackMoved, touch, event); };
        mTouchDesc.ended = [this](Touch* touch, Event* event) { return this->isContains(&mCallbackEnded, touch, event); };
        mTouchDesc.cancel = [this](Touch* touch, Event* event) { return this->isContains(&mCallbackCancel, touch, event); };
        TouchListener::TouchOneByOne(mTouchDesc, this);
        
        const Vec2 scrSize { Director::getInstance()->getVisibleSize() };
        
        //  ボタンのサイズは画像のサイズに合わせる
        mBackground = Sprite::create(path);
        this->setContentSize(mBackground->getContentSize() * mBackground->getScale());
        this->setAnchorPoint(AnchorPoint::MIDDLE_CENTER);
        mBackground->setPosition(Vec2::ZERO);
        mBackground->setAnchorPoint(AnchorPoint::BOTTOM_LFET);
        this->addChild(mBackground);
        
        return true;
    }
    
    // タッチ処理時に矩形内へのタッチか判定する処理を割りこませる
    bool Button::isContains(CallBack* callback, Touch* touch, Event* event)
    {
        if(!mTouchEnable) return false;
        
        if(this->getBoundingBox().containsPoint(touch->getLocation()))
        {
            (*callback)(this);
            return true;
        }
        return false;
    }
    
    //  リサイズ
    void Button::setSize(CONST_REF(Vec2) size)
    {
        mBackground->setContentSize(Size(size.x, size.y));
        setContentSize(Size(size.x, size.y));
    }
    
    //  スケーリング
    void Button::setScale(CONST_REF(Vec2) scale)
    {
        mBackground->setScale(scale.x, scale.y);
    }
    
    //  タッチに反応するかを設定する
    void Button::setTouchEnable(bool enable)
    {
        mTouchEnable = enable;
    }
    
    void Button::setCallBackOnTouchBegan(CONST_REF(CallBack) cb) { mCallbackBegan = cb; }
    void Button::setCallBackOnTouchMoved(CONST_REF(CallBack) cb) { mCallbackMoved = cb; }
    void Button::setCallBackOnTouchEnded(CONST_REF(CallBack) cb) { mCallbackEnded = cb; }
    void Button::setCallBackOnTouchCancel(CONST_REF(CallBack) cb) { mCallbackCancel = cb; }
}
}


