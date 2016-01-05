#include "EnemyManager.h"
#include "../Data/ObjectData.h"
#include "EnemyFactory.h"

using namespace cocos2d;

// コンストラクタ
EnemyManager::EnemyManager()
	: mEnemyFactory( makeShared< EnemyFactory >() )
{
	
}

// インスタンスの生成
EnemyManager* EnemyManager::create()
{
	EnemyManager* inst { new EnemyManager() };
	
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
	const std::string& key { mEnemyFactory->extractFileName( objectData->textureName ) };
	
	if ( !mEnemyFactory->isEmptyElement( key ) )
	{
		// テクスチャの名前と、オブジェクト管理数をオブジェクトの名前として使用する。
		const std::string& name { key + StringUtils::toString( getObjectManageCount() ) };
		
		// 自身の子ノードとして追加する。
		Node* enemy { mEnemyFactory->createObject( key, objectData, name ) };
		addChild( enemy );
	}
}

// オブジェクト管理数の取得
std::size_t EnemyManager::getObjectManageCount() const
{
	return getChildrenCount();
}