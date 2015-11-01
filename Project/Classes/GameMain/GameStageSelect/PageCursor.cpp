//
//  PageCurSor.cpp
//  TeamProject
//
//  Created by Satou yuta on 2015/10/23.
//
//

#include "PageCursor.h"

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