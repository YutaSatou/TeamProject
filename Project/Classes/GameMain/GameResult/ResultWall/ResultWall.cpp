//
//  ResultSlimeContainer.cpp
//  TeamProject
//
//  Created by Satou yuta on 2016/01/16.
//
//

#include "ResultWall.h"

#include "../../GamePlay/LiquidFun/LiquidFunUserAPI.h"
#include "../../GamePlay/Control/GameControlMediator.h"
#include "../../GamePlay/Object/Common/LiquidFunBodyDeleter.h"
#include "../../GamePlay/Object/Contact/ContactSettlor.h"

using namespace cocos2d;

// コンストラクタ
ResultWall::ResultWall()
: mBody( nullptr )
{
	
}

// 初期化
bool ResultWall::init( const Vec2& start, const Vec2& end )
{
	if ( !Node::init() )
	{
		return false;
	}
	
	// 各パラメータを設定する。
	setAnchorPoint( Vec2::ANCHOR_MIDDLE );
	setPosition( Vec2::ZERO );
	
	// 物理構造の初期化を行う。
	initPhysics( start, end );
	
	return true;
}

// インスタンスの生成
ResultWall* ResultWall::create( const Vec2& start, const Vec2& end )
{
	ResultWall* inst { new ResultWall() };
	
	if ( inst && inst->init( start, end ) )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

// 物理構造の初期化
void ResultWall::initPhysics( const Vec2& start, const Vec2& end )
{
	// マテリアル( 密度, 反発係数, 摩擦係数 )を用意する。
	LiquidFunMaterial material { 0.0f, 0.2f, 1.0f };
	
	// ボディの生成に必要な設定記述子を生成する。
	LiquidFunBodyDescCreator	bodyDescCreator;
	LiquidFunBodyDesc			bodyDesc	{ bodyDescCreator.createBodyDesc( this, LiquidFunBodyType::b2_staticBody ) };
	LiquidFunFixtureDesc		fixtureDesc	{ bodyDescCreator.createEdgeSegment( start, end, material ) };
	
	// ボディを装着する。
	mBody = LiquidFunBodySettlor::attachBody( bodyDesc, fixtureDesc );
	
	// ノードが削除されるタイミングで、ボディも削除されるように設定する。
	addChild( LiquidFunBodyDeleter::create( mBody ) );
}