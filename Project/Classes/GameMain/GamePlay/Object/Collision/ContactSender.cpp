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
void ContactSender::sendContactObject( ContactFuncTag funcTag, const std::string& nodeName, Node* contactNode )
{
	using SendFunc		= std::function< void( const std::string&, Node* ) >;
	using SendFuncMap	= std::unordered_map< int, SendFunc >;
	
	static SendFuncMap sendFuncMap =
	{
		{ ContactFuncTag::CONTACT_FUNC_BEGIN,		[ this ]( const std::string& nodeName, Node* contactNode )
			{ mCallbackContainer[ nodeName ]->onContactBegin( contactNode );	} },
		{ ContactFuncTag::CONTACT_FUNC_PRESOLVE,	[ this ]( const std::string& nodeName, Node* contactNode )
			{ mCallbackContainer[ nodeName ]->onContactPreSolve( contactNode );	} },
		{ ContactFuncTag::CONTACT_FUNC_SEPERATE,	[ this ]( const std::string& nodeName, Node* contactNode )
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