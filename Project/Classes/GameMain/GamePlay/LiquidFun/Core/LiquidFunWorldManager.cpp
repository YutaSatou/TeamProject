#include "LiquidFunWorldManager.h"
#include "LiquidFunScheduler.h"
#include "LiquidFunHelper.h"

using namespace cocos2d;

namespace
{
	const Vect DEFAULT_GRAVITY = Vect( 0.0f, -6.0f );	//=> デフォルトの重力値
}

// コンストラクタ
LiquidFunWorldManager::LiquidFunWorldManager()
	: mWorld( new LiquidFunWorld( LiquidFunVec2( DEFAULT_GRAVITY.x, DEFAULT_GRAVITY.y ) ) )
	, mScheduler( new LiquidFunScheduler( mWorld ) )
	, mGravity( DEFAULT_GRAVITY )
{
	
}

// デストラクタ
LiquidFunWorldManager::~LiquidFunWorldManager()
{
	CC_SAFE_DELETE( mWorld );
	CC_SAFE_DELETE( mScheduler );
}

// 更新
void LiquidFunWorldManager::update()
{
	mScheduler->update();
}

// ワールドのリセット
void LiquidFunWorldManager::resetWorld()
{
	LiquidFunBody* body = mWorld->GetBodyList();
	
	while ( body )
	{
		// ボディをコピーする。
		b2Body* currentBody = body;
		
		// コピー元のボディは次のボディを取得する。
		body = body->GetNext();
		
		// ワールドからボディを削除する。
		deleteBody( currentBody );
	}
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
}

// ジョイントの削除
void LiquidFunWorldManager::deleteJoint( LiquidFunJoint* joint )
{
	mWorld->DestroyJoint( joint );
}

// パーティクルの削除
void LiquidFunWorldManager::deleteParticle( LiquidFunParticle* particle )
{
	mWorld->DestroyParticleSystem( particle );
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
	mWorld->SetGravity( LiquidFunVec2( mGravity.x, mGravity.y ) );
}