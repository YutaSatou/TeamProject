#include "Wall.h"
#include "../../LiquidFun/LiquidFunUserAPI.h"
#include "../../Control/GameControlMediator.h"
#include "../Common/LiquidFunBodyDeleter.h"
#include "../Contact/ContactSettlor.h"

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
	setName( "Wall" );
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
	// 接触コールバックを設定する。
	SharedPtr< ContactCallback > callback = makeShared< ContactCallback >();
	callback->onContactBegin = [ &mediator ]( Node*, LiquidFunBody* ) { mediator.gameEnd(); };
	
	// カテゴリの設定、接触するカテゴリの設定、コールバックの登録を行う。
	ContactSettlor contactSettlor( mBody );
	contactSettlor.setupCategory( Contact::Category::WALL_EVENT );
	contactSettlor.setupContactCategory( callback, { Contact::Category::PLAYER } );
	contactSettlor.enableContactCallback( getName(), callback );
}

// 物理構造の初期化
void Wall::initPhysics( const Vec2& start, const Vec2& end )
{
	// マテリアル( 密度, 反発係数, 摩擦係数 )を用意する。
	LiquidFunMaterial material( 0.0f, 1.0f, 1.0f );
	
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