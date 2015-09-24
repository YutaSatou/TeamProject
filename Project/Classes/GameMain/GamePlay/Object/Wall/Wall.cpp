#include "Wall.h"
#include "../Collision/ContactSettlor.h"

using namespace cocos2d;

// 初期化
bool Wall::init()
{
	if ( !Node::init() )
	{
		return false;
	}
	
	// 各パラメータを設定する。
	setName( "Wall" );
	setAnchorPoint( Vec2::ANCHOR_MIDDLE );
	setPosition( Vec2::ZERO );
	
	// 物理構造の初期化を行う。
	initPhysics();
	
	return true;
}

// インスタンスの生成
Wall* Wall::create()
{
	Wall* inst = new Wall();
	
	if ( inst && inst->init() )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

// 物理構造の初期化
void Wall::initPhysics()
{
	// 画面サイズを取得する。
	const Vec2	screenMin	= Vec2::ZERO;
	const Vec2	screenMax	= Director::getInstance()->getWinSize();
	
	// 静的なボディを用意する。
	PhysicsBody* body = PhysicsBody::create();
	body->setDynamic( false );
	
	// ボディに対してシェイプを装着する。
	attachShape( body, { screenMin.x, screenMax.y }, { screenMax.x, screenMax.y } );
	attachShape( body, { screenMin.x, screenMin.y }, { screenMax.x, screenMin.y } );
	attachShape( body, { screenMin.x, screenMax.y }, { screenMin.x, screenMin.y } );
	attachShape( body, { screenMax.x, screenMax.y }, { screenMax.x, screenMin.y } );
	
	// ボディの設定をする。
	setupPhysicsBody( body );
	
	// 自身にボディを設定する。
	setPhysicsBody( body );
}

// ボディの設定
void Wall::setupPhysicsBody( PhysicsBody* body )
{
	// カテゴリの設定、衝突の有効化、接触の有効化を行う。
	ContactSettlor contactSettlor( body, true );
	contactSettlor.setupCategory( ContactCategory::WALL );
	contactSettlor.enableCollision();
	contactSettlor.enableContact();
}

// シェイプの装着
void Wall::attachShape( PhysicsBody* body, const Vec2& start, const Vec2& end )
{
	// 物理特性( 密度, 反発係数, 摩擦係数 )を用意する。
	PhysicsMaterial material;
	material.density		= 0.5f;
	material.restitution	= 0.5f;
	material.friction		= 0.3f;
	
	// 線のシェイプを生成する。
	PhysicsShape* edgeSegment = PhysicsShapeEdgeSegment::create( start, end, material );
	
	// ボディに追加する。
	body->addShape( edgeSegment );
}