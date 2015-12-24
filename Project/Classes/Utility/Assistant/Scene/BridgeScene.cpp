#include "BridgeScene.h"
#include "SceneChanger.h"

using namespace cocos2d;

// コンストラクタ
BridgeScene::BridgeScene()
	: mNextSceneCreateFunc( []() { return nullptr; } )
{
	
}

// 初期化
bool BridgeScene::init( NextSceneCreateFunc func )
{
	if ( !Layer::init() )
	{
		return false;
	}
	
	mNextSceneCreateFunc = func;
	
	scheduleOnce( CC_SCHEDULE_SELECTOR( BridgeScene::next ), 0.2f );
	
	return true;
}

// 次のシーンへの遷移
void BridgeScene::next( float deltaTime )
{
	SceneChanger::switchScene( mNextSceneCreateFunc() );
	
	unschedule( CC_SCHEDULE_SELECTOR( BridgeScene::next ) );
}

// インスタンスの生成
BridgeScene* BridgeScene::create( NextSceneCreateFunc func )
{
	BridgeScene* inst { new BridgeScene() };
	
	if ( inst && inst->init( func ) )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}