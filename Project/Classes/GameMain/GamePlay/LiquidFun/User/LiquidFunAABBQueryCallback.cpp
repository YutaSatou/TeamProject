#include "LiquidFunAABBQueryCallback.h"
#include "cocos2d.h"
#include "../Core/LiquidFunHelper.h"
#include "../Core/LiquidFunWorldManager.h"

using namespace cocos2d;

// コンストラクタ
LiquidFunAABBQueryCallback::LiquidFunAABBQueryCallback()
	: onReportFixture( []( LiquidFunFixture* ) { return true; } )
{
	
}

// 更新
void LiquidFunAABBQueryCallback::update( const Vec2& searchPosition, const Size& searchArea )
{
	const Vec2	lower	{ searchPosition.x - searchArea.width / 2.0f, searchPosition.y - searchArea.height / 2.0f };
	const Vec2	upper	{ searchPosition.x + searchArea.width / 2.0f, searchPosition.y + searchArea.height / 2.0f };
	
	LiquidFunAABB aabb;
	aabb.lowerBound	= LiquidFunHelper::toMeter( lower );
	aabb.upperBound	= LiquidFunHelper::toMeter( upper );
	
	// 自身を登録する。
	LiquidFunWorldManager::getInstance().registerAABBQuery( this, aabb );
}

// フィクスチャを検知した時に呼ばれるコールバック関数
bool LiquidFunAABBQueryCallback::ReportFixture( LiquidFunFixture* fixture )
{
	return onReportFixture( fixture );
}