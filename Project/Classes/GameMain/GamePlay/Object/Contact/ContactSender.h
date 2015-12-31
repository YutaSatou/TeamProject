#ifndef _CONTACT_SENDER_H_
#define _CONTACT_SENDER_H_

#include "ContactEventManager.h"
#include "Utility/Template/EnumHash.h"

class ContactSendChecker;

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
	 *	@brief	コンテナの初期化
	 */
	void initContainer();
	
private:
	
	using ContactRigid				= std::function< void( std::string, cocos2d::Node*, LiquidFunBody* ) >;
	using ContactLiquid				= std::function< void( std::string, cocos2d::Node*, LiquidFunParticle*, int ) >;
	using ContactRigidContainer		= std::unordered_map< ContactFuncTag, ContactRigid, EnumHash >;
	using ContactLiquidContainer	= std::unordered_map< ContactFuncTag, ContactLiquid, EnumHash >;
	
	ContactEventManager::CallbackContainer&	mCallbackContainer;			//=> コールバックコンテナ
	ContactRigidContainer					mContactRigidContainer;		//=> 剛体接触通知用コンテナ
	ContactLiquidContainer					mContactLiquidContainer;	//=> 液体接触通知用コンテナ
	SharedPtr< ContactSendChecker >			mSendChecker;				//=> 接触通知確認者
};

#endif