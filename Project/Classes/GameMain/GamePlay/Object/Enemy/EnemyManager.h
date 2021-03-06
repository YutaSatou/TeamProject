#ifndef _ENEMY_MANAGER_H_
#define _ENEMY_MANAGER_H_

#include "cocos2d.h"
#include "../Data/ObjectDataDefine.h"

class EnemyFactory;

/*------------------------------------------------------------*/
//	@class		：	EnemyManager
//	@brief		：	敵管理者
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class EnemyManager : public cocos2d::Node
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
	 *	@param	objectData	オブジェクトデータ
	 */
	void onDataLoaded( ObjectDataPtr objectData );
	
private:
	
	/**
	 *	@brief	オブジェクト管理数の取得
	 *	@return	size_t	管理数
	 */
	std::size_t getObjectManageCount() const;
	
private:
	
	using EnemyFactoryPtr = std::shared_ptr< EnemyFactory >;
	
	EnemyFactoryPtr mEnemyFactory;	//=> 敵生成工場
};

#endif