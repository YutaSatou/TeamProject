#include "StageSelectLayer.h"

using namespace cocos2d;

bool StageSelectLayer::init()
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