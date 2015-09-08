#include "GameResultLayer.h"

using namespace cocos2d;

bool GameResultLayer::init()
{
	if ( !LayerColor::initWithColor( Color4B::BLACK ) )
	{
		return false;
	}
	
	scheduleUpdate();
	
	return true;
}

void GameResultLayer::update( float deltaTime )
{
	
}

GameResultLayer* GameResultLayer::create()
{
	GameResultLayer* inst = new GameResultLayer();
	
	if ( inst && inst->init() )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}