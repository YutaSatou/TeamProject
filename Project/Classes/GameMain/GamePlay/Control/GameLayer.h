#ifndef _GAME_LAYER_H_
#define _GAME_LAYER_H_

#include "cocos2d.h"
#include "GameControlMediator.h"

class PlayerManager;
class EnemyManager;
class StageTerrainManager;

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
	GameLayer();
	
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
	 *	@param	plistFilePath	プロパティリストファイルのパス
	 *	@return	GameLayer		インスタンス
	 */
	static GameLayer* create( const std::string& plistFilePath );
	
	/**
	 *	@brief	ゲーム開始
	 */
	virtual void gameStart() override;
	
	/**
	 *	@brief	ゲーム終了
	 */
	virtual void gameEnd() override;
	
private:
	
	/**
	 *	@brief	ステージの初期化
	 *	@param	plistFilePath	プロパティリストファイルのパス
	 */
	void initStage( const std::string& plistFilePath );
	
private:
	
	PlayerManager*			mPlayerManager;			// プレイヤ管理者
	EnemyManager*			mEnemyManager;			// 敵管理者
	StageTerrainManager*	mStageTerrainManager;	// 地形管理者
};

#endif