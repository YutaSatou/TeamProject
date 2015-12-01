#include "PlayerBody.h"
#include "../../LiquidFun/LiquidFunUserAPI.h"
#include "../../LiquidFun/LiquidFunCoreAPI.h"

using namespace cocos2d;

namespace
{
	unsigned short particleType =	LiquidFunParticleType::b2_springParticle	|
									LiquidFunParticleType::b2_barrierParticle	|
									LiquidFunParticleType::b2_fixtureContactListenerParticle;	//=> パーティクルのビットマスク
}

// コンストラクタ
PlayerBody::PlayerBody()
	: mParentNode( nullptr )
	, mParticle( nullptr )
	, mParticleGroup( nullptr )
	, mParticleGroupSize( Size::ZERO )
{
	
}

// デストラクタ
PlayerBody::~PlayerBody()
{
	LiquidFunParticleSettlor::detachParticleGroup( mParticle, mParticleGroup );
}

// 初期化
void PlayerBody::init( Node* parentNode, const std::string& textureName, const Vec2& position )
{
	// メンバ変数を初期化する。
	mParentNode			= parentNode;
	mParticleGroupSize	= parentNode->getContentSize();
	
	// ボディとテクスチャを初期化する。
	initBody( position );
	initTexture( textureName );
}

// ボディの初期化
void PlayerBody::initBody( const Vec2& position )
{
	// 親ノードから色情報を取得する。
	Color4B color	= Color4B( mParentNode->getColor() );
	color.a			= mParentNode->getOpacity();
	
	// パーティクル設定記述子を生成する。
	LiquidFunParticleDesc particleDesc;
	particleDesc.radius				= LiquidFunHelper::toMeter( 2.0f );
	particleDesc.springStrength		= 0.2f;
	particleDesc.strictContactCheck	= true;
	
	// シェイプを生成する。
	LiquidFunCircleShape shape;
	shape.m_radius	= LiquidFunHelper::toMeter( mParticleGroupSize.width / 2.0f );
	
	// パーティクルグループ設定記述子を生成する。
	LiquidFunParticleGroupDesc groupDesc;
	groupDesc.shape		= &shape;
	groupDesc.flags		= particleType;
	groupDesc.color		= LiquidFunParticleColor( color.r, color.g, color.b, color.a );
	groupDesc.position	= LiquidFunHelper::toMeter( position );
	groupDesc.strength	= 0.4f;
	
	// パーティクルを装着する。
	mParticle		= LiquidFunParticleSettlor::attachParticle( particleDesc );
	mParticleGroup	= LiquidFunParticleSettlor::attachParticleGroup( mParticle, groupDesc );
	
	// パーティクルを停止状態にする。
	mParticle->SetPaused( true );
}

// 更新
void PlayerBody::update()
{
	eachBuffer( [ this ]( UserDataPointer* userData, LiquidFunParticleColor* color, LiquidFunVec2* position )
	{
		// ノードを取得する。
		Node* node = LiquidFunHelper::getNode( userData );
		
		if ( !node )
		{
		   // 取得に失敗した場合は終了する。
		   return;
		}
		
		// 各バッファの情報をノードに適応する。
		node->setPosition( LiquidFunHelper::toPixsel( ( *position ) ) + ( mParticleGroupSize / 2.0f ) );
		node->setColor( Color3B( ( *color ).r, ( *color ).g, ( *color ).b ) );
		node->setOpacity( ( *color ).a );
	} );
}

// 重力の有効化
void PlayerBody::enableGravity()
{
	mParticle->SetPaused( false );
}

// テクスチャの初期化
void PlayerBody::initTexture( const std::string& textureName )
{
	eachBuffer( [ this, &textureName ]( UserDataPointer* userData, LiquidFunParticleColor* color, LiquidFunVec2* position )
	{
		// パーティクル用のテクスチャを生成する。
		Sprite* particle = Sprite::create( textureName );
		particle->setAnchorPoint( Vec2::ANCHOR_MIDDLE );
		particle->setScale( 0.5f );
		
		// ユーザデータにテクスチャを登録する。
		( *userData ) = particle;
		
		// 親ノードにテクスチャを追加する。
		mParentNode->addChild( particle );
	} );
}

// バッファの巡回
void PlayerBody::eachBuffer( const EachBufferFunc& func )
{
	const auto particleCount	= mParticle->GetParticleCount();
	const auto bufferIndex		= mParticleGroup->GetBufferIndex();
	
	// 各バッファのアドレスを取得する。
	auto userData	= mParticle->GetUserDataBuffer()	+ bufferIndex;
	auto color		= mParticle->GetColorBuffer()		+ bufferIndex;
	auto position	= mParticle->GetPositionBuffer()	+ bufferIndex;
	
	for ( int i = 0; i < particleCount; ++i )
	{
		// 関数を実行する。
		func( userData, color, position );
		
		// 各バッファのアドレスを進める。
		++userData, ++color, ++position;
	}
}