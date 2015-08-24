#ifndef _CONTACT_SENDER_H_
#define _CONTACT_SENDER_H_

#include "ContactFuncTag.h"
#include "ContactCallback.h"

/*------------------------------------------------------------*/
//	@class		：	ContactSender
//	@brief		：	接触通知者
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class ContactSender
{
	
private:
	
	using CallbackContainer = std::map< std::string, ContactCallback::Ptr >;
	
public:
	
	/**
	 *	@brief	コンストラクタ
	 *	@param	callbackContainer	コールバックコンテナ
	 */
	ContactSender( CallbackContainer& callbackContainer );
	
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
	void sendContactObject( ContactFuncTag funcTag, const std::string& nodeName, const cocos2d::Node* contactNode );
	
private:
	
	CallbackContainer& mCallbackContainer;	//=> コールバックコンテナ
};

#endif