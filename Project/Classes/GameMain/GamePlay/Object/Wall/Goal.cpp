#include "Goal.h"

using namespace cocos2d;

// 初期化
bool Goal::init( const Vec2& position )
{
	if ( !Sprite::initWithFile( "Texture/GamePlay/Goal.png" ) )
	{
		return false;
	}
	
	// 各パラメータを設定する。
	setAnchorPoint( Vec2::ANCHOR_MIDDLE );
	setPosition( position );
	
	// 物理構造の初期化を行う。
	initPhysics();
	
	return true;
}

// インスタンスの生成
Goal* Goal::create( const Vec2& position )
{
	Goal* inst { new Goal() };
	
	if ( inst && inst->init( position ) )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

// 物理構造の初期化
void Goal::initPhysics()
{
	
}