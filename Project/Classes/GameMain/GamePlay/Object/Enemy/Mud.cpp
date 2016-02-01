#include "Mud.h"
#include "../../LiquidFun/LiquidFunUserAPI.h"
#include "../Data/ObjectData.h"
#include "../Common/LiquidFunBodyDeleter.h"
#include "../Contact/ContactSettlor.h"
#include "Utility/Assistant/Animation/SpriteAnimator.h"

using namespace cocos2d;

// コンストラクタ
Mud::Mud()
	: mBody( nullptr )
	, mObjectData( nullptr )
{
	
}

// 初期化
bool Mud::init( ObjectDataPtr objectData, const std::string& nodeName )
{
	if ( !Sprite::initWithFile( objectData->textureName, { 0.0f, 0.0f, 80.0f, 80.0f } ) )
	{
		return false;
	}
	
	// オブジェクトデータを登録する。
	mObjectData = objectData;
	setUserData( &mObjectData->blendColor );
	
	// 各パラメータを設定する。
	setName( nodeName );
	setColor( mObjectData->textureColor );
	setOpacity( mObjectData->alpha );
	setScale( 1.2f );
	setAnchorPoint( Vec2::ANCHOR_MIDDLE );
	setPosition( mObjectData->position );
	
	// アニメーションの初期化を行う。
	initAnimation();
	
	// 物理構造の初期化を行う。
	initPhysics();
	
	return true;
}

// インスタンスの生成
Mud* Mud::create( ObjectDataPtr objectData, const std::string& nodeName )
{
	Mud* inst { new Mud() };
	
	if ( inst && inst->init( objectData, nodeName ) )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

// アニメーションの初期化
void Mud::initAnimation()
{
	// アニメーションを登録する。
	SpriteAnimationData animationData;
	animationData.addAnimation( mObjectData->textureName, "Mud", getContentSize(), 30 );
	
	// アニメーションを再生する。
	SpriteAnimator animator { this, animationData };
	animator.play( "Mud", 2.0f );
}

// 物理構造の初期化
void Mud::initPhysics()
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
	
	// 接触コールバックを設定する。
	ContactCallback::Ptr callback { std::make_shared< ContactCallback >() };
	callback->onContactLiquidBegin = CC_CALLBACK_3( Mud::onContactLiquidBegin, this );
	
	// カテゴリの設定、衝突するカテゴリの設定、接触するカテゴリの設定、コールバックの有効化を行う。
	ContactSettlor contactSettlor { mBody };
	contactSettlor.setupCategory( Contact::Category::MUD );
	contactSettlor.setupCollisionCategory();
	contactSettlor.setupContactCategory( callback, { Contact::Category::LIQUID } );
	contactSettlor.enableContactCallback( getName(), callback );
}

// 液体と接触した時に呼ばれるコールバック関数
void Mud::onContactLiquidBegin( Node* contactNode, LiquidFunParticle* particle, int index )
{
	// ボディの衝突判定と接触コールバックを無効にする。
	mBody->SetActive( false );
	ContactSettlor contactSettlor { mBody };
	contactSettlor.disableContactCallback( getName() );
	
	// オブジェクト削除のアクションを実行する。
	ActionInterval*	deadAction		{ Spawn::create( ScaleTo::create( 0.5f, 0.0f ), Blink::create( 0.5f, 7 ), nullptr ) };
	ActionInterval*	removeAction	{ Sequence::create( deadAction, RemoveSelf::create(), nullptr ) };
	runAction( removeAction );
}