#ifndef _PLAYER_MANAGER_H_
#define _PLAYER_MANAGER_H_

#include "cocos2d.h"
#include "../Data/ObjectDataPtr.h"

class Player;

/*------------------------------------------------------------*/
//	@class		：	PlayerManager
//	@brief		：	プレイヤ管理者
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class PlayerManager : public cocos2d::Node
{
	
protected:
	
	/**
	 *	@brief	コンストラクタ
	 */
	PlayerManager();
	
	/**
	 *	@brief	デストラクタ
	 */
	~PlayerManager() = default;
	
public:
	
	/**
	 *	@brief	インスタンスの生成
	 *	@return	PlayerManager	インスタンス
	 */
	static PlayerManager* create();
	
	/**
	 *	@brief	データ読み込み時のコールバック関数
	 *	@param	objectData	オブジェクトデータ
	 */
	void onDataLoaded( ObjectDataPtr objectData );
	
	/**
	 *	@brief	ゲーム開始時のコールバック関数
	 */
	void onGameStart();
	
private:
	
	Player*	mPlayer;			// プレイヤ
	bool	mIsPlayerCreated;	// プレイヤを生成したか否か
};

#endif