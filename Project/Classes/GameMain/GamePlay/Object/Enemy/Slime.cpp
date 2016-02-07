#include "Slime.h"
#include "../../LiquidFun/LiquidFunUserAPI.h"
#include "../Data/ObjectData.h"
#include "../Common/LiquidFunBodyDeleter.h"
#include "../Contact/ContactSettlor.h"
#include "Utility/Assistant/Animation/SpriteAnimator.h"

using namespace cocos2d;

// コンストラクタ
Slime::Slime()
	: mBody( nullptr )
	, mObjectData( nullptr )
{
	
}

// 初期化
bool Slime::init( ObjectDataPtr objectData, const std::string& nodeName )
{
	if ( !Sprite::initWithFile( objectData->textureName, { 0.0f, 0.0f, 70.0f, 70.0f } ) )
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
	
	// 物理構造の初期化、接触コールバックの設定を行う。
	initPhysics();
	setupContactCallback();
	
	return true;
}

// インスタンスの生成
Slime* Slime::create( ObjectDataPtr objectData, const std::string& nodeName )
{
	Slime* inst { new Slime() };
	
	if ( inst && inst->init( objectData, nodeName ) )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

// アニメーションの初期化
void Slime::initAnimation()
{
	// テクスチャの名前から拡張子を削除する。
	std::string textureName = mObjectData->textureName;
	textureName.erase( textureName.find_last_of( "." ) );
	
	// フェイスアニメーション用のスプライトを生成する。
	Sprite* face { Sprite::create() };
	face->setAnchorPoint( Vec2::ANCHOR_BOTTOM_LEFT );
	addChild( face );
	
	// アニメーションを登録する。
	SpriteAnimationData animationData;
	animationData.addAnimation( textureName + ".png",		"Slime_Body", getContentSize(), 60 );
	animationData.addAnimation( textureName + "_Face.png",	"Slime_Face", getContentSize(), 60 );
	
	// アニメーションを再生する。
	SpriteAnimator animator { this, animationData };
	animator.play( "Slime_Body", 2.0f );
	animator.changeTarget( face );
	animator.play( "Slime_Face", 2.0f );
}

// 物理構造の初期化
void Slime::initPhysics()
{
	// ボディの大きさを定義する。
	const Size	drawSize	{ getContentSize() * getScale() };
	const float	radius		{ ( drawSize.width / 2.0f ) - 5.0f };
	
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
void Slime::setupContactCallback()
{
	// 接触コールバックを設定する。
	ContactCallback::Ptr callback { std::make_shared< ContactCallback >() };
	callback->onContactLiquidBegin = CC_CALLBACK_3( Slime::onContactLiquidBegin, this );
	
	// カテゴリの設定、衝突するカテゴリの設定、接触するカテゴリの設定、コールバックの有効化を行う。
	ContactSettlor contactSettlor { mBody };
	contactSettlor.setupCategory( Contact::Category::SLIME );
	contactSettlor.setupCollisionCategory();
	contactSettlor.setupContactCategory( callback, { Contact::Category::LIQUID } );
	contactSettlor.enableContactCallback( getName(), callback );
}

// 液体と接触した時に呼ばれるコールバック関数
void Slime::onContactLiquidBegin( Node* contactNode, LiquidFunParticle* particle, int index )
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