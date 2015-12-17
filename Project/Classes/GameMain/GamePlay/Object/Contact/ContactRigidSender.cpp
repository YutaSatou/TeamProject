#include "ContactRigidSender.h"
#include "../../LiquidFun/LiquidFunUserAPI.h"
#include "../../LiquidFun/LiquidFunCoreAPI.h"
#include "ContactFuncTag.h"
#include "ContactSendChecker.h"
#include "Utility/Template/EnumHash.h"

using namespace cocos2d;

namespace
{
	using SendFunc			= std::function< void( const std::string&, Node*, LiquidFunBody* ) >;
	using SendFuncContainer	= std::unordered_map< ContactFuncTag, SendFunc, EnumHash >;
}

// コンストラクタ
ContactRigidSender::ContactRigidSender( ContactEventManager::CallbackContainer& callbackContainer )
	: mCallbackContainer( callbackContainer )
	, mSendChecker( makeShared< ContactSendChecker >( callbackContainer ) )
{
	
}

// 通知
void ContactRigidSender::send( const ContactFuncTag& funcTag, LiquidFunContact* contact )
{
	// 接触したボディとボディに登録されているノードを取得する。
	LiquidFunBody*	bodyA	= contact->GetFixtureA()->GetBody();
	LiquidFunBody*	bodyB	= contact->GetFixtureB()->GetBody();
	Node*			nodeA	= LiquidFunHelper::getNode( bodyA );
	Node*			nodeB	= LiquidFunHelper::getNode( bodyB );
	
	if ( !nodeA || !nodeB )
	{
		// ボディにノードが登録されていない場合は終了する。
		return;
	}
	
	if ( !mSendChecker->isRigidFilter( contact, nodeA, nodeB ) )
	{
		// フィルタチェックを通過できない場合は終了する。
		return;
	}
	
	// オブジェクトに接触を通知する。
	sendContactObject( funcTag, nodeA->getName(), nodeB, bodyB );
	sendContactObject( funcTag, nodeB->getName(), nodeA, bodyA );
}

// オブジェクトへの接触通知
void ContactRigidSender::sendContactObject( const ContactFuncTag& funcTag, const std::string& nodeName, Node* contactNode, LiquidFunBody* contactBody )
{
	static SendFuncContainer sendFuncContainer =
	{
		{ ContactFuncTag::RIGID_BEGIN,		[ this ]( const std::string& nodeName, Node* contactNode, LiquidFunBody* contactBody )
			{ mCallbackContainer[ nodeName ]->onContactRigidBegin( contactNode, contactBody );		} },
		{ ContactFuncTag::RIGID_PRESOLVE,	[ this ]( const std::string& nodeName, Node* contactNode, LiquidFunBody* contactBody )
			{ mCallbackContainer[ nodeName ]->onContactRigidPreSolve( contactNode, contactBody );	} },
		{ ContactFuncTag::RIGID_END,		[ this ]( const std::string& nodeName, Node* contactNode, LiquidFunBody* contactBody )
			{ mCallbackContainer[ nodeName ]->onContactRigidEnd( contactNode, contactBody );		} },
	};
	
	// オブジェクトに接触を通知する。
	sendFuncContainer[ funcTag ]( nodeName, contactNode, contactBody );
}