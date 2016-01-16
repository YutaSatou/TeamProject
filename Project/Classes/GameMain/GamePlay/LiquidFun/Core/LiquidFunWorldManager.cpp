#include "LiquidFunWorldManager.h"
#include "LiquidFunScheduler.h"
#include "LiquidFunHelper.h"

using namespace cocos2d;

namespace
{
	const Vect DEFAULT_GRAVITY { 0.0f, -4.0f };	//=> デフォルトの重力値
}

// コンストラクタ
LiquidFunWorldManager::LiquidFunWorldManager()
	: mWorld( std::make_shared< LiquidFunWorld >( LiquidFunVec2( DEFAULT_GRAVITY.x, DEFAULT_GRAVITY.y ) ) )
	, mScheduler( std::make_shared< LiquidFunScheduler >( mWorld ) )
	, mGravity( DEFAULT_GRAVITY )
{
	
}

// 更新
void LiquidFunWorldManager::update()
{
	mScheduler->update();
}

// コンタクトリスナの登録
void LiquidFunWorldManager::registerContactListener( LiquidFunBaseContactListener* contactListener )
{
	mWorld->SetContactListener( contactListener );
}

// ボディの追加
LiquidFunBody* LiquidFunWorldManager::addBody( const LiquidFunBodyDesc* bodyDesc )
{
	return mWorld->CreateBody( bodyDesc );
}

// ジョイントの追加
LiquidFunJoint* LiquidFunWorldManager::addJoint( const LiquidFunJointDesc* jointDesc )
{
	return mWorld->CreateJoint( jointDesc );
}

// パーティクルの追加
LiquidFunParticle* LiquidFunWorldManager::addParticle( const LiquidFunParticleDesc* particleDesc )
{
	return mWorld->CreateParticleSystem( particleDesc );
}

// ボディの削除
void LiquidFunWorldManager::deleteBody( LiquidFunBody* body )
{
	mWorld->DestroyBody( body );
	
	body = nullptr;
}

// ジョイントの削除
void LiquidFunWorldManager::deleteJoint( LiquidFunJoint* joint )
{
	mWorld->DestroyJoint( joint );
	
	joint = nullptr;
}

// パーティクルの削除
void LiquidFunWorldManager::deleteParticle( LiquidFunParticle* particle )
{
	mWorld->DestroyParticleSystem( particle );
	
	particle = nullptr;
}

// 重力値の取得
Vect LiquidFunWorldManager::getGravity() const
{
	return mGravity;
}

// 重力値の設定
void LiquidFunWorldManager::setGravity( const Vect& gravity )
{
	if ( mGravity == gravity )
	{
		return;
	}
	
	mGravity = gravity;
	mWorld->SetGravity( { mGravity.x, mGravity.y } );
}