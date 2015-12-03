#include "ContactListener.h"
#include "../../LiquidFun/LiquidFunUserAPI.h"
#include "ContactFuncTag.h"
#include "ContactEventManager.h"

using namespace cocos2d;

// 初期化
bool ContactListener::init()
{
	if ( !Node::init() )
	{
		return false;
	}
	
	initListener();
	
	return true;
}

// インスタンスの生成
ContactListener* ContactListener::create()
{
	ContactListener* inst = new ContactListener();
	
	if ( inst && inst->init() )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

// リスナの初期化
void ContactListener::initListener()
{
	LiquidFunContactListener*	listener	= LiquidFunContactListener::create();
	ContactEventManager&		manager		= ContactEventManager::getInstance();
	
	listener->onContactRigidBegin = [ &manager ]( LiquidFunContact* contact )
	{
		manager.onContactEvent( ContactFuncTag::RIGID_BEGIN, contact );
	};
	
	listener->onContactRigidPreSolve = [ &manager ]( LiquidFunContact* contact, const LiquidFunManifold* oldManifold )
	{
		manager.onContactEvent( ContactFuncTag::RIGID_PRESOLVE, contact );
	};
	
	listener->onContactRigidEnd = [ &manager ]( LiquidFunContact* contact )
	{
		manager.onContactEvent( ContactFuncTag::RIGID_END, contact );
	};
	
	listener->onContactLiquidBegin = [ &manager ]( LiquidFunParticle* particle, LiquidFunParticleBodyContact* contact )
	{
		manager.onContactEvent( ContactFuncTag::LIQUID_BEGIN, contact->fixture, particle, contact->index );
	};
	
	listener->onContactLiquidEnd = [ &manager ]( LiquidFunFixture* fixture, LiquidFunParticle* particle, int index )
	{
		manager.onContactEvent( ContactFuncTag::LIQUID_END, fixture, particle, index );
	};
	
	addChild( listener );
}