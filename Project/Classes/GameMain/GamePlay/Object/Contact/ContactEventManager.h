#ifndef _CONTACT_EVENT_MANAGER_H_
#define _CONTACT_EVENT_MANAGER_H_

#include "../../LiquidFun/LiquidFunDefine.h"
#include "Utility/Template/Singleton.h"
#include "Utility/Template/SmartPtr.h"
#include <string>
#include <unordered_map>

enum class ContactFuncTag : int;

struct	ContactCallback;
class	ContactSender;

/*------------------------------------------------------------*/
//	@class		：	ContactEventManager
//	@brief		：	接触イベント管理者
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class ContactEventManager : public Singleton< ContactEventManager >
{
	
public:
	
	using CallbackContainer = std::unordered_map< std::string, SharedPtr< ContactCallback > >;
	
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
	ContactEventManager();
	
private:
	
	friend class Singleton< ContactEventManager >;
	
	CallbackContainer			mCallbackContainer;	//=> コールバックコンテナ
	UniquePtr< ContactSender >	mContactSender;		//=> 接触通知者
};

#endif