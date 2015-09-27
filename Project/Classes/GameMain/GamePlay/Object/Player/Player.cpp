#include "Player.h"
#include "../Collision/ContactSettlor.h"

using namespace cocos2d;

// コンストラクタ
Player::Player()
	: mObjectData( nullptr )
{
	
}

// 初期化
bool Player::init( ObjectData::Ptr objectData )
{
	if ( !Sprite::initWithFile( objectData->textureName ) )
	{
		return false;
	}
	
	// オブジェクトデータを登録する。
	mObjectData = objectData;
	setUserObject( mObjectData->blendColor );
	
	// 各パラメータを設定する。
	setName( "Player" );
	setAnchorPoint( Vec2::ANCHOR_MIDDLE );
	setPosition( objectData->position );
	
	// 物理構造の初期化を行う。
	initPhysics();
	
	return true;
}

// インスタンスの生成
Player* Player::create( ObjectData::Ptr objectData )
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
	
}

// 物理構造の初期化
void Player::initPhysics()
{
	// ボディの大きさを定義する。
	const float bodySize = getContentSize().width / 2;
	
	// 動的なボディを生成する。
	PhysicsBody* body = PhysicsBody::createCircle( bodySize, mObjectData->material );
	body->setDynamic( true );
	
	// 接触コールバックを設定する。
	ContactCallback::Ptr callback = std::make_shared< ContactCallback >();
	callback->onContactBegin = CC_CALLBACK_1( Player::onContactBegin, this );
	
	// カテゴリの設定、衝突の有効化、接触の有効化、コールバックの登録を行う。
	ContactSettlor contactSettlor( body );
	contactSettlor.setupCategory( ContactCategory::PLAYER );
	contactSettlor.enableCollision();
	contactSettlor.enableContact();
	contactSettlor.enableContactCallback( getName(), callback );
	
	// 自身にボディを設定する。
	setPhysicsBody( body );
}