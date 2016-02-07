#include "Player.h"
#include "../Data/ObjectData.h"
#include "Action/PlayerActionController.h"

using namespace cocos2d;

namespace
{
	const uint16_t PARTICLE_TYPE
	{
		LiquidFunParticleType::b2_springParticle | LiquidFunParticleType::b2_barrierParticle
	};
}

// コンストラクタ
Player::Player()
	: mObjectData( nullptr )
	, mActionController( std::make_shared< PlayerActionController >() )
{
	
}

// 初期化
bool Player::init( ObjectDataPtr objectData )
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
	setContentSize( { 64.0f, 64.0f } );
	setAnchorPoint( Vec2::ANCHOR_MIDDLE );
	setPosition( Vec2::ZERO );
	
	// パーティクルの初期化、接触コールバックの設定を行う。
	initParticle();
	disableLiquidBehavior();
	setupContactCallback();
	
	// アクション制御者の初期化を行う。
	mActionController->init( this, mObjectData );
	
	return true;
}

// 更新
void Player::update( float deltaTime )
{
	LiquidObject::update( deltaTime );
	
	updateParticle();
	
	mActionController->update( deltaTime );
}

// インスタンスの生成
Player* Player::create( ObjectDataPtr objectData )
{
	Player* inst { new Player() };
	
	if ( inst && inst->init( objectData ) )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

// 色情報の同期
void Player::syncColor()
{
	eachBuffer( [ this ]( UserDataPointer* userData, LiquidFunParticleColor* color, LiquidFunVec2* position )
	{
		const Color3B&	c	{ mObjectData->textureColor };
		const uint8_t	a	{ mObjectData->alpha };
		
		( *color ) = { c.r, c.g, c.b, a };
	} );
}

// 座標情報の同期
void Player::syncPosition()
{
	unregisterTexture();
	initParticle();
}

// パーティクルの初期化
void Player::initParticle()
{
	// パーティクルの生成に必要な設定記述子を生成する。
	LiquidFunParticleDescCreator	creator;
	LiquidFunParticleDesc			particleDesc	{ creator.createParticleDesc( 4.0f ) };
	LiquidFunParticleGroupDesc		groupDesc		{ creator.createParticleGroupDesc( mObjectData->textureColor, mObjectData->position, PARTICLE_TYPE, getContentSize().width, mObjectData->alpha ) };
	
	// 弾力の強さを設定する。
	particleDesc.springStrength		= 0.2f;
	particleDesc.dampingStrength	= 0.7f;
	groupDesc.strength				= 0.3f;
	
	// パーティクルを装着する。
	mParticle		= LiquidFunParticleSettlor::attachParticle( particleDesc );
	mParticleGroup	= LiquidFunParticleSettlor::attachParticleGroup( mParticle, groupDesc );
	
	// テクスチャを登録する。
	registerTexture( mObjectData->textureName );
}

// 剛体と接触した時に呼ばれるコールバック関数
void Player::onContactRigidBegin( Node* contactNode, LiquidFunFixture* fixture )
{
	mActionController->execute( contactNode, fixture );
}