#ifndef _CONTACT_SENDER_H_
#define _CONTACT_SENDER_H_

#include "../../LiquidFun/LiquidFunDefine.h"
#include "ContactEventManager.h"

namespace cocos2d
{
	class Node;
}

enum class ContactFuncTag : int;

struct ContactCallback;

/*------------------------------------------------------------*/
//	@class		：	ContactSender
//	@brief		：	接触通知者
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class ContactSender
{
	
public:
	
	/**
	 *	@brief	コンストラクタ
	 *	@param	callbackContainer	コールバックコンテナ
	 */
	ContactSender( ContactEventManager::CallbackContainer& callbackContainer );
	
	/**
	 *	@brief	デストラクタ
	 */
	~ContactSender() = default;
	
	/**
	 *	@brief	通知
	 *	@param	funcTag	接触関数のタグ
	 *	@param	contact	接触したオブジェクトの情報
	 */
	void send( const ContactFuncTag& funcTag, LiquidFunContact* contact );
	
private:
	
	/**
	 *	@brief	オブジェクトへの接触通知
	 *	@param	funcTag		接触関数のタグ
	 *	@param	nodeName	通知するオブジェクトの名前
	 *	@param	contactNode	接触したノードの情報
	 *	@param	contactBody	接触したボディの情報
	 */
	void sendContactObject( const ContactFuncTag& funcTag, const std::string& nodeName, cocos2d::Node* contactNode, LiquidFunBody* contactBody );
	
private:
	
	ContactEventManager::CallbackContainer& mCallbackContainer;	//=> コールバックコンテナ
};

#endif