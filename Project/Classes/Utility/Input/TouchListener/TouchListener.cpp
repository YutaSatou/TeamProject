//
//  AddEventListener.cpp
//  MyProject
//
//  Created by 星共法 on 2015/01/31.
//
//

/**
 *  @brief  イベントを作成しつつ、それをディスパッチャーに登録するものだが、
            static関数なので引数の違いを単純にオーバーロードや
            汎用の呼び出しで片付けていいのかは悩みどころ
 */

#include "TouchListener.h"

using namespace cocos2d;

namespace Utility{
void TouchLinstener::TouchOneByOne(TouchEvent::SingleTouch::TouchBegan began ,
                                      TouchEvent::SingleTouch::TouchMoved moved ,
                                      TouchEvent::SingleTouch::TouchEnded ended ,
                                      TouchEvent::SingleTouch::TouchCancel cancelled,
                                      Node* target){
    auto listener = EventListenerTouchOneByOne::create();
    auto dispatcher = Director::getInstance()->getEventDispatcher();
    
    TouchEvent::SingleTouch::TouchBegan beganFunc = began;
    
    //  beganの代入は必須なので、空を渡されたなら適当な物を作成する
    if(!beganFunc){
        beganFunc = [](Touch*, Event*){
            return true;
        };
    }
    
    listener->onTouchBegan = beganFunc;
    listener->onTouchMoved = moved;
    listener->onTouchEnded = ended;
    listener->onTouchCancelled = cancelled;
    dispatcher->addEventListenerWithSceneGraphPriority(listener, target);
}

void TouchLinstener::TouchOneByOne(SingleTouchEventDesc& desc, Node* obj){
    if(!obj){
        return;
    }
    
    auto listener = EventListenerTouchOneByOne::create();
    auto dispatcher = Director::getInstance()->getEventDispatcher();
    
    //  beganの代入は必須なので、空を渡されたなら適当な物を作成する
    if(!desc.began){
        desc.began = [](Touch*, Event*)->bool{
            return true;
        };
    }
    
    listener->onTouchBegan = desc.began;
    listener->onTouchMoved = desc.moved;
    listener->onTouchEnded = desc.ended;
    listener->onTouchCancelled = desc.ended;
    dispatcher->addEventListenerWithSceneGraphPriority(listener, obj);
}

void TouchLinstener::TouchOneByOne(EventListenerTouchOneByOne* listener, Node* target){
    auto t_dispatcher = Director::getInstance()->getEventDispatcher();
    t_dispatcher->addEventListenerWithSceneGraphPriority(listener, target);
}

void TouchLinstener::TouchAllAtOnce(TouchEvent::MultiTouch::TouchesBegan began,
                                       TouchEvent::MultiTouch::TouchesMoved moved,
                                       TouchEvent::MultiTouch::TouchesEnded ended,
                                       TouchEvent::MultiTouch::TouchesCancel cancelled,
                                       Node* target){
    auto listener = EventListenerTouchAllAtOnce::create();
    auto dispatcher = Director::getInstance()->getEventDispatcher();
    
    TouchEvent::MultiTouch::TouchesBegan beganFunc = began;
    
    //  beganの代入は必須なので、空を渡されたなら適当な物を作成する
    if(!beganFunc){
        beganFunc = [](const std::vector<Touch*>&, Event*)->void{
            
        };
    }
    
    listener->onTouchesBegan = beganFunc;
    listener->onTouchesMoved = moved;
    listener->onTouchesEnded = ended;
    listener->onTouchesCancelled = cancelled;
    dispatcher->addEventListenerWithSceneGraphPriority(listener, target);
}

void TouchLinstener::TouchAllAtOnce(MultiTouchEventDesc& desc, Node* obj){
    if(!obj){
        return;
    }
    
    auto listener = EventListenerTouchAllAtOnce::create();
    auto dispatcher = Director::getInstance()->getEventDispatcher();
    
    //  beganの代入は必須なので、空を渡されたなら適当な物を作成する
    if(!desc.began){
        desc.began = [](const std::vector<Touch*>&, Event*)->void{
            
        };
    }
    
    listener->onTouchesBegan = desc.began;
    listener->onTouchesMoved = desc.moved;
    listener->onTouchesEnded = desc.ended;
    listener->onTouchesCancelled = desc.cancel;
    dispatcher->addEventListenerWithSceneGraphPriority(listener, obj);
}

void TouchLinstener::KeyBoard(KeyInputEvent::KeyInputPressed pressed,
                                 KeyInputEvent::KeyInputReleased released,
                                 Node* target){
    auto listener = EventListenerKeyboard::create();
    auto dispatcher = Director::getInstance()->getEventDispatcher();
    
    listener->onKeyPressed = pressed;
    listener->onKeyReleased = released;
    
    dispatcher->addEventListenerWithSceneGraphPriority(listener, target);
}
}






