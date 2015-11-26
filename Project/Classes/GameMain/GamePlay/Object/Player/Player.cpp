#include "Player.h"
#include "../Data/ObjectData.h"
#include "../Color/ColorMixer.h"
// #include "../Collision/ContactSettlor.h"

using namespace cocos2d;

// コンストラクタ
Player::Player()
	: mObjectData( nullptr )
	, mColorMixer( makeShared< ColorMixer >() )
{
	
}

// 初期化
bool Player::init( SharedPtr< ObjectData > objectData )
{
	if ( !Sprite::initWithFile( objectData->textureName ) )
	{
		return false;
	}
	
	// オブジェクトデータを登録する。
	mObjectData = objectData;
	setUserData( &mObjectData->blendColor );
	
	// 各パラメータを設定する。
	setName( "Player" );
	setColor( mObjectData->textureColor );
	setAnchorPoint( Vec2::ANCHOR_MIDDLE );
	setPosition( objectData->position );
	
	// 物理構造の初期化を行う。
	initPhysics();
	
	return true;
}

// インスタンスの生成
Player* Player::create( SharedPtr< ObjectData > objectData )
{
	Player* inst = new Player();
	
	if ( inst && inst->init( objectData ) )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

// 接触時に呼ばれるコールバック関数
void Player::onContactBegin( Node* contactNode )
{
	// 自分と敵の色を合成する。
	ColorCMY blendColor = mColorMixer->blend( this, contactNode, 1.3f );
	
	// 色を更新する。
	updateColor( blendColor );
}

// 重力の有効化
void Player::enableGravity()
{
	// getPhysicsBody()->setGravityEnable( true );
}

// 物理構造の初期化
void Player::initPhysics()
{
	/*
	// ボディの大きさを定義する。
	const float bodySize = getContentSize().width / 2.0f;
	
	// 動的なボディを生成する。
	PhysicsBody* body = PhysicsBody::createCircle( bodySize, mObjectData->material );
	body->setDynamic( true );
	body->setGravityEnable( false );
	
	// 接触コールバックを設定する。
	SharedPtr< ContactCallback > callback = makeShared< ContactCallback >();
	callback->onContactBegin = CC_CALLBACK_1( Player::onContactBegin, this );
	
	// カテゴリの設定、衝突の有効化、接触の有効化、コールバックの登録を行う。
	ContactSettlor contactSettlor( body );
	contactSettlor.setupCategory( ContactCategory::PLAYER );
	contactSettlor.enableCollision();
	contactSettlor.enableContact();
	contactSettlor.enableContactCallback( getName(), callback );
	
	// 自身にボディを設定する。
	setPhysicsBody( body );
	*/
}

// 色の更新
void Player::updateColor( const ColorCMY& blendColor )
{
	// 色情報を更新する。
	mObjectData->blendColor		= blendColor;
	mObjectData->textureColor	= ColorCMY::convertToRGB( blendColor );
	
	// テクスチャの色を変更する。
	setColor( mObjectData->textureColor );
}