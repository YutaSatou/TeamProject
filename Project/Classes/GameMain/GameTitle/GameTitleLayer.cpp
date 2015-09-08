#include "GameTitleLayer.h"

using namespace cocos2d;

bool GameTitleLayer::init()
{
	if ( !LayerColor::initWithColor( Color4B::BLACK ) )
	{
		return false;
	}
	
	scheduleUpdate();
	
	return true;
}

void GameTitleLayer::update( float deltaTime )
{
	
}

GameTitleLayer* GameTitleLayer::create()
{
	GameTitleLayer* inst = new GameTitleLayer();
	
	if ( inst && inst->init() )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}