#include "Cannon.h"
#include "../../LiquidFun/LiquidFunUserAPI.h"
#include "../Data/ObjectData.h"
#include "../Common/LiquidFunBodyDeleter.h"
#include "../Contact/ContactSettlor.h"
#include "EnemyDeadAction.h"
#include "Utility/Assistant/Animation/SpriteAnimator.h"

using namespace cocos2d;

// コンストラクタ
Cannon::Cannon()
	: mBody( nullptr )
	, mObjectData( nullptr )
	, mShootListener( []( const Vec2& ) { } )
	, mShootPower( Vec2::ZERO )
{
	
}

// 初期化
bool Cannon::init( ObjectDataPtr objectData, const std::string& nodeName, const Vec2& shootPower )
{
	if ( !Sprite::initWithFile( objectData->textureName, { 0.0f, 0.0f, 76.0f, 76.0f } ) )
	{
		return false;
	}
	
	// メンバ変数を初期化する。
	mObjectData	= objectData;
	mShootPower	= shootPower;
	
	// 各パラメータを設定する。
	setName( nodeName );
	setColor( mObjectData->textureColor );
	setOpacity( mObjectData->alpha );
	setScale( 1.2f );
	setAnchorPoint( Vec2::ANCHOR_MIDDLE );
	setPosition( mObjectData->position );
	
	// 物理構造の初期化、接触コールバックの設定を行う。
	initPhysics();
	setupContactCallback();
	
	return true;
}

// インスタンスの生成
Cannon* Cannon::create( ObjectDataPtr objectData, const std::string& nodeName, const Vec2& shootPower )
{
	Cannon* inst { new Cannon() };
	
	if ( inst && inst->init( objectData, nodeName, shootPower ) )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

// 発射を観測するリスナの登録
void Cannon::registerShootListener( ShootListener listener )
{
	mShootListener = listener;
}

// 物理構造の初期化
void Cannon::initPhysics()
{
	// ボディの大きさを定義する。
	const Size	drawSize	{ getContentSize() * getScale() };
	const float	radius		{ ( drawSize.width / 2.0f ) - 8.0f };
	
	// ボディの生成に必要な設定記述子を生成する。
	LiquidFunBodyDescCreator	bodyDescCreator;
	LiquidFunBodyDesc			bodyDesc	{ bodyDescCreator.createBodyDesc( this, LiquidFunBodyType::b2_dynamicBody ) };
	LiquidFunFixtureDesc		fixtureDesc	{ bodyDescCreator.createCircle( radius, mObjectData->material ) };
	
	// ボディを装着する。
	mBody = LiquidFunBodySettlor::attachBody( bodyDesc, fixtureDesc );
	
	// ノードが削除されるタイミングで、ボディも削除されるように設定する。
	addChild( LiquidFunBodyDeleter::create( mBody ) );
}

// 接触コールバックの設定
void Cannon::setupContactCallback()
{
	// 接触コールバックを設定する。
	ContactCallback::Ptr callback { std::make_shared< ContactCallback >() };
	callback->onContactLiquidBegin = CC_CALLBACK_3( Cannon::onContactLiquidBegin, this );
	
	// カテゴリの設定、衝突するカテゴリの設定、接触するカテゴリの設定、コールバックの有効化を行う。
	ContactSettlor contactSettlor { mBody };
	contactSettlor.setupCategory( Contact::Category::CANNON );
	contactSettlor.setupCollisionCategory();
	contactSettlor.setupContactCategory( callback, { Contact::Category::LIQUID } );
	contactSettlor.enableContactCallback( getName(), callback );
}

// 液体と接触した時に呼ばれるコールバック関数
void Cannon::onContactLiquidBegin( Node* contactNode, LiquidFunParticle* particle, int index )
{
	// ボディの衝突判定と接触コールバックを無効にする。
	mBody->SetActive( false );
	ContactSettlor contactSettlor { mBody };
	contactSettlor.disableContactCallback( getName() );
	
	playAnimation();
}

// アニメーションの再生
void Cannon::playAnimation()
{
	static const int	ANIMATION_FRAME_COUNT			{ 30 };
	static const float	ANIMATION_FRAME_SWITCH_SPEED	{ 2.0f };
	static const float	ANIMATION_END_SEC				{ ANIMATION_FRAME_COUNT * ANIMATION_FRAME_SWITCH_SPEED / 60.0f };
	
	// アニメーションを登録する。
	SpriteAnimationData animationData;
	animationData.addAnimation( mObjectData->textureName, "Cannon", getContentSize(), ANIMATION_FRAME_COUNT );
	
	// アニメーションを再生する。
	SpriteAnimator animator { this, animationData };
	animator.play( "Cannon", ANIMATION_FRAME_SWITCH_SPEED, false );
	
	ActionInterval*	delayAction			{ DelayTime::create( ANIMATION_END_SEC ) };
	ActionInterval*	enemyDeadAction		{ EnemyDeadAction::create( 0.5f, 7 ) };
	CallFunc*		onShoot				{ CallFunc::create( [ this ]() { mShootListener( mShootPower ); } ) };
	ActionInterval*	shootAction			{ Sequence::create( delayAction, onShoot, enemyDeadAction, nullptr ) };
	
	runAction( shootAction );
}