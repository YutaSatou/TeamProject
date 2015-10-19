#ifndef _CONTACT_SENDER_H_
#define _CONTACT_SENDER_H_

#include "Utility/Template/SmartPtr.h"
#include "ContactFuncTag.h"
#include <map>
#include <string>

namespace cocos2d
{
	class Node;
	class PhysicsContact;
}

class ContactCallback;

/*------------------------------------------------------------*/
//	@class		：	ContactSender
//	@brief		：	接触通知者
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class ContactSender
{
	
private:
	
	using CallbackContainer = std::map< std::string, SharedPtr< ContactCallback > >;
	
public:
	
	/**
	 *	@brief	コンストラクタ
	 *	@param	callbackContainer	コールバックコンテナ
	 */
	ContactSender( CallbackContainer& callbackContainer );
	
	/**
	 *	コピーコンストラクタ( 封印 )
	 */
	ContactSender( const ContactSender& ) = delete;
	
	/**
	 *	代入演算子( 封印 )
	 */
	ContactSender& operator = ( const ContactSender& ) = delete;
	
	/**
	 *	@brief	デストラクタ
	 */
	~ContactSender() = default;
	
	/**
	 *	@brief	通知
	 *	@param	funcTag	接触関数のタグ
	 *	@param	contact	接触したオブジェクトの情報
	 */
	void send( ContactFuncTag funcTag, cocos2d::PhysicsContact& contact );
	
private:
	
	/**
	 *	@brief	オブジェクトへの接触通知
	 *	@param	funcTag		接触関数のタグ
	 *	@param	nodeName	通知するオブジェクトの名前
	 *	@param	contactNode	接触したノードの情報
	 */
	void sendContactObject( ContactFuncTag funcTag, const std::string& nodeName, cocos2d::Node* contactNode );
	
private:
	
	CallbackContainer& mCallbackContainer;	//=> コールバックコンテナ
};

#endif