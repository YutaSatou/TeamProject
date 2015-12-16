#include "Wall.h"
#include "../../LiquidFun/LiquidFunUserAPI.h"
#include "../../Control/GameControlMediator.h"
#include "../Contact/ContactSettlor.h"
#include "../Common/LiquidFunBodyDeleter.h"

using namespace cocos2d;

// コンストラクタ
Wall::Wall()
	: mBody( nullptr )
{
	
}

// 初期化
bool Wall::init( const Vec2& start, const Vec2& end )
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
Wall* Wall::create( const Vec2& start, const Vec2& end )
{
	Wall* inst = new Wall();
	
	if ( inst && inst->init( start, end ) )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

// ゲーム終了イベントの有効化
void Wall::enableGameEndEvent( GameControlMediator& mediator )
{
	// 名前を設定する。
	setName( "WallEvent" );
	
	// 接触コールバックを設定する。
	SharedPtr< ContactCallback > callback = makeShared< ContactCallback >();
	callback->onContactLiquidBegin = [ &mediator ]( Node* contactNode, LiquidFunBody* body, LiquidFunParticle* particle, int index )
	{
		// パーティクルを停止状態にして、ゲームを終了する。
		particle->SetPaused( true );
		mediator.gameEnd();
	};
	
	// カテゴリの設定、接触するカテゴリの設定、コールバックの有効化を行う。
	ContactSettlor contactSettlor( mBody );
	contactSettlor.setupCategory( Contact::Category::WALL_EVENT );
	contactSettlor.setupContactCategory( callback, { Contact::Category::PLAYER, Contact::Category::LIQUID } );
	contactSettlor.enableContactCallback( getName(), callback );
}

// 物理構造の初期化
void Wall::initPhysics( const Vec2& start, const Vec2& end )
{
	// マテリアル( 密度, 反発係数, 摩擦係数 )を用意する。
	LiquidFunMaterial material( 0.0f, 0.2f, 1.0f );
	
	// ボディの生成に必要な設定記述子を生成する。
	LiquidFunBodyDescCreator	bodyDescCreator;
	LiquidFunBodyDesc			bodyDesc	= bodyDescCreator.createBodyDesc( this, LiquidFunBodyType::b2_staticBody );
	LiquidFunFixtureDesc		fixtureDesc	= bodyDescCreator.createEdgeSegment( start, end, material );
	
	// ボディを装着する。
	mBody = LiquidFunBodySettlor::attachBody( bodyDesc, fixtureDesc );
	addChild( LiquidFunBodyDeleter::create( mBody ) );
	
	// カテゴリの設定、衝突するカテゴリの設定を行う。
	ContactSettlor contactSettlor( mBody );
	contactSettlor.setupCategory( Contact::Category::WALL );
	contactSettlor.setupCollisionCategory();
}