#include "WallManager.h"
#include "../Collision/ContactCategory.h"
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
	
	// 上下左右の壁を装着する。
	attachWall( ContactCategory::WALL_UP,		{ screenMin.x, screenMax.y }, { screenMax.x, screenMax.y } );
	attachWall( ContactCategory::WALL_DOWN,		{ screenMin.x, screenMin.y }, { screenMax.x, screenMin.y } );
	attachWall( ContactCategory::WALL_LEFT,		{ screenMin.x, screenMax.y }, { screenMin.x, screenMin.y } );
	attachWall( ContactCategory::WALL_RIGHT,	{ screenMax.x, screenMax.y }, { screenMax.x, screenMin.y } );
	
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

// 壁の装着
void WallManager::attachWall( const ContactCategory& category, const Vec2& start, const Vec2& end )
{
	Wall* wall = Wall::create( category, start, end );
	
	addChild( wall );
}