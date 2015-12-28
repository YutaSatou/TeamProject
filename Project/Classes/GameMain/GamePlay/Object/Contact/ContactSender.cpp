#include "ContactSender.h"
#include "../../LiquidFun/LiquidFunUserAPI.h"
#include "../../LiquidFun/LiquidFunCoreAPI.h"
#include "ContactFuncTag.h"
#include "ContactSendChecker.h"

using namespace cocos2d;

// コンストラクタ
ContactSender::ContactSender( ContactEventManager::CallbackContainer& callbackContainer )
	: mCallbackContainer( callbackContainer )
	, mContactRigidContainer()
	, mContactLiquidContainer()
	, mSendChecker( makeShared< ContactSendChecker >( callbackContainer ) )
{
	initContainer();
}

// 通知
void ContactSender::send( const ContactFuncTag& funcTag, LiquidFunContact* contact )
{
	// 接触したフィクスチャから、ボディとボディに登録されているノードを取得する。
	LiquidFunFixture*	fixtureA	{ contact->GetFixtureA() };
	LiquidFunFixture*	fixtureB	{ contact->GetFixtureB() };
	LiquidFunBody*		bodyA		{ fixtureA->GetBody() };
	LiquidFunBody*		bodyB		{ fixtureB->GetBody() };
	Node*				nodeA		{ LiquidFunHelper::getNode( bodyA ) };
	Node*				nodeB		{ LiquidFunHelper::getNode( bodyB ) };
	
	// ノードの取得に失敗した場合は、終了する。
	if ( !nodeA ) { return; }
	if ( !nodeB ) { return; }
	
	if ( !mSendChecker->isFilter( std::make_pair( fixtureA->GetFilterData().categoryBits, fixtureB->GetFilterData().categoryBits ),
								  std::make_pair( nodeA->getName(), nodeB->getName() ) ) )
	{
		// フィルタチェックを通過できない場合は、終了する。
		return;
	}
	
	// オブジェクトに接触を通知する。
	mContactRigidContainer.at( funcTag )( nodeA->getName(), nodeB, bodyB );
	mContactRigidContainer.at( funcTag )( nodeB->getName(), nodeA, bodyA );
}

// 通知
void ContactSender::send( const ContactFuncTag& funcTag, LiquidFunFixture* fixture, LiquidFunParticle* particle, int index )
{
	// 接触したボディとボディに登録されているノードを取得する。パーティクルは登録されているノードの親ノードを取得する。
	LiquidFunBody*	body			{ fixture->GetBody() };
	Node*			particleNode	{ LiquidFunHelper::getNode( particle->GetUserDataBuffer() ) };
	Node*			rigidNode		{ LiquidFunHelper::getNode( body ) };
	Node*			liquidNode		{ particleNode->getParent() };
	
	// ノードの取得に失敗した場合は、終了する。
	if ( !rigidNode )	{ return; }
	if ( !liquidNode )	{ return; }
	
	if ( !mSendChecker->isFilter( std::make_pair( fixture->GetFilterData().categoryBits, Contact::toUShort( Contact::Category::LIQUID ) ),
								  std::make_pair( rigidNode->getName(), liquidNode->getName() ) ) )
	{
		// フィルタチェックを通過できない場合は終了する。
		return;
	}
	
	// オブジェクトに接触を通知する。
	mContactRigidContainer.at( funcTag )( liquidNode->getName(), rigidNode, body );
	mContactLiquidContainer.at( funcTag )( rigidNode->getName(), liquidNode, particle, index );
}

// コンテナの初期化
void ContactSender::initContainer()
{
	using Key = const std::string;
	
	auto rigidBegin		= [ this ]( Key& key, Node* _1, LiquidFunBody* _2 )				{ mCallbackContainer.at( key )->onContactRigidBegin( _1, _2 );			};
	auto rigidPresolve	= [ this ]( Key& key, Node* _1, LiquidFunBody* _2 )				{ mCallbackContainer.at( key )->onContactRigidPreSolve( _1, _2 );		};
	auto rigidEnd		= [ this ]( Key& key, Node* _1, LiquidFunBody* _2 )				{ mCallbackContainer.at( key )->onContactRigidEnd( _1, _2 );			};
	auto liquidBegin	= [ this ]( Key& key, Node* _1, LiquidFunParticle* _2, int _3 )	{ mCallbackContainer.at( key )->onContactLiquidBegin( _1, _2, _3 );		};
	auto liquidEnd		= [ this ]( Key& key, Node* _1, LiquidFunParticle* _2, int _3 )	{ mCallbackContainer.at( key )->onContactLiquidEnd( _1, _2, _3 );		};
	auto liquidPresolve	= [ this ]( Key& key, Node* _1, LiquidFunParticle* _2, int _3 )	{ CCLOG( "%s", "onContactLiquidPreSolve is not implemented yet." );		};
	
	mContactRigidContainer.emplace( ContactFuncTag::BEGIN, rigidBegin );
	mContactRigidContainer.emplace( ContactFuncTag::PRESOLVE, rigidPresolve );
	mContactRigidContainer.emplace( ContactFuncTag::END, rigidEnd );
	mContactLiquidContainer.emplace( ContactFuncTag::BEGIN, liquidBegin );
	mContactLiquidContainer.emplace( ContactFuncTag::PRESOLVE, liquidPresolve );
	mContactLiquidContainer.emplace( ContactFuncTag::END, liquidEnd );
}