#ifndef _CONTACT_SETTLOR_H_
#define _CONTACT_SETTLOR_H_

#include "ContactCallback.h"
#include "Utility/Template/SmartPtr.h"

/*------------------------------------------------------------*/
//	@class		：	ContactSettlor
//	@brief		：	接触設定者
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class ContactSettlor
{
	
public:
	
	using OtherCategory = std::vector< Contact::Category >;
	
public:
	
	/**
	 *	@brief	コンストラクタ
	 *	@param	targetBody	設定するボディ
	 */
	ContactSettlor( LiquidFunBody* targetBody );
	
	/**
	 *	@brief	デストラクタ
	 */
	~ContactSettlor() = default;
	
	/**
	 *	@brief	カテゴリの設定
	 *	@param	category	ボディに設定するカテゴリ
	 */
	void setupCategory( const Contact::Category& category );
	
	/**
	 *	@brief	衝突するカテゴリの設定
	 *	@param	otherCategory	衝突するカテゴリベクタ
	 */
	void setupCollisionCategory( const OtherCategory& otherCategory = { Contact::Category::ALL_CATEGORY } );
	
	/**
	 *	@brief	接触するカテゴリの設定
	 *	@param	callback		コールバック
	 *	@param	otherCategory	接触するカテゴリベクタ
	 */
	void setupContactCategory( SharedPtr< ContactCallback > callback, const OtherCategory& otherCategory = { Contact::Category::ALL_CATEGORY } );
	
	/**
	 *	@brief	接触コールバックの有効化
	 *	@param	nodeName	ノードの名前
	 *	@param	callback	コールバック
	 */
	void enableContactCallback( const std::string& nodeName, SharedPtr< ContactCallback > callback );
	
	/**
	 *	@brief	接触コールバックの無効化
	 *	@param	nodeName	ノードの名前
	 */
	void disableContactCallback( const std::string& nodeName );
	
private:
	
	/**
	 *	@brief	OR演算
	 *	@param	otherCategory	OR演算を行うカテゴリベクタ
	 *	@return	unsigned short	ビットマスク
	 */
	unsigned short orCalculate( const OtherCategory& otherCategory );
	
private:
	
	LiquidFunBody*			mTargetBody;	//=> 設定するボディ
	LiquidFunContactFilter	mContactFilter;	//=> 接触フィルタ
};

#endif