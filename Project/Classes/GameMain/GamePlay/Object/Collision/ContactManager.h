#ifndef _CONTACT_MANAGER_H_
#define _CONTACT_MANAGER_H_

#include "Utility/Template/Singleton.h"
#include "Utility/Template/SmartPtr.h"
#include "ContactFuncTag.h"
#include "ContactSender.h"

class ContactCallback;

/*------------------------------------------------------------*/
//	@class		：	ContactManager
//	@brief		：	接触管理者
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class ContactManager : public Singleton< ContactManager >
{
	
private:
	
	using CallbackContainer = std::map< std::string, SharedPtr< ContactCallback > >;
	
public:
	
	/**
	 *	@brief	デストラクタ
	 */
	~ContactManager();
	
	/**
	 *	@brief	接触イベントコールバック
	 *	@param	funcTag	接触関数のタグ
	 *	@param	contact	接触したオブジェクトの情報
	 */
	void onContactEvent( ContactFuncTag funcTag, cocos2d::PhysicsContact& contact );
	
	/**
	 *	@brief	コールバックの追加
	 *	@param	nodeName	ノードの名前
	 *	@param	callback	追加するコールバック
	 */
	void addCallback( const std::string& nodeName, SharedPtr< ContactCallback > callback );
	
	/**
	 *	@brief	コールバックの削除
	 *	@param	nodeName	ノードの名前
	 */
	void deleteCallback( const std::string& nodeName );
	
private:
	
	/**
	 *	@brief	コンストラクタ
	 */
	ContactManager();
	
private:
	
	friend class Singleton< ContactManager >;
	
	CallbackContainer	mCallbackContainer;	//=> コールバックコンテナ
	ContactSender		mContactSender;		//=> 接触通知者
};

#endif