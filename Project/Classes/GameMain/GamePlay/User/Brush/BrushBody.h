#ifndef _BRUSH_BODY_H_
#define _BRUSH_BODY_H_

#include "../../LiquidFun/LiquidFunDefine.h"
#include <memory>
#include <vector>
#include <functional>

namespace cocos2d
{
	class Vec2;
	class Node;
}

class LiquidFunBodyDescCreator;

/*------------------------------------------------------------*/
//	@class		：	BrushBody
//	@brief		：	ブラシ用のボディ
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class BrushBody
{
	
public:
	
	/**
	 *	@brief	コンストラクタ
	 */
	BrushBody();
	
	/**
	 *	@brief	デストラクタ
	 */
	~BrushBody();
	
	/**
	 *	@brief	線形状のフィクスチャ設定記述子の追加
	 *	@param	start		線の開始地点
	 *	@param	end			線の終了地点
	 *	@param	lineWidth	線の幅
	 */
	void pushSegment( const cocos2d::Vec2& start, const cocos2d::Vec2& end, float lineWidth );
	
	/**
	 *	@brief	線と線を結ぶフィクスチャ設定記述子の追加
	 *	@param	position	追加する座標
	 *	@param	lineWidth	線の幅
	 */
	void pushConnection( const cocos2d::Vec2& position, float lineWidth );
	
	/**
	 *	@brief	コンテナの解放
	 */
	void clear();
	
	/**
	 *	@brief	コンテナが空か否か
	 *	@return	bool	コンテナが空か否か
	 */
	bool isEmpty() const;
	
	/**
	 *	@brief	ボディの装着
	 *	@param	registerNode	ボディに登録するノード
	 */
	void attachBody( cocos2d::Node* registerNode );
	
private:
	
	/**
	 *	@brief	コンテナの巡回
	 *	@param	func	実行する関数
	 */
	void each( std::function< void( LiquidFunFixtureDesc& ) > func );
	
private:
	
	using FixtureDescContainer			= std::vector< LiquidFunFixtureDesc >;
	using LiquidFunBodyDescCreatorPtr	= std::shared_ptr< LiquidFunBodyDescCreator >;
	
	FixtureDescContainer		mFixtureDescContainer;	//=> フィクスチャ設定記述子のコンテナ
	LiquidFunBodyDescCreatorPtr	mBodyDescCreator;		//=> ボディ設定記述子生成者
};

#endif