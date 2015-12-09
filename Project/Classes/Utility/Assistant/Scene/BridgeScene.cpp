#include "BridgeScene.h"
#include "SceneChanger.h"

using namespace cocos2d;

// コンストラクタ
BridgeScene::BridgeScene()
	: mNextSceneCreateFunc( []() { return nullptr; } )
{
	
}

// 初期化
bool BridgeScene::init( const NextSceneCreateFunc& func )
{
	if ( !Layer::init() )
	{
		return false;
	}
	
	mNextSceneCreateFunc = func;
	
	schedule( CC_SCHEDULE_SELECTOR( BridgeScene::next ) );
	
	return true;
}

// 次のシーンへの遷移
void BridgeScene::next( float deltaTime )
{
	// 初回フレームでシーンを変更する。
	SceneChanger::switchScene( mNextSceneCreateFunc() );
	
	// スケジュール登録を解除する。
	unschedule( CC_SCHEDULE_SELECTOR( BridgeScene::next ) );
}

// インスタンスの生成
BridgeScene* BridgeScene::create( const NextSceneCreateFunc& func )
{
	BridgeScene* inst = new BridgeScene();
	
	if ( inst && inst->init( func ) )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}