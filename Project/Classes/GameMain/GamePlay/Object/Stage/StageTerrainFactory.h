#ifndef _STAGE_TERRAIN_FACTORY_H_
#define _STAGE_TERRAIN_FACTORY_H_

#include "../Data/ObjectFactory.h"
#include "../Data/ObjectDataDefine.h"

class StageTerrain;

/*------------------------------------------------------------*/
//	@class		：	StageTerrainFactory
//	@brief		：	地形生成工場
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class StageTerrainFactory : public ObjectFactory< StageTerrain, ObjectDataPtr >
{
	
public:
	
	/**
	 *	@brief	コンストラクタ
	 */
	StageTerrainFactory();
	
	/**
	 *	@brief	デストラクタ
	 */
	~StageTerrainFactory() = default;
	
private:
	
	/**
	 *	@brief	生成する製品の追加
	 */
	void addProductList();
};

#endif