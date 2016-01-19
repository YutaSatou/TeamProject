#ifndef _STAGE_TERRAIN_H_
#define _STAGE_TERRAIN_H_

#include "cocos2d.h"
#include "../Data/ObjectDataDefine.h"

/**
 *	@brief	地形の種類
 */
enum class StageTerrainType : int
{
	BOX			= 0,
	TRIANGLE	= 1,
	CIRCLE		= 2,
};

/*------------------------------------------------------------*/
//	@class		：	StageTerrain
//	@brief		：	地形
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class StageTerrain : public cocos2d::Sprite
{
	
protected:
	
	/**
	 *	@brief	コンストラクタ
	 */
	StageTerrain() = default;
	
	/**
	 *	@brief	デストラクタ
	 */
	~StageTerrain() = default;
	
	/**
	 *	@brief	初期化
	 *	@param	objectData	オブジェクトデータ
	 *	@param	terrainType	地形の種類
	 *	@return	bool		初期化が完了したか否か
	 */
	bool init( ObjectDataPtr objectData, const StageTerrainType& terrainType );
	
public:
	
	/**
	 *	@brief	インスタンスの生成
	 *	@param	objectData		オブジェクトデータ
	 *	@param	terrainType		地形の種類
	 *	@return	StageTerrain	インスタンス
	 */
	static StageTerrain* create( ObjectDataPtr objectData, const StageTerrainType& terrainType );
	
private:
	
	/**
	 *	@brief	物理構造の初期化
	 *	@param	objectData	オブジェクトデータ
	 *	@param	terrainType	地形の種類
	 */
	void initPhysics( ObjectDataPtr objectData, const StageTerrainType& terrainType );
};

#endif