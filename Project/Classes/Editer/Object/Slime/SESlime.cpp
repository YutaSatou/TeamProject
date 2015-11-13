//
//  SESlime.cpp
//  PSStageCreate
//
//  Created by 星共法 on 2015/11/09.
//
//

#include "Editer/Object/Slime/SESlime.h"

SESlime::SESlime()
{
    
}

SESlime::~SESlime()
{
    
}

bool SESlime::init()
{
    if(!Node::init()) return false;
    
    DrawNode* slime { DrawNode::create() };
    slime->drawDot(this->getPosition(), 10.0f, Color4F::BLUE);
    this->addChild(slime);
    
    return true;
}