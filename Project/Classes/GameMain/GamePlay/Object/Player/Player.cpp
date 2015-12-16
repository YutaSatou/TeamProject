#include "Player.h"
#include "../Data/ObjectData.h"

using namespace cocos2d;

namespace
{
	const unsigned short PARTICLE_TYPE =	LiquidFunParticleType::b2_springParticle |
											LiquidFunParticleType::b2_barrierParticle;	// パーティクルのビットマスク
}

// コンストラクタ
Player::Player()
	: mObjectData( nullptr )
{
	
}

// 初期化
bool Player::init( SharedPtr< ObjectData > objectData )
{
	if ( !Node::init() )
	{
		return false;
	}
	
	// オブジェクトデータを登録する。
	mObjectData = objectData;
	setUserData( &mObjectData->blendColor );
	
	// スケジュール登録を行う。
	scheduleUpdate();
	
	// 各パラメータを設定する。
	setName( "Player" );
	setColor( mObjectData->textureColor );
	setContentSize( Size( 64.0f, 64.0f ) );
	setAnchorPoint( Vec2::ANCHOR_MIDDLE );
	setPosition( Vec2::ZERO );
	
	// 液体関係の初期化を行う。
	initParticle();
	registerTexture( mObjectData->textureName );
	setupContactCallback();
	
	return true;
}

// 更新
void Player::update( float deltaTime )
{
	// 基底クラスの更新を行う。
	LiquidObject::update( deltaTime );
	
	// パーティクルの更新を行う。
	updateParticle();
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

// パーティクルの初期化
void Player::initParticle()
{
	// パーティクルの生成に必要な設定記述子を生成する。
	LiquidFunParticleDescCreator creator;
	auto particleDesc	= creator.createParticleDesc( 4.0f );
	auto groupDesc		= creator.createParticleGroupDesc( mObjectData->textureColor, mObjectData->position, PARTICLE_TYPE, getContentSize().width );
	
	// 弾力の強さを設定する。
	particleDesc.springStrength	= 0.2f;
	groupDesc.strength			= 0.4f;
	
	// パーティクルを装着する。
	mParticle		= LiquidFunParticleSettlor::attachParticle( particleDesc );
	mParticleGroup	= LiquidFunParticleSettlor::attachParticleGroup( mParticle, groupDesc );
	
	// パーティクルを停止状態にする。
	mParticle->SetPaused( true );
}

// 液体挙動の有効化
void Player::enableLiquidBehavior()
{
	mParticle->SetPaused( false );
}