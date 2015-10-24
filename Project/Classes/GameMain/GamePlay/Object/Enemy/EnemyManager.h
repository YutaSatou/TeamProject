#ifndef _ENEMY_MANAGER_H_
#define _ENEMY_MANAGER_H_

#include "cocos2d.h"
#include "../Data/IDataLoadListener.h"

class EnemyFactory;

/*------------------------------------------------------------*/
//	@class		：	EnemyManager
//	@brief		：	敵管理者
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class EnemyManager : public cocos2d::Node, public IDataLoadListener
{
	
protected:
	
	/**
	 *	@brief	コンストラクタ
	 */
	EnemyManager();
	
	/**
	 *	@brief	デストラクタ
	 */
	~EnemyManager() = default;
	
public:
	
	/**
	 *	@brief	インスタンスの生成
	 *	@return	EnemyManager	インスタンス
	 */
	static EnemyManager* create();
	
	/**
	 *	@brief	データ読み込み時のコールバック関数
	 *	@param	objectDataContainer	オブジェクトデータコンテナ
	 */
	virtual void onDataLoaded( IDataLoadListener::ObjectDataContainer& objectDataContainer );
	
private:
	
	SharedPtr< EnemyFactory > mEnemyFactory;	//=> 敵生成工場
};

#endif