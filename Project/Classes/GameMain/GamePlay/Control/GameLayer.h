#ifndef _GAME_LAYER_H_
#define _GAME_LAYER_H_

#include "cocos2d.h"
#include "GameControlMediator.h"

/*------------------------------------------------------------*/
//	@class		：	GameLayer
//	@brief		：	ゲームレイヤ
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class GameLayer : public cocos2d::Layer, public GameControlMediator
{
	
protected:
	
	/**
	 *	@brief	コンストラクタ
	 */
	GameLayer() = default;
	
	/**
	 *	@brief	デストラクタ
	 */
	~GameLayer() = default;
	
	/**
	 *	@brief	初期化
	 *	@return	bool	初期化が完了したか否か
	 */
	virtual bool init() override;
	
public:
	
	/**
	 *	@brief	インスタンスの生成
	 *	@return	GameLayer	インスタンス
	 */
	static GameLayer* create();
	
	/**
	 *	@brief	ゲーム開始
	 */
	virtual void gameStart() override;
	
	/**
	 *	@brief	ゲーム中断
	 */
	virtual void gamePause() override;
	
	/**
	 *	@brief	ゲーム終了
	 */
	virtual void gameEnd() override;
};

#endif