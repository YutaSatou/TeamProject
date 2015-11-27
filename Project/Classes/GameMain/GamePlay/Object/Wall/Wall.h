#ifndef _WALL_H_
#define _WALL_H_

#include "cocos2d.h"
#include "../../LiquidFun/LiquidFunDefine.h"

/*------------------------------------------------------------*/
//	@class		：	Wall
//	@brief		：	画面端の壁
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class Wall : public cocos2d::Node
{
	
protected:
	
	/**
	 *	@brief	コンストラクタ
	 */
	Wall();
	
	/**
	 *	@brief	デストラクタ
	 */
	~Wall() = default;
	
	/**
	 *	@brief	初期化
	 *	@param	start	線の開始座標
	 *	@param	end		線の終了座標
	 *	@return	bool	初期化が完了したか否か
	 */
	bool init( const cocos2d::Vec2& start, const cocos2d::Vec2& end );
	
public:
	
	/**
	 *	@brief	インスタンスの生成
	 *	@param	start	線の開始座標
	 *	@param	end		線の終了座標
	 *	@return	Wall	インスタンス
	 */
	static Wall* create( const cocos2d::Vec2& start, const cocos2d::Vec2& end );
	
private:
	
	/**
	 *	@brief	物理構造の初期化
	 *	@param	start	線の開始座標
	 *	@param	end		線の終了座標
	 */
	void initPhysics( const cocos2d::Vec2& start, const cocos2d::Vec2& end );
	
private:
	
	LiquidFunBody* mBody;	//=> ボディ
};

#endif