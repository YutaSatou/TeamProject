#include "LiquidFunHelper.h"

using namespace cocos2d;

// 静的メンバの初期化
const float LiquidFunHelper::PTM_RATIO { 32.0f };

// ピクセルからメータへの単位変換
LiquidFunVec2 LiquidFunHelper::toMeter( const Vec2& pixsel )
{
	return { toMeter( pixsel.x ), toMeter( pixsel.y ) };
}

// ピクセルからメータへの単位変換
float LiquidFunHelper::toMeter( float pixsel )
{
	return { pixsel / PTM_RATIO };
}

// メータからピクセルへの単位変換
Vec2 LiquidFunHelper::toPixsel( const LiquidFunVec2& meter )
{
	return { toPixsel( meter.x ), toPixsel( meter.y ) };
}

// メータからピクセルへの単位変換
float LiquidFunHelper::toPixsel( float meter )
{
	return { meter * PTM_RATIO };
}

// ノードの取得
Node* LiquidFunHelper::getNode( LiquidFunBody* body )
{
	return static_cast< Node* >( body->GetUserData() );
}

// ノードの取得
Node* LiquidFunHelper::getNode( UserData* userData )
{
	return static_cast< Node* >( ( *userData ) );
}