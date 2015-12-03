#ifndef _CONTACT_RIGID_SENDER_H_
#define _CONTACT_RIGID_SENDER_H_

#include "../../LiquidFun/LiquidFunDefine.h"
#include "Utility/Template/SmartPtr.h"
#include "ContactEventManager.h"

namespace cocos2d
{
	class Node;
}

enum class ContactFuncTag : int;

class ContactSendChecker;

/*------------------------------------------------------------*/
//	@class		：	ContactRigidSender
//	@brief		：	剛体接触通知者
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class ContactRigidSender
{
	
public:
	
	/**
	 *	@brief	コンストラクタ
	 *	@param	callbackContainer	コールバックコンテナ
	 */
	ContactRigidSender( ContactEventManager::CallbackContainer& callbackContainer );
	
	/**
	 *	@brief	デストラクタ
	 */
	~ContactRigidSender() = default;
	
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
	
	ContactEventManager::CallbackContainer&	mCallbackContainer;	//=> コールバックコンテナ
	SharedPtr< ContactSendChecker >			mSendChecker;		//=> 接触通知確認者
};

#endif