#include "DebugLayer.h"
#include "Object/Wall/Wall.h"
#include "Object/Ball/Ball.h"
#include "User/Brush/Brush.h"

using namespace cocos2d;

bool DebugLayer::init()
{
	if ( !LayerColor::initWithColor( Color4B::BLACK ) )
	{
		return false;
	}
	
	scheduleUpdate();
	
	Wall*	wall	= Wall::create();
	Ball*	ball	= Ball::create( Vec2( 600.0f, 600.0f ) );
	Brush*	brush	= Brush::create();
	
	addChild( wall );
	addChild( ball );
	addChild( brush );
	
	return true;
}

void DebugLayer::update( float deltaTime )
{
	
}

DebugLayer* DebugLayer::create()
{
	DebugLayer* inst = new DebugLayer();
	
	if ( inst && inst->init() )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}