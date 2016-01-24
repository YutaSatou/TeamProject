#ifndef _GOAL_H_
#define _GOAL_H_

#include "cocos2d.h"

/*------------------------------------------------------------*/
//	@class		：	Goal
//	@brief		：	ゴール
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class Goal : public cocos2d::Sprite
{
	
protected:
	
	/**
	 *	@brief	コンストラクタ
	 */
	Goal() = default;
	
	/**
	 *	@brief	デストラクタ
	 */
	~Goal() = default;
	
	/**
	 *	@brief	初期化
	 *	@param	position	設置する座標
	 *	@return	bool		初期化が完了したか否か
	 */
	bool init( const cocos2d::Vec2& position );
	
public:
	
	/**
	 *	@brief	インスタンスの生成
	 *	@param	position	設置する座標
	 *	@return	Goal		インスタンス
	 */
	static Goal* create( const cocos2d::Vec2& position );
	
private:
	
	/**
	 *	@brief	物理構造の初期化
	 */
	void initPhysics();
	
	/**
	 *	@brief	ボディの生成
	 *	@param	registerNode	ボディを登録するノード
	 *	@param	plistFilePath	プロパティリストファイルのパス
	 */
	void createBody( cocos2d::Node* registerNode, const std::string& plistFilePath );
};

#endif