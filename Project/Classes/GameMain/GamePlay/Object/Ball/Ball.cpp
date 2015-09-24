#include "Ball.h"
#include "../Collision/ContactSettlor.h"

using namespace cocos2d;

bool Ball::init( const Vec2& position )
{
	if ( !Sprite::initWithFile( "Texture/Debug/Circle.png" ) )
	{
		return false;
	}
	
	setName( "Ball" );
	setAnchorPoint( Vec2::ANCHOR_MIDDLE );
	setPosition( position );
	
	initPhysics();
	
	return true;
}

Ball* Ball::create( const Vec2& position )
{
	Ball* inst = new Ball();
	
	if ( inst && inst->init( position ) )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

void Ball::initPhysics()
{
	PhysicsMaterial material;
	material.density		= 0.6f;
	material.restitution	= 0.9f;
	material.friction		= 0.6f;
	
	PhysicsBody* body = PhysicsBody::createCircle( 32.0f, material );
	body->setDynamic( true );
	
	ContactSettlor contactSettlor( body );
	contactSettlor.setupCategory( ContactCategory::BALL );
	contactSettlor.enableCollision();
	contactSettlor.enableContact();
	
	setPhysicsBody( body );
}