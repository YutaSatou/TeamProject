#include "LiquidFunHelper.h"

using namespace cocos2d;

// 静的メンバの初期化
const float LiquidFunHelper::PTM_RATIO = 32.0f;

// ピクセルからメータへの単位変換
LiquidFunVec2 LiquidFunHelper::toMeter( const Vec2& pixsel )
{
	return LiquidFunVec2( pixsel.x / PTM_RATIO, pixsel.y / PTM_RATIO );
}

// ピクセルからメータへの単位変換
float LiquidFunHelper::toMeter( const float& pixsel )
{
	return ( pixsel / PTM_RATIO );
}

// メータからピクセルへの単位変換
Vec2 LiquidFunHelper::toPixsel( const LiquidFunVec2& meter )
{
	return Vec2( meter.x * PTM_RATIO, meter.y * PTM_RATIO );
}

// メータからピクセルへの単位変換
float LiquidFunHelper::toPixsel( const float& meter )
{
	return ( meter * PTM_RATIO );
}