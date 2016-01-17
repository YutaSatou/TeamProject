#include "EnemyManager.h"
#include "../Data/ObjectData.h"
#include "EnemyFactory.h"

using namespace cocos2d;

// コンストラクタ
EnemyManager::EnemyManager()
	: mEnemyFactory( std::make_shared< EnemyFactory >() )
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
void EnemyManager::onDataLoaded( ObjectDataPtr objectData )
{
	// テクスチャの名前をキーとして使用する。
	const std::string& key { mEnemyFactory->extractFileName( objectData->textureName ) };
	
	if ( mEnemyFactory->isRegisterElement( key ) )
	{
		// テクスチャの名前と、オブジェクト管理数をオブジェクトの名前として使用する。
		const std::string& name { key + ":" + StringUtils::toString( getObjectManageCount() ) };
		
		// 敵を生成して、自身の子ノードとして追加する。
		Node* enemy { mEnemyFactory->createObject( key, objectData, name ) };
		addChild( enemy );
	}
}

// オブジェクト管理数の取得
std::size_t EnemyManager::getObjectManageCount() const
{
	return getChildrenCount();
}