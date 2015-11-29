#include "LiquidFunContactListener.h"
#include "../Core/LiquidFunWorldManager.h"

using namespace cocos2d;

// コンストラクタ
LiquidFunContactListener::LiquidFunContactListener()
	: onContactBegin( []( LiquidFunContact* ) { } )
	, onContactPreSolve( []( LiquidFunContact*, const LiquidFunManifold* ) { } )
	, onContactEnd( []( LiquidFunContact* ) { } )
{
	
}

// 初期化
bool LiquidFunContactListener::init()
{
	if ( !Node::init() )
	{
		return false;
	}
	
	// 自身を登録する。
	LiquidFunWorldManager::getInstance().registerContactListener( this );
	
	return true;
}

// インスタンスの生成
LiquidFunContactListener* LiquidFunContactListener::create()
{
	LiquidFunContactListener* inst = new LiquidFunContactListener();
	
	if ( inst && inst->init() )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

// 接触時に呼ばれるコールバック関数
void LiquidFunContactListener::BeginContact( LiquidFunContact* contact )
{
	onContactBegin( contact );
}

// 接触中に呼ばれるコールバック関数
void LiquidFunContactListener::PreSolve( LiquidFunContact* contact, const LiquidFunManifold* oldManifold )
{
	onContactPreSolve( contact, oldManifold );
}

// 離脱時に呼ばれるコールバック関数
void LiquidFunContactListener::EndContact( LiquidFunContact* contact )
{
	onContactEnd( contact );
}

// 接触時に呼ばれるコールバック関数( パーティクル )
void LiquidFunContactListener::BeginContact( LiquidFunParticle* particle, LiquidFunParticleBodyContact* contact )
{
	onContactParticleBegin( particle, contact );
}

// 離脱時に呼ばれるコールバック関数( パーティクル )
void LiquidFunContactListener::EndContact( LiquidFunFixture* fixture, LiquidFunParticle* particle, signed int index )
{
	onContactParticleEnd( fixture, particle, index );
}