#include "GamePlayLayer.h"
#include "LiquidFun/LiquidFunCoreAPI.h"
#include "Object/Contact/ContactListener.h"
#include "Control/GameLayer.h"
#include "User/UI/UILayer.h"

using namespace cocos2d;

// 初期化
bool GamePlayLayer::init()
{
	if ( !Layer::init() )
	{
		return false;
	}
	
	scheduleUpdate();
	
	LiquidFunWorldManager::getInstance().setGravity( Vect( 0.0f, -4.0f ) );
	
	/* addChild( LiquidFunDebugDrawer::create() ); */
	addChild( ContactListener::create() );
	addChild( GameLayer::create( "Plist/StageData/StageData_01.plist" ) );
	addChild( UILayer::create() );
	
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