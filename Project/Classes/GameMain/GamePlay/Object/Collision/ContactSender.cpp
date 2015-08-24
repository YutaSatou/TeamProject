#include "ContactSender.h"

using namespace cocos2d;

// コンストラクタ
ContactSender::ContactSender( CallbackContainer& callbackContainer )
	: mCallbackContainer( callbackContainer )
{
	
}

// 通知
void ContactSender::send( ContactFuncTag funcTag, PhysicsContact& contact )
{
	// 接触したノードを取得する。
	Node* nodeA	= contact.getShapeA()->getBody()->getNode();
	Node* nodeB	= contact.getShapeB()->getBody()->getNode();
	
	if ( !nodeA || !nodeB )
	{
		// 不正なポインタを取得した場合は終了する。
		return;
	}
	
	// オブジェクトに接触を通知する。
	sendContactObject( funcTag, nodeA->getName(), nodeB );
	sendContactObject( funcTag, nodeB->getName(), nodeA );
}

// オブジェクトへの接触通知
void ContactSender::sendContactObject( ContactFuncTag funcTag, const std::string& nodeName, const Node* contactNode )
{
	// 変換用連想配列を用意する。
	static std::unordered_map< int, std::function< void( const std::string&, const Node* ) > > sendFuncMap =
	{
		{ ContactFuncTag::BEGIN,	[ this ]( const std::string& nodeName, const Node* contactNode )
			{ mCallbackContainer[ nodeName ]->onContactBegin( contactNode );	} },
		{ ContactFuncTag::PRESOLVE,	[ this ]( const std::string& nodeName, const Node* contactNode )
			{ mCallbackContainer[ nodeName ]->onContactPreSolve( contactNode );	} },
		{ ContactFuncTag::SEPERATE,	[ this ]( const std::string& nodeName, const Node* contactNode )
			{ mCallbackContainer[ nodeName ]->onContactSeperate( contactNode );	} },
	};
	
	// 要素検索用イテレータを用意する。
	auto findItor = mCallbackContainer.find( nodeName );
	
	if ( findItor != mCallbackContainer.end() )
	{
		// オブジェクトに接触を通知する。
		sendFuncMap[ funcTag ]( nodeName, contactNode );
	}
}