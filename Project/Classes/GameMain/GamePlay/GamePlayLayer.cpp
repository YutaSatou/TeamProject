#include "GamePlayLayer.h"
#include "LiquidFun/LiquidFunWorldManager.h"
#include "LiquidFun/Debug/LiquidFunDebugDrawer.h"
#include "Control/GameLayer.h"

using namespace cocos2d;

// 初期化
bool GamePlayLayer::init()
{
	if ( !Layer::init() )
	{
		return false;
	}
	
	scheduleUpdate();
	
	addChild( LiquidFunDebugDrawer::create() );
	addChild( GameLayer::create( "Plist/StageData/StageData_01.plist" ) );
	
	return true;
}

// 更新
void GamePlayLayer::update( float deltaTime )
{
	Layer::update( deltaTime );
	
	LiquidFunWorldManager::getInstance().update();
}

// インスタンスの生成
GamePlayLayer* GamePlayLayer::create()
{
	GamePlayLayer* inst = new GamePlayLayer();
	
	if ( inst && inst->init() )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}