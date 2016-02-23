#ifndef _LIQUID_FUN_AABB_QUERY_CALLBACK_H_
#define _LIQUID_FUN_AABB_QUERY_CALLBACK_H_

#include "../Core/LiquidFunBox2D.h"
#include <functional>

namespace cocos2d
{
	class Vec2;
	class Size;
}

/*------------------------------------------------------------*/
//	@class		：	LiquidFunAABBQueryCallback
//	@brief		：	LiquidFunのAABBクエリコールバック
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class LiquidFunAABBQueryCallback : public LiquidFunQueryCallback
{
	
public:
	
	/**
	 *	@brief	コンストラクタ
	 */
	LiquidFunAABBQueryCallback();
	
	/**
	 *	@brief	デストラクタ
	 */
	~LiquidFunAABBQueryCallback() = default;
	
	/**
	 *	@brief	更新
	 *	@param	searchPosition	検索する座標
	 *	@param	searchArea		検索する範囲
	 */
	void update( const cocos2d::Vec2& searchPosition, const cocos2d::Size& searchArea );
	
private:
	
	/**
	 *	@brief	フィクスチャを検知した時に呼ばれるコールバック関数
	 *	@param	fixture	検知したフィクスチャ
	 *	@return	bool	検索を続けるか否か
	 */
	virtual bool ReportFixture( LiquidFunFixture* fixture ) override;
	
public:
	
	using ReportFixtureFunc = std::function< bool( LiquidFunFixture* ) >;
	
	ReportFixtureFunc onReportFixture;	//=> フィクスチャを検知した時に呼ばれるコールバック関数
};

#endif