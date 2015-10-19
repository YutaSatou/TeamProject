#include "GamePlayLayer.h"

using namespace cocos2d;

// 初期化
bool GamePlayLayer::init()
{
	if ( !Layer::init() )
	{
		return false;
	}
	
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