//
//  PageCurSor.cpp
//  TeamProject
//
//  Created by Satou yuta on 2015/10/23.
//
//

#include "PageCurSor.h"

using namespace cocos2d;
using namespace ui;

bool PageCurSor::init(){

    if ( !Layer::init() ){
        
        return false;
    }
    
    return true;
}

PageCurSor* PageCurSor::create(){
    
    PageCurSor* inst = new PageCurSor();
    
    if ( inst && inst->init() )
    {
        inst->autorelease();
        return inst;
    }
    
    CC_SAFE_DELETE( inst );
    return nullptr;
}

void PageCurSor::update( float deltaTime ){
}