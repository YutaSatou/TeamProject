#include "Brush.h"
#include "BrushTrail.h"

using namespace cocos2d;

Brush::Brush()
	: mBrushTrail( nullptr )
{
	
}

Brush::~Brush()
{
	
}

bool Brush::init()
{
	if ( !Node::init() )
	{
		return false;
	}
	
	initTouchListener();
	
	mBrushTrail = BrushTrail::create();
	addChild( mBrushTrail );
	
	return true;
}

Brush* Brush::create()
{
	Brush* inst = new Brush();
	
	if ( inst && inst->init() )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

void Brush::initTouchListener()
{
	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
	
	listener->onTouchBegan = [ this ]( Touch* touch, Event* event )
	{
		mBrushTrail->writeBegin( touch );
		return true;
	};
	
	listener->onTouchMoved = [ this ]( Touch* touch, Event* event )
	{
		mBrushTrail->writeMove( touch );
	};
	
	listener->onTouchEnded = [ this ]( Touch* touch, Event* event )
	{
		mBrushTrail->writeEnd( touch );
	};
	
	listener->onTouchCancelled = [ this ]( Touch* touch, Event* event )
	{
		mBrushTrail->writeEnd( touch );
	};
	
	listener->setSwallowTouches( true );
	
	getEventDispatcher()->addEventListenerWithSceneGraphPriority( listener, this );
}