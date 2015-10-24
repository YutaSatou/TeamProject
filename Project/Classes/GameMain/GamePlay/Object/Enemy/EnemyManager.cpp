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
	unsigned int	number	= 0;
	
	std::for_each( objectDataContainer.begin(), objectDataContainer.end(), [ this, &key, &name, &number ]( SharedPtr< ObjectData > objectData )
	{
		// テクスチャの名前をキーとして使用する。
		key = mEnemyFactory->extractFileName( objectData->textureName );
		
		if ( !mEnemyFactory->isEmptyElement( key ) )
		{
			// オブジェクトの名前に識別用の数字を割り当てる。
			name += std::to_string( number );
			
			// 敵を生成して自身の子ノードとして追加する。
			Node* enemy = mEnemyFactory->createObject( key, objectData, name );
			addChild( enemy );
			
			++number;
		}
	} );
}