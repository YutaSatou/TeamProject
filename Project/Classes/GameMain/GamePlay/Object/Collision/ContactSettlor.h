#ifndef _CONTACT_SETTLOR_H_
#define _CONTACT_SETTLOR_H_

#include "ContactCategory.h"
#include "ContactCallback.h"

/*------------------------------------------------------------*/
//	@class		：	ContactSettlor
//	@brief		：	接触設定者
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class ContactSettlor
{
	
public:
	
	using OtherCategory = std::vector< ContactCategory >;
	
public:
	
	/**
	 *	@brief	コンストラクタ
	 *	@param	targetBody		設定するボディ
	 *	@param	isSetupShape	シェイプもボディと同じ設定にするか否か
	 */
	ContactSettlor( cocos2d::PhysicsBody* targetBody, bool isSetupShape = false );
	
	/**
	 *	@brief	デストラクタ
	 */
	~ContactSettlor() = default;
	
	/**
	 *	@brief	カテゴリの設定
	 *	@param	category	ボディに設定するカテゴリ
	 */
	void setupCategory( ContactCategory category );
	
	/**
	 *	@brief	衝突の有効化
	 *			全てのカテゴリと衝突が有効になる。
	 */
	void enableCollision();
	
	/**
	 *	@brief	衝突の有効化
	 *			引数のベクタに追加したカテゴリのみ、衝突が有効になる。
	 *			追加していないカテゴリとの衝突は無効となり、すり抜ける。
	 *	@param	otherCategory	衝突するカテゴリ
	 */
	void enableCustomCollision( OtherCategory otherCategory );
	
	/**
	 *	@brief	接触の有効化
	 *			全てのカテゴリと接触が有効になる。
	 */
	void enableContact();
	
	/**
	 *	@brief	接触の有効化
	 *			引数のベクタに追加したカテゴリのみ、接触が有効になる。
	 *			追加していないカテゴリとの接触は無効となり、コールバックは発信されない。
	 *	@param	otherCategory	接触するカテゴリ
	 */
	void enableCustomContact( OtherCategory otherCategory );
	
	/**
	 *	@brief	接触コールバックの有効化
	 *	@param	nodeName	ノードの名前
	 *	@param	callback	コールバック
	 */
	void enableContactCallback( const std::string& nodeName, ContactCallback::Ptr callback );
	
	/**
	 *	@brief	接触コールバックの無効化
	 *	@param	nodeName	ノードの名前
	 */
	void disableContactCallback( const std::string& nodeName );
	
private:
	
	/**
	 *	@brief	シェイプベクタの巡回
	 *	@param	func	実行する関数
	 */
	void eachShapeVector( std::function< void( cocos2d::PhysicsShape* ) > func );
	
	/**
	 *	@brief	ビットマスクの取得
	 *	@param	otherCategory	変換するカテゴリベクタ
	 *	@return	int				ビットマスク
	 */
	int getBitmask( OtherCategory otherCategory );
	
private:
	
	cocos2d::PhysicsBody*	mTargetBody;	//=> 設定するボディ
	bool					mIsSetupShape;	//=> シェイプもボディと同じ設定にするか否か
};

#endif