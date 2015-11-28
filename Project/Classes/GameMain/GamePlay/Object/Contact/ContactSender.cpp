#include "ContactSender.h"
#include "../../LiquidFun/LiquidFunUserAPI.h"
#include "../../LiquidFun/LiquidFunCoreAPI.h"
#include "ContactFuncTag.h"
#include "ContactCallback.h"
#include "Utility/Template/EnumHash.h"

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
	
	if ( !isSend( nodeA->getName(), nodeB->getName(), contact ) )
	{
		// 通知をしない場合は終了する。
		return;
	}
	
	// オブジェクトに接触を通知する。
	sendContactObject( funcTag, nodeA->getName(), nodeB, bodyB );
	sendContactObject( funcTag, nodeB->getName(), nodeA, bodyA );
}

// オブジェクトへの接触通知
void ContactSender::sendContactObject( const ContactFuncTag& funcTag, const std::string& nodeName, Node* contactNode, LiquidFunBody* contactBody )
{
	static SendFuncMap sendFuncMap =
	{
		{ ContactFuncTag::BEGIN,	[ this ]( const std::string& nodeName, Node* contactNode, LiquidFunBody* contactBody )
			{ mCallbackContainer[ nodeName ]->onContactBegin( contactNode, contactBody );		} },
		{ ContactFuncTag::PRESOLVE,	[ this ]( const std::string& nodeName, Node* contactNode, LiquidFunBody* contactBody )
			{ mCallbackContainer[ nodeName ]->onContactPreSolve( contactNode, contactBody );	} },
		{ ContactFuncTag::END,		[ this ]( const std::string& nodeName, Node* contactNode, LiquidFunBody* contactBody )
			{ mCallbackContainer[ nodeName ]->onContactEnd( contactNode, contactBody );			} },
	};
	
	// オブジェクトに接触を通知する。
	sendFuncMap[ funcTag ]( nodeName, contactNode, contactBody );
}

// 通知するか否か
bool ContactSender::isSend( const std::string& nodeNameA, const std::string& nodeNameB, LiquidFunContact* contact )
{
	// フィルタを取得する。
	const auto& filterA = contact->GetFixtureA()->GetFilterData();
	const auto& filterB = contact->GetFixtureB()->GetFilterData();
	
	// 要素の検索を行うラムダ式を定義する。
	static const auto isFind = [ this ]( const std::string& nodeName )
	{
		return ( mCallbackContainer.find( nodeName ) != mCallbackContainer.end() );
	};
	
	if ( !isFind( nodeNameA ) || !isFind( nodeNameB ) )
	{
		// 要素の検索に失敗している。
		return false;
	}
	
	// 演算結果を返却する。
	return ( ( filterA.categoryBits & mCallbackContainer[ nodeNameB ]->contactBitmask ) != 0 &&
			 ( filterB.categoryBits & mCallbackContainer[ nodeNameA ]->contactBitmask ) != 0 );
}