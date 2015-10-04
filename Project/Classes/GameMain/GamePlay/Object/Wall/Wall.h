#ifndef _WALL_H_
#define _WALL_H_

#include "cocos2d.h"
#include "../Collision/ContactCategory.h"

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
	Wall() = default;
	
	/**
	 *	@brief	デストラクタ
	 */
	~Wall() = default;
	
	/**
	 *	@brief	初期化
	 *	@param	category	設定するカテゴリ
	 *	@param	start		線の開始座標
	 *	@param	end			線の終了座標
	 *	@return	bool		初期化が完了したか否か
	 */
	bool init( const ContactCategory& category, const cocos2d::Vec2& start, const cocos2d::Vec2& end );
	
public:
	
	/**
	 *	@brief	インスタンスの生成
	 *	@param	category	設定するカテゴリ
	 *	@param	start		線の開始座標
	 *	@param	end			線の終了座標
	 *	@return	Wall		インスタンス
	 */
	static Wall* create( const ContactCategory& category, const cocos2d::Vec2& start, const cocos2d::Vec2& end );
	
private:
	
	/**
	 *	@brief	物理構造の初期化
	 *	@param	start	線の開始座標
	 *	@param	end		線の終了座標
	 */
	void initPhysics( const cocos2d::Vec2& start, const cocos2d::Vec2& end );
	
	/**
	 *	@brief	ボディの設定
	 *	@param	body	設定するボディ
	 */
	void setupPhysicsBody( cocos2d::PhysicsBody* body );
	
private:
	
	ContactCategory	mCategory;	//=> カテゴリ
};

#endif