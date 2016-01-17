#ifndef _STAGE_TERRAIN_MANAGER_H_
#define _STAGE_TERRAIN_MANAGER_H_

#include "cocos2d.h"
#include "../Data/ObjectDataPtr.h"

class StageTerrainFactory;

/*------------------------------------------------------------*/
//	@class		：	StageTerrainManager
//	@brief		：	地形管理者
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class StageTerrainManager : public cocos2d::Node
{
	
protected:
	
	/**
	 *	@brief	コンストラクタ
	 */
	StageTerrainManager();
	
	/**
	 *	@brief	デストラクタ
	 */
	~StageTerrainManager() = default;
	
public:
	
	/**
	 *	@brief	インスタンスの生成
	 *	@return	StageTerrainManager	インスタンス
	 */
	static StageTerrainManager* create();
	
	/**
	 *	@brief	データ読み込み時のコールバック関数
	 *	@param	objectData	オブジェクトデータ
	 */
	void onDataLoaded( ObjectDataPtr objectData );
	
private:
	
	/**
	 *	@brief	地形の追加
	 *	@param	objectData	オブジェクトデータ
	 *	@param	key			地形の生成に必要なキー
	 */
	void addStageTerrain( ObjectDataPtr objectData, const std::string& key );
	
private:
	
	using StageTerrainFactoryPtr = std::shared_ptr< StageTerrainFactory >;
	
	StageTerrainFactoryPtr mStageTerrainFactory;	//=> 地形生成工場
};

#endif