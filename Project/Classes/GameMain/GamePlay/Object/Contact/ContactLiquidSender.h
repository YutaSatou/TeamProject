#ifndef _CONTACT_LIQUID_SENDER_H_
#define _CONTACT_LIQUID_SENDER_H_

#include "../../LiquidFun/LiquidFunDefine.h"
#include "Utility/Template/SmartPtr.h"
#include "ContactEventManager.h"

namespace cocos2d
{
	class Node;
}

enum class ContactFuncTag : int;

struct	ContactCallback;
class	ContactSendChecker;

/*------------------------------------------------------------*/
//	@class		：	ContactLiquidSender
//	@brief		：	液体接触通知者
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class ContactLiquidSender
{
	
private:
	
	using ContactInfo = std::tuple< cocos2d::Node*, LiquidFunBody*, LiquidFunParticle*, int >;
	
public:
	
	/**
	 *	@brief	コンストラクタ
	 *	@param	callbackContainer	コールバックコンテナ
	 */
	ContactLiquidSender( ContactEventManager::CallbackContainer& callbackContainer );
	
	/**
	 *	@brief	デストラクタ
	 */
	~ContactLiquidSender() = default;
	
	/**
	 *	@brief	通知
	 *	@param	funcTag		接触関数のタグ
	 *	@param	fixture		接触したフィクスチャ
	 *	@param	particle	接触したパーティクル
	 *	@param	index		接触したパーティクルのインデックス
	 */
	void send( const ContactFuncTag& funcTag, LiquidFunFixture* fixture, LiquidFunParticle* particle, int index );
	
private:
	
	/**
	 *	@brief	オブジェクトへの接触通知
	 *	@param	funcTag		接触関数のタグ
	 *	@param	nodeName	通知するオブジェクトの名前
	 *	@param	contact		接触情報タプル
	 */
	void sendContactObject( const ContactFuncTag& funcTag, const std::string& nodeName, const ContactInfo& contact );
	
private:
	
	ContactEventManager::CallbackContainer&	mCallbackContainer;	//=> コールバックコンテナ
	SharedPtr< ContactSendChecker >			mSendChecker;		//=> 接触通知確認者
};

#endif