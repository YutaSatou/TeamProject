#include "GameTitleLayer.h"

using namespace cocos2d;

bool GameTitleLayer::init()
{
	if ( !LayerColor::initWithColor( Color4B::BLACK ) )
	{
		return false;
	}
	
	scheduleUpdate();
	
	Label* sceneNameLabel = Label::createWithTTF( "GameTitle", "Font/Arial.ttf", 32 );
	sceneNameLabel->setColor( Color3B::WHITE );
	sceneNameLabel->setPosition( Vec2( 300, 400 ) );
	addChild( sceneNameLabel );
	
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