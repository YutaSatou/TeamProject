#ifndef _STAGE_TERRAIN_H_
#define _STAGE_TERRAIN_H_

#include "cocos2d.h"
#include "../../LiquidFun/LiquidFunDefine.h"
#include "Utility/Template/SmartPtr.h"

struct ObjectData;

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
//	@brief		：	ステージの地形
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class StageTerrain : public cocos2d::Sprite
{
	
protected:
	
	/**
	 *	@brief	コンストラクタ
	 */
	StageTerrain();
	
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
	bool init( SharedPtr< ObjectData > objectData, const StageTerrainType& terrainType );
	
public:
	
	/**
	 *	@brief	インスタンスの生成
	 *	@param	objectData		オブジェクトデータ
	 *	@param	terrainType		地形の種類
	 *	@return	StageTerrain	インスタンス
	 */
	static StageTerrain* create( SharedPtr< ObjectData > objectData, const StageTerrainType& terrainType );
	
private:
	
	/**
	 *	@brief	物理構造の初期化
	 *	@param	terrainType	地形の種類
	 */
	void initPhysics( const StageTerrainType& terrainType );
	
private:
	
	SharedPtr< ObjectData > mObjectData;	//=> オブジェクトデータ
};

#endif