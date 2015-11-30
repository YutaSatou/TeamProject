//
//  StageSelectOption.cpp
//  TeamProject
//
//  Created by Satou yuta on 2015/11/06.
//
//

#include "StageSelectOption.h"

using namespace cocos2d;
using namespace ui;

namespace  {
    
    Size SCREEN_SIZE;
    Vec2 ORIGIN_SIZE;
}

bool StageSelectOption::init(){
    
    if ( !Layer::init() ){
        
        return false;
    }
    
    SCREEN_SIZE = Director::getInstance()->getVisibleSize();
    ORIGIN_SIZE = Director::getInstance()->getVisibleOrigin();
    
    Button* creditButton = Button::create( "Texture/Debug/Stage_Option_Button.png",
                                           "Texture/Debug/Stage_Option_Button.png",
                                           "Texture/Debug/Stage_Option_Button.png");
    creditButton->setTitleText( "クレジット" );
    creditButton->setTitleFontName( "Font/RiiPopkkR.otf" );
    creditButton->setTitleFontSize( 24 );
    creditButton->setTitleColor( Color3B::BLACK );
    creditButton->setPosition( Vec2( 229, 367 ) );
    addChild( creditButton );
    
    creditButton->addTouchEventListener( [ = ]( Ref* sender, Widget::TouchEventType type ){
    
        if ( type == Widget::TouchEventType::BEGAN ){
        
            CCLOG( "Credit" );
        }
    });

    Button* optionButton = Button::create( "Texture/Debug/Stage_Option_Button.png",
                                          "Texture/Debug/Stage_Option_Button.png",
                                          "Texture/Debug/Stage_Option_Button.png");
    optionButton->setTitleText( "オプション" );
    optionButton->setTitleFontName( "Font/RiiPopkkR.otf" );
    optionButton->setTitleFontSize( 24 );
    optionButton->setTitleColor( Color3B::BLACK );
    optionButton->setPosition( Vec2( 485, 367 ) );
    addChild( optionButton );
    
    optionButton->addTouchEventListener( [ = ]( Ref* sender, Widget::TouchEventType type ){
        
        if ( type == Widget::TouchEventType::BEGAN ){
            
            CCLOG( "option" );
        }
    });
    
    return true;
}

StageSelectOption* StageSelectOption::create(){
    
    StageSelectOption* inst = new StageSelectOption();
    
    if ( inst && inst->init() ){
        inst->autorelease();
        return inst;
    }
    
    CC_SAFE_DELETE( inst );
    return nullptr;
}

void StageSelectOption::update( float deltaTime ){
    
}