#include "DebugLayer.h"
#include "Object/Collision/ContactListener.h"
#include "Object/Wall/Wall.h"
#include "User/Brush/Brush.h"

using namespace cocos2d;

bool DebugLayer::init()
{
	if ( !LayerColor::initWithColor( Color4B::BLACK ) )
	{
		return false;
	}
	
	scheduleUpdate();
	
	ContactListener*	contactListener	= ContactListener::create();
	Wall*				wall			= Wall::create();
	Brush*				brush			= Brush::create();
	
	addChild( contactListener );
	addChild( wall );
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