#ifndef _LIQUID_FUN_BODY_SETTLOR_H_
#define _LIQUID_FUN_BODY_SETTLOR_H_

#include "../LiquidFunDefine.h"

/*------------------------------------------------------------*/
//	@class		：	LiquidFunBodySettlor
//	@brief		：	LiquidFunのボディ設定者
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class LiquidFunBodySettlor
{
	
public:
	
	/**
	 *	@brief	コンストラクタ
	 */
	LiquidFunBodySettlor() = delete;
	
	/**
	 *	@brief	デストラクタ
	 */
	~LiquidFunBodySettlor() = delete;
	
	/**
	 *	@brief	空ボディの装着
	 *	@param	bodyDesc		ボディ設定記述子
	 *	@return	LiquidFunBody	ボディのインスタンス
	 */
	static LiquidFunBody* attachEmptyBody( const LiquidFunBodyDesc& bodyDesc );
	
	/**
	 *	@brief	ボディの装着
	 *	@param	bodyDesc		ボディ設定記述子
	 *	@param	fixtureDesc		フィクスチャ設定記述子
	 *	@return	LiquidFunBody	ボディのインスタンス
	 */
	static LiquidFunBody* attachBody( const LiquidFunBodyDesc& bodyDesc, LiquidFunFixtureDesc& fixtureDesc );
	
	/**
	 *	@brief	フィクスチャの装着
	 *	@param	body				フィクスチャを装着するボディ
	 *	@param	fixtureDesc			フィクスチャ設定記述子
	 *	@return	LiquidFunFixture	フィクスチャのインスタンス
	 */
	static LiquidFunFixture* attachFixture( LiquidFunBody* body, LiquidFunFixtureDesc& fixtureDesc );
	
	/**
	 *	@brief	ボディの装着解除
	 *	@param	body	装着解除するボディ
	 */
	static void detachBody( LiquidFunBody* body );
	
	/**
	 *	@brief	フィクスチャの装着解除
	 *	@param	body	フィクスチャを装着しているボディ
	 *	@param	fixture	装着解除するフィクスチャ
	 */
	static void detachFixture( LiquidFunBody* body, LiquidFunFixture* fixture );
};

#endif