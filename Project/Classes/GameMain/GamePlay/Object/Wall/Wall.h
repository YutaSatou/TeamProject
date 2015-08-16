#ifndef _WALL_H_
#define _WALL_H_

#include "cocos2d.h"

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
	 *	@return	bool	初期化が完了したか否か
	 */
	virtual bool init() override;
	
public:
	
	/**
	 *	@brief	インスタンスの生成
	 *	@return	Wall	インスタンス
	 */
	static Wall* create();
	
private:
	
	/**
	 *	@brief	物理構造の初期化
	 */
	void initPhysics();
	
	/**
	 *	@brief	シェイプの装着
	 *	@param	body	シェイプを装着するボディ
	 *	@param	start	線の開始座標
	 *	@param	end		線の終了座標
	 */
	void attachShape( cocos2d::PhysicsBody* body, const cocos2d::Vec2& start, const cocos2d::Vec2& end );
};

#endif