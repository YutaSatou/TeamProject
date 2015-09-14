#include "GameResultLayer.h"

using namespace cocos2d;

bool GameResultLayer::init()
{
	if ( !LayerColor::initWithColor( Color4B::BLACK ) )
	{
		return false;
	}
	
	scheduleUpdate();
	
	Label* sceneNameLabel = Label::createWithTTF( "GameResult", "Font/Arial.ttf", 32 );
	sceneNameLabel->setColor( Color3B::WHITE );
	sceneNameLabel->setPosition( Vec2( 300, 400 ) );
	addChild( sceneNameLabel );
	
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