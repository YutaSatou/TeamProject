#include "GameStageSelectLayer.h"

using namespace cocos2d;

bool GameStageSelectLayer::init()
{
	if ( !LayerColor::initWithColor( Color4B::BLACK ) )
	{
		return false;
	}
	
	scheduleUpdate();
	
	Label* sceneNameLabel = Label::createWithTTF( "GameStageSelect", "Font/Arial.ttf", 32 );
	sceneNameLabel->setColor( Color3B::WHITE );
	sceneNameLabel->setPosition( Vec2( 300, 400 ) );
	addChild( sceneNameLabel );
	
	return true;
}

void GameStageSelectLayer::update( float deltaTime )
{
	
}

GameStageSelectLayer* GameStageSelectLayer::create()
{
	GameStageSelectLayer* inst = new GameStageSelectLayer();
	
	if ( inst && inst->init() )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}