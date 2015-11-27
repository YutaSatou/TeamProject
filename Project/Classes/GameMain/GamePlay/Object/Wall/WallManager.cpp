#include "WallManager.h"
#include "Wall.h"

using namespace cocos2d;

// 初期化
bool WallManager::init()
{
	if ( !Node::init() )
	{
		return false;
	}
	
	// 画面サイズを取得する。
	const Vec2	screenMin	= Vec2::ZERO;
	const Vec2	screenMax	= Director::getInstance()->getWinSize();
	
	// 上, 下, 左, 右の壁を生成する。
	Wall* up	= Wall::create( { screenMin.x, screenMax.y }, { screenMax.x, screenMax.y } );
	Wall* down	= Wall::create( { screenMin.x, screenMin.y }, { screenMax.x, screenMin.y } );
	Wall* left	= Wall::create( { screenMin.x, screenMax.y }, { screenMin.x, screenMin.y } );
	Wall* right	= Wall::create( { screenMax.x, screenMax.y }, { screenMax.x, screenMin.y } );
	
	// 自身の子ノードとして追加する。
	addChild( up );
	addChild( down );
	addChild( left );
	addChild( right );
	
	return true;
}

// インスタンスの生成
WallManager* WallManager::create()
{
	WallManager* inst = new WallManager();
	
	if ( inst && inst->init() )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}