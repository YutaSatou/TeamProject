#include "Slime.h"
#include "../Data/ObjectData.h"
#include "../Collision/ContactSettlor.h"

using namespace cocos2d;

namespace
{
	ContactSettlor::OtherCategory otherCategory =
	{
		ContactCategory::WALL_UP, ContactCategory::WALL_DOWN, ContactCategory::WALL_LEFT, ContactCategory::WALL_RIGHT
	};
}

// コンストラクタ
Slime::Slime()
	: mObjectData( nullptr )
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
void Slime::onContactBegin( Node* contactNode )
{
	// 物理構造を無効にするアクション。
	CallFunc* disableAction = CallFunc::create( [ this ]() { getPhysicsBody()->setEnable( false ); } );
	
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
	
	// 動的なボディを生成する。
	PhysicsBody* body = PhysicsBody::createCircle( bodySize, mObjectData->material );
	body->setDynamic( true );
	body->setGravityEnable( false );
	
	// 接触コールバックを設定する。
	SharedPtr< ContactCallback > callback = makeShared< ContactCallback >();
	callback->onContactBegin = CC_CALLBACK_1( Slime::onContactBegin, this );
	
	// カテゴリの設定、衝突の有効化、接触の有効化、コールバックの登録を行う。
	ContactSettlor contactSettlor( body );
	contactSettlor.setupCategory( ContactCategory::SLIME );
	contactSettlor.enableCustomCollision( otherCategory );
	contactSettlor.enableCustomContact( { ContactCategory::PLAYER } );
	contactSettlor.enableContactCallback( getName(), callback );
	
	// 自身にボディを設定する。
	setPhysicsBody( body );
}