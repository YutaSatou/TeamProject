#include "EnemyManager.h"
#include "EnemyFactory.h"
#include "../Data/ObjectData.h"

using namespace cocos2d;

// コンストラクタ
EnemyManager::EnemyManager()
	: mEnemyFactory( makeShared< EnemyFactory >() )
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
void EnemyManager::onDataLoaded( IDataLoadListener::ObjectDataContainer& objectDataContainer )
{
	std::string		key		= "";
	std::string		name	= "";
	int				number	= 0;
	
	std::for_each( objectDataContainer.begin(), objectDataContainer.end(), [ this, &key, &name, &number ]( SharedPtr< ObjectData > objectData )
	{
		// テクスチャの名前をキーとして使用する。
		key = mEnemyFactory->extractFileName( objectData->textureName );
		
		if ( !mEnemyFactory->isEmptyElement( key ) )
		{
			// テクスチャの名前と識別用の数字をオブジェクトの名前として使用する。
			name = key + StringUtils::toString( number );
			
			// 敵を生成して自身の子ノードとして追加する。
			Node* enemy = mEnemyFactory->createObject( key, objectData, name );
			addChild( enemy );
			
			++number;
		}
	} );
}