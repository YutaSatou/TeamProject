#ifndef _LIQUID_FUN_BODY_DESC_CREATOR_H_
#define _LIQUID_FUN_BODY_DESC_CREATOR_H_

#include "../Core/LiquidFunBox2D.h"
#include "math/Vec2.h"

namespace cocos2d
{
	class Size;
	class Node;
}

struct LiquidFunMaterial;

/*------------------------------------------------------------*/
//	@class		：	LiquidFunBodyDescCreator
//	@brief		：	LiquidFunのボディ設定記述子生成者
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class LiquidFunBodyDescCreator
{
	
public:
	
	/**
	 *	@brief	コンストラクタ
	 */
	LiquidFunBodyDescCreator() = default;
	
	/**
	 *	@brief	デストラクタ
	 */
	~LiquidFunBodyDescCreator() = default;
	
	/**
	 *	@brief	ボディ設定記述子の生成
	 *	@param	registerNode		ボディに登録するノード
	 *	@param	bodyType			ボディの種類
	 *	@return	LiquidFunBodyDesc	ボディ設定記述子
	 */
	LiquidFunBodyDesc createBodyDesc( cocos2d::Node* registerNode, const LiquidFunBodyType& bodyType );
	
	/**
	 *	@brief	フィクスチャ設定記述子の生成
	 *	@param	shape					フィクスチャに設定するシェイプ
	 *	@param	material				フィクスチャに設定するマテリアル
	 *	@return	LiquidFunFixtureDesc	フィクスチャ設定記述子
	 */
	LiquidFunFixtureDesc createFixtureDesc( const LiquidFunShape* shape, const LiquidFunMaterial& material );
	
	/**
	 *	@brief	フィクスチャ設定記述子( 円形状 )の生成
	 *	@param	radius					円の半径
	 *	@param	material				マテリアル
	 *	@param	offset					オフセット座標
	 *	@return	LiquidFunFixtureDesc	フィクスチャ設定記述子
	 */
	LiquidFunFixtureDesc createCircle( float radius, const LiquidFunMaterial& material, const cocos2d::Vec2& offset = cocos2d::Vec2::ZERO );
	
	/**
	 *	@brief	フィクスチャ設定記述子( 箱形状 )の生成
	 *	@param	size					箱の大きさ
	 *	@param	material				マテリアル
	 *	@return	LiquidFunFixtureDesc	フィクスチャ設定記述子
	 */
	LiquidFunFixtureDesc createBox( const cocos2d::Size& size, const LiquidFunMaterial& material );
	
	/**
	 *	@brief	フィクスチャ設定記述子( 線形状 )の生成
	 *	@param	start					線の開始座標
	 *	@param	end						線の終了座標
	 *	@param	lineWidth				線の幅
	 *	@param	material				マテリアル
	 *	@param	offset					オフセット座標
	 *	@return	LiquidFunFixtureDesc	フィクスチャ設定記述子
	 */
	LiquidFunFixtureDesc createSegment( const cocos2d::Vec2& start, const cocos2d::Vec2& end, float lineWidth, const LiquidFunMaterial& material, const cocos2d::Vec2& offset = cocos2d::Vec2::ZERO );
	
	/**
	 *	@brief	フィクスチャ設定記述子( エッジ線形状 )の生成
	 *	@param	start					線の開始座標
	 *	@param	end						線の終了座標
	 *	@param	material				マテリアル
	 *	@return	LiquidFunFixtureDesc	フィクスチャ設定記述子
	 */
	LiquidFunFixtureDesc createEdgeSegment( const cocos2d::Vec2& start, const cocos2d::Vec2& end, const LiquidFunMaterial& material );
	
	/**
	 *	@brief	フィクスチャ設定記述子( 多角形形状 )の生成
	 *	@param	points					頂点データ
	 *	@param	pointCount				頂点数
	 *	@param	material				マテリアル
	 *	@return	LiquidFunFixtureDesc	フィクスチャ設定記述子
	 */
	LiquidFunFixtureDesc createPolygon( const cocos2d::Vec2* points, int pointCount, const LiquidFunMaterial& material );
};

#endif