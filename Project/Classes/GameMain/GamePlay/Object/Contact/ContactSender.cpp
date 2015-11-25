#include "ContactSender.h"
#include "../../LiquidFun/LiquidFunUserAPI.h"
#include "../../LiquidFun/LiquidFunCoreAPI.h"
#include "Utility/Template/EnumHash.h"
#include "ContactFuncTag.h"
#include "ContactCallback.h"

using namespace cocos2d;

namespace
{
	using SendFunc		= std::function< void( const std::string&, Node*, LiquidFunBody* ) >;
	using SendFuncMap	= std::unordered_map< ContactFuncTag, SendFunc, EnumHash >;
}

// コンストラクタ
ContactSender::ContactSender( ContactEventManager::CallbackContainer& callbackContainer )
	: mCallbackContainer( callbackContainer )
{
	
}

// 通知
void ContactSender::send( const ContactFuncTag& funcTag, LiquidFunContact* contact )
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
	
	// オブジェクトに接触を通知する。
	sendContactObject( funcTag, nodeA->getName(), nodeB, bodyB );
	sendContactObject( funcTag, nodeB->getName(), nodeA, bodyA );
}

// オブジェクトへの接触通知
void ContactSender::sendContactObject( const ContactFuncTag& funcTag, const std::string& nodeName, Node* contactNode, LiquidFunBody* body )
{
	static SendFuncMap sendFuncMap =
	{
		{ ContactFuncTag::BEGIN,	[ this ]( const std::string& nodeName, Node* contactNode, LiquidFunBody* body )
			{ mCallbackContainer[ nodeName ]->onContactBegin( contactNode, body );		} },
		{ ContactFuncTag::PRESOLVE,	[ this ]( const std::string& nodeName, Node* contactNode, LiquidFunBody* body )
			{ mCallbackContainer[ nodeName ]->onContactPreSolve( contactNode, body );	} },
		{ ContactFuncTag::END,		[ this ]( const std::string& nodeName, Node* contactNode, LiquidFunBody* body )
			{ mCallbackContainer[ nodeName ]->onContactEnd( contactNode, body );		} },
	};
	
	// 要素検索用イテレータを用意する。
	auto findItor = mCallbackContainer.find( nodeName );
	
	if ( findItor != mCallbackContainer.end() )
	{
		// オブジェクトに接触を通知する。
		sendFuncMap[ funcTag ]( nodeName, contactNode, body );
	}
}