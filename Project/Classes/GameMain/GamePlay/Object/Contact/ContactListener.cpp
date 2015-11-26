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
	
	// オブジェクトが接触した時に呼ばれる。
	listener->onContactBegin = [ &manager ]( LiquidFunContact* contact )
	{
		manager.onContactEvent( ContactFuncTag::BEGIN, contact );
	};
	
	// オブジェクトが接触している時に呼ばれる。
	listener->onContactPreSolve = [ &manager ]( LiquidFunContact* contact, const LiquidFunManifold* oldManifold )
	{
		manager.onContactEvent( ContactFuncTag::PRESOLVE, contact );
	};
	
	// オブジェクトが離れた時に呼ばれる。
	listener->onContactEnd = [ &manager ]( LiquidFunContact* contact )
	{
		manager.onContactEvent( ContactFuncTag::END, contact );
	};
	
	addChild( listener );
}