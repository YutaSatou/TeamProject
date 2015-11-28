#include "Slime.h"
#include "../../LiquidFun/LiquidFunUserAPI.h"
#include "../Data/ObjectData.h"
#include "../Common/LiquidFunBodyDeleter.h"
#include "../Contact/ContactSettlor.h"

using namespace cocos2d;

// コンストラクタ
Slime::Slime()
	: mBody( nullptr )
	, mObjectData( nullptr )
{
	
}

// 初期化
bool Slime::init( SharedPtr< ObjectData > objectData, const std::string& nodeName )
{
	if ( !Sprite::initWithFile( objectData->textureName ) )
	{
		return false;
	}
	
	// オブジェクトデータを登録する。
	mObjectData = objectData;
	setUserData( &mObjectData->blendColor );
	
	// 各パラメータを設定する。
	setName( nodeName );
	setColor( mObjectData->textureColor );
	setAnchorPoint( Vec2::ANCHOR_MIDDLE );
	setPosition( objectData->position );
	
	// 物理構造の初期化を行う。
	initPhysics();
	
	return true;
}

// インスタンスの生成
Slime* Slime::create( SharedPtr< ObjectData > objectData, const std::string& nodeName )
{
	Slime* inst = new Slime();
	
	if ( inst && inst->init( objectData, nodeName ) )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

// 接触時に呼ばれるコールバック関数
void Slime::onContactBegin( Node* contactNode, LiquidFunBody* contactBody )
{
	// 物理構造を無効にするアクション。
	CallFunc* disableAction = CallFunc::create( [ this ]() { mBody->SetActive( false ); } );
	
	// オブジェクト死亡時のアクション。
	ActionInterval* deadAction = Sequence::create( disableAction, Blink::create( 0.5f, 7 ), RemoveSelf::create(), nullptr );
	
	// アクションを実行する。
	runAction( deadAction );
}

// 物理構造の初期化
void Slime::initPhysics()
{
	// ボディの大きさを定義する。
	const float bodySize = getContentSize().width / 2.0f;
	
	// ボディの生成に必要な設定記述子を生成する。
	LiquidFunBodyDescCreator	bodyDescCreator;
	LiquidFunBodyDesc			bodyDesc	= bodyDescCreator.createBodyDesc( this, LiquidFunBodyType::b2_dynamicBody );
	LiquidFunFixtureDesc		fixtureDesc	= bodyDescCreator.createCircle( bodySize, mObjectData->material );
	
	// ボディを装着する。
	mBody = LiquidFunBodySettlor::attachBody( bodyDesc, fixtureDesc );
	addChild( LiquidFunBodyDeleter::create( mBody ) );
	
	// 接触コールバックを設定する。
	SharedPtr< ContactCallback > callback = makeShared< ContactCallback >();
	callback->onContactBegin = CC_CALLBACK_2( Slime::onContactBegin, this );
	
	// カテゴリの設定、衝突するカテゴリの設定、接触するカテゴリの設定、コールバックの登録を行う。
	ContactSettlor contactSettlor( mBody );
	contactSettlor.setupCategory( Contact::Category::SLIME );
	contactSettlor.setupCollisionCategory();
	contactSettlor.setupContactCategory( callback, { Contact::Category::PLAYER } );
	contactSettlor.enableContactCallback( getName(), callback );
}