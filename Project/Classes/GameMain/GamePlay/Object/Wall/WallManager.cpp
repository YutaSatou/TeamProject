#include "WallManager.h"
#include "../../Control/GameControlMediator.h"
#include "Wall.h"
#include "Goal.h"

using namespace cocos2d;

// 初期化
bool WallManager::init( GameControlMediator& mediator )
{
	if ( !Node::init() )
	{
		return false;
	}
	
	// 画面サイズを取得する。
	const Vec2&	screenMin	{ 0.0f, -150.0f };
	const Vec2&	screenMax	{ Director::getInstance()->getWinSize() };
	
	// 上, 下, 左, 右の壁を生成する。
	Wall* up	{ Wall::create( { screenMin.x, screenMax.y }, { screenMax.x, screenMax.y } ) };
	Wall* down	{ Wall::create( { screenMin.x, screenMin.y }, { screenMax.x, screenMin.y } ) };
	Wall* left	{ Wall::create( { screenMin.x, screenMax.y }, { screenMin.x, screenMin.y } ) };
	Wall* right	{ Wall::create( { screenMax.x, screenMax.y }, { screenMax.x, screenMin.y } ) };
	
	// ゲーム終了イベントを有効化する。
	down->enableGameEndEvent( mediator );
	
	// 自身の子ノードとして追加する。
	addChild( up );
	addChild( down );
	addChild( left );
	addChild( right );
	addChild( Goal::create( { 360.0f, 100.0f } ) );
	
	return true;
}

// インスタンスの生成
WallManager* WallManager::create( GameControlMediator& mediator )
{
	WallManager* inst { new WallManager() };
	
	if ( inst && inst->init( mediator ) )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}