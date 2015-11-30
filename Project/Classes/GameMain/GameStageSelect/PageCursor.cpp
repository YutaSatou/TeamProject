//
//  PageCurSor.cpp
//  TeamProject
//
//  Created by Satou yuta on 2015/10/23.
//
//

#include "PageCursor.h"
#include "StageSelectPage.h"

using namespace cocos2d;
using namespace ui;

bool PageCursor::init(){

    if ( !Layer::init() ){
        
        return false;
    }
    
    return true;
}

PageCursor* PageCursor::create(){
    
    PageCursor* inst = new PageCursor();
    
    if ( inst && inst->init() )
    {
        inst->autorelease();
        return inst;
    }
    
    CC_SAFE_DELETE( inst );
    return nullptr;
}

void PageCursor::update( float deltaTime ){
}

ImageView* PageCursor::baseTex( const std::string& baseTex, const Vec2& pos ){
    
    ImageView* image = ImageView::create( baseTex );
    image->setPosition( pos );
    
    return image;
}

MenuItemImage* PageCursor::sliderTex( const std::string& sliderTex, const Vec2& pos ){
    
    MenuItemImage* button = MenuItemImage::create( sliderTex, sliderTex, [](Ref* ref){} );
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches( true );
    button->setPosition( pos );
    
    return button;
}