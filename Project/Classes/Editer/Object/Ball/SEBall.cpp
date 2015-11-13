//
//  SEBall.cpp
//  PSStageCreate
//
//  Created by 星共法 on 2015/11/09.
//
//

#include "Editer/Object/Ball/SEBall.h"

SEBall::SEBall()
{
    
}

SEBall::~SEBall()
{
    
}

bool SEBall::init()
{
    if(!Node::init()) return false;
    
    DrawNode* ball { DrawNode::create() };
    ball->drawDot(this->getPosition(), 10, Color4F::ORANGE);
    this->addChild(ball);
    return true;
}