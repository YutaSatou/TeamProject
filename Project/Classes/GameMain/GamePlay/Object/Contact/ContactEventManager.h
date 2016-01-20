#ifndef _CONTACT_EVENT_MANAGER_H_
#define _CONTACT_EVENT_MANAGER_H_

#include "ContactCallback.h"
#include "Utility/Template/Singleton.h"

enum class ContactFuncTag;

class ContactSender;

/*------------------------------------------------------------*/
//	@class		：	ContactEventManager
//	@brief		：	接触イベント管理者
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class ContactEventManager : public Singleton< ContactEventManager >
{
	
public:
	
	using CallbackContainer = std::unordered_map< std::string, ContactCallback::Ptr >;
	
public:
	
	/**
	 *	@brief	デストラクタ
	 */
	~ContactEventManager();
	
	/**
	 *	@brief	接触イベントコールバック
	 *	@param	funcTag	接触関数のタグ
	 *	@param	contact	接触したオブジェクトの情報
	 */
	void onContactEvent( const ContactFuncTag& funcTag, LiquidFunContact* contact );
	
	/**
	 *	@brief	接触イベントコールバック
	 *	@param	funcTag		接触関数のタグ
	 *	@param	fixture		接触したフィクスチャ
	 *	@param	particle	接触したパーティクル
	 *	@param	index		接触したパーティクルのインデックス
	 */
	void onContactEvent( const ContactFuncTag& funcTag, LiquidFunFixture* fixture, LiquidFunParticle* particle, int index );
	
	/**
	 *	@brief	コールバックの追加
	 *	@param	nodeName	ノードの名前
	 *	@param	callback	追加するコールバック
	 */
	void addCallback( const std::string& nodeName, ContactCallback::Ptr callback );
	
	/**
	 *	@brief	コールバックの削除
	 *	@param	nodeName	ノードの名前
	 */
	void deleteCallback( const std::string& nodeName );
	
private:
	
	/**
	 *	@brief	コンストラクタ
	 */
	ContactEventManager();
	
private:
	
	friend class Singleton< ContactEventManager >;
	
	using ContactSenderPtr = std::shared_ptr< ContactSender >;
	
	CallbackContainer	mCallbackContainer;	//=> コールバックコンテナ
	ContactSenderPtr	mContactSender;		//=> 接触通知者
};

#endif