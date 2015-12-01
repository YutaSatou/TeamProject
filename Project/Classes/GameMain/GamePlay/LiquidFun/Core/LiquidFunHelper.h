#ifndef _LIQUID_FUN_HELPER_H_
#define _LIQUID_FUN_HELPER_H_

#include "cocos2d.h"
#include "LiquidFunBox2D.h"

/*------------------------------------------------------------*/
//	@class		：	LiquidFunHelper
//	@brief		：	LiquidFunの変換補助
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class LiquidFunHelper
{
	
private:
	
	using VoidPointer = void*;
	
public:
	
	/**
	 *	@brief	コンストラクタ
	 */
	LiquidFunHelper() = delete;
	
	/**
	 *	@brief	デストラクタ
	 */
	~LiquidFunHelper() = delete;
	
	/**
	 *	@brief	ピクセルからメータへの単位変換
	 *	@param	pixsel			ピクセル
	 *	@return	LiquidFunVec2	メータ
	 */
	static LiquidFunVec2 toMeter( const cocos2d::Vec2& pixsel );
	
	/**
	 *	@brief	ピクセルからメータへの単位変換
	 *	@param	pixsel	ピクセル
	 *	@return	float	メータ
	 */
	static float toMeter( float pixsel );
	
	/**
	 *	@brief	メータからピクセルへの単位変換
	 *	@param	meter	メータ
	 *	@return	Vec2	ピクセル
	 */
	static cocos2d::Vec2 toPixsel( const LiquidFunVec2& meter );
	
	/**
	 *	@brief	メータからピクセルへの単位変換
	 *	@param	meter	メータ
	 *	@return	float	ピクセル
	 */
	static float toPixsel( float meter );
	
	/**
	 *	@brief	ノードの取得
	 *	@param	body	ノードを登録しているボディ
	 *	@return	Node	ノードのインスタンス
	 */
	static cocos2d::Node* getNode( LiquidFunBody* body );
	
	/**
	 *	@brief	ノードの取得
	 *	@param	userData	ユーザデータ
	 *	@return	Node		ノードのインスタンス
	 */
	static cocos2d::Node* getNode( VoidPointer* userData );
	
public:
	
	static const float PTM_RATIO;	//=> Box2D上の1m = Cocos2d-x上の32px
};

#endif