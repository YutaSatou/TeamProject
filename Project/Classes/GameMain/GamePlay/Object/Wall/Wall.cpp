#include "Wall.h"
#include "../Collision/ContactSettlor.h"

using namespace cocos2d;

// コンストラクタ
Wall::Wall()
	: mCategory( ContactCategory::WALL_UP )
{
	
}

// 初期化
bool Wall::init( const ContactCategory& category, const Vec2& start, const Vec2& end )
{
	if ( !Node::init() )
	{
		return false;
	}
	
	// カテゴリを登録する。
	mCategory = category;
	
	// 各パラメータを設定する。
	setName( "Wall" );
	setAnchorPoint( Vec2::ANCHOR_MIDDLE );
	setPosition( Vec2::ZERO );
	
	// 物理構造の初期化を行う。
	initPhysics( start, end );
	
	return true;
}

// インスタンスの生成
Wall* Wall::create( const ContactCategory& category, const Vec2& start, const Vec2& end )
{
	Wall* inst = new Wall();
	
	if ( inst && inst->init( category, start, end ) )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

// 物理構造の初期化
void Wall::initPhysics( const Vec2& start, const Vec2& end )
{
	// 物理特性( 密度, 反発係数, 摩擦係数 )を用意する。
	PhysicsMaterial material;
	material.density		= 0.2f;
	material.restitution	= 0.2f;
	material.friction		= 1.0f;
	
	// ボディを生成する。
	PhysicsBody* body = PhysicsBody::createEdgeSegment( start, end, material );
	
	// ボディの設定をする。
	setupPhysicsBody( body );
	
	// 自身にボディを設定する。
	setPhysicsBody( body );
}

// ボディの設定
void Wall::setupPhysicsBody( PhysicsBody* body )
{
	// カテゴリの設定、衝突の有効化、接触の有効化を行う。
	ContactSettlor contactSettlor( body );
	contactSettlor.setupCategory( mCategory );
	contactSettlor.enableCollision();
	contactSettlor.enableContact( { ContactCategory::PLAYER } );
}