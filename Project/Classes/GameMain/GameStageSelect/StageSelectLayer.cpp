#include "StageSelectLayer.h"

using namespace cocos2d;

bool StageSelectLayer::init()
{
	if ( !LayerColor::initWithColor( Color4B::BLACK ) )
	{
		return false;
	}
	
	scheduleUpdate();
	
	return true;
}

void StageSelectLayer::update( float deltaTime )
{
	
}

StageSelectLayer* StageSelectLayer::create()
{
	StageSelectLayer* inst = new StageSelectLayer();
	
	if ( inst && inst->init() )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}