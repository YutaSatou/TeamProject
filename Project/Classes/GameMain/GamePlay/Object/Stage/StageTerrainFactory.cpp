#include "StageTerrainFactory.h"
#include "../Data/ObjectData.h"
#include "StageTerrain.h"

// コンストラクタ
StageTerrainFactory::StageTerrainFactory()
{
	addProductList();
}

// 生成する製品の追加
void StageTerrainFactory::addProductList()
{
	addCreateFunction( "Terrain_Box",		[]( SharedPtr< ObjectData > objectData )
					  { return StageTerrain::create( objectData, StageTerrainType::BOX ); } );
	
	addCreateFunction( "Terrain_Triangle",	[]( SharedPtr< ObjectData > objectData )
					  { return StageTerrain::create( objectData, StageTerrainType::TRIANGLE ); } );
	
	addCreateFunction( "Terrain_Circle",	[]( SharedPtr< ObjectData > objectData )
					  { return StageTerrain::create( objectData, StageTerrainType::CIRCLE ); } );
}