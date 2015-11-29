#ifndef _GAMEPLAY_LAYER_H_
#define _GAMEPLAY_LAYER_H_

#include "cocos2d.h"

/*------------------------------------------------------------*/
//	@class		：	GamePlayLayer
//	@brief		：	ゲームプレイレイヤ
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class GamePlayLayer : public cocos2d::Layer
{
	
protected:
	
	/**
	 *	@brief	コンストラクタ
	 */
	GamePlayLayer() = default;
	
	/**
	 *	@brief	デストラクタ
	 */
	~GamePlayLayer() = default;
	
	/**
	 *	@brief	初期化
	 *	@return	bool	初期化が完了したか否か
	 */
	virtual bool init() override;
	
	/**
	 *	@brief	更新
	 *	@param	deltaTime	デルタ時間
	 */
	virtual void update( float deltaTime ) override;
	
public:
	
	/**
	 *	@brief	インスタンスの生成
	 *	@return	GamePlayLayer	インスタンス
	 */
	static GamePlayLayer* create();
};

#endif