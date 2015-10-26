#include "EnemyManager.h"
#include "../Data/ObjectData.h"
#include "EnemyFactory.h"

using namespace cocos2d;

// コンストラクタ
EnemyManager::EnemyManager()
	: mEnemyFactory( makeShared< EnemyFactory >() )
	, mObjectManageCount( 0 )
{
	
}

// インスタンスの生成
EnemyManager* EnemyManager::create()
{
	EnemyManager* inst = new EnemyManager();
	
	if ( inst && inst->init() )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

// データ読み込み時のコールバック関数
void EnemyManager::onDataLoaded( SharedPtr< ObjectData > objectData )
{
	// テクスチャの名前をキーとして使用する。
	std::string key = mEnemyFactory->extractFileName( objectData->textureName );
	
	if ( !mEnemyFactory->isEmptyElement( key ) )
	{
		// テクスチャの名前とオブジェクト管理用数値をオブジェクトの名前として使用する。
		std::string name = key + StringUtils::toString( mObjectManageCount );
		
		// 敵を生成して自身の子ノードとして追加する。
		Node* enemy = mEnemyFactory->createObject( key, objectData, name );
		addChild( enemy );
		
		++mObjectManageCount;
	}
}