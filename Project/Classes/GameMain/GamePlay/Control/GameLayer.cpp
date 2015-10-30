#include "GameLayer.h"

using namespace cocos2d;

// 初期化
bool GameLayer::init()
{
	if ( !Layer::init() )
	{
		return false;
	}
	
	return true;
}

// インスタンスの生成
GameLayer* GameLayer::create()
{
	GameLayer* inst = new GameLayer();
	
	if ( inst && inst->init() )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

// ゲーム開始
void GameLayer::gameStart()
{
	
}

// ゲーム中断
void GameLayer::gamePause()
{
	
}

// ゲーム終了
void GameLayer::gameEnd()
{
	
}