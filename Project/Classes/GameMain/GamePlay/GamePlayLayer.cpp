#include "GamePlayLayer.h"
#include "Object/Collision/ContactListener.h"
#include "Control/GameLayer.h"

using namespace cocos2d;

// 初期化
bool GamePlayLayer::init()
{
	if ( !Layer::init() )
	{
		return false;
	}
	
	addChild( ContactListener::create() );
	addChild( GameLayer::create( "Plist/StageData/StageData_01.plist" ) );
	
	return true;
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