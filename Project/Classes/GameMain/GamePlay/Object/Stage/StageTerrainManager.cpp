#include "StageTerrainManager.h"
#include "../Data/ObjectData.h"
#include "StageTerrainFactory.h"
#include "StageTerrain.h"
#include <cstring>

using namespace cocos2d;

// コンストラクタ
StageTerrainManager::StageTerrainManager()
	: mStageTerrainFactory( std::make_shared< StageTerrainFactory >() )
{
	
}

// インスタンスの生成
StageTerrainManager* StageTerrainManager::create()
{
	StageTerrainManager* inst { new StageTerrainManager() };
	
	if ( inst && inst->init() )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

// データ読み込み時のコールバック関数
void StageTerrainManager::onDataLoaded( ObjectDataPtr objectData )
{
	addStageTerrain( objectData, "Terrain_Box"		);
	addStageTerrain( objectData, "Terrain_Triangle"	);
	addStageTerrain( objectData, "Terrain_Circle"	);
}

// 地形の追加
void StageTerrainManager::addStageTerrain( ObjectDataPtr objectData, const std::string& key )
{
	if ( std::strstr( objectData->textureName.c_str(), key.c_str() ) )
	{
		// テクスチャの名前にキーが含まれている場合、地形を生成する。
		StageTerrain* stageTerrain { mStageTerrainFactory->createObject( key, objectData ) };
		
		// 自身の子ノードとして追加する。
		addChild( stageTerrain );
	}
}