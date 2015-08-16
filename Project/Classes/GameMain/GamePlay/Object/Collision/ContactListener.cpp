#include "ContactListener.h"
#include "ContactManager.h"

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
	EventListenerPhysicsContact*	listener	= EventListenerPhysicsContact::create();
	ContactManager&					manager		= ContactManager::getInstance();
	
	// オブジェクトが接触した時に呼ばれる。
	listener->onContactBegin = [ &manager ]( PhysicsContact& contact )
	{
		manager.onContactEvent( ContactFuncTag::BEGIN, contact );
		return true;
	};
	
	// オブジェクトが接触している時に呼ばれる。
	listener->onContactPreSolve = [ &manager ]( PhysicsContact& contact, PhysicsContactPreSolve& solve )
	{
		manager.onContactEvent( ContactFuncTag::PRESOLVE, contact );
		return true;
	};
	
	// オブジェクトが離れた時に呼ばれる。
	listener->onContactSeperate = [ &manager ]( PhysicsContact& contact )
	{
		manager.onContactEvent( ContactFuncTag::SEPERATE, contact );
	};
	
	getEventDispatcher()->addEventListenerWithSceneGraphPriority( listener, this );
}