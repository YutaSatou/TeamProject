#include "LiquidFunContactListener.h"
#include "../Core/LiquidFunWorldManager.h"

using namespace cocos2d;

// コンストラクタ
LiquidFunContactListener::LiquidFunContactListener()
	: onContactRigidBegin( []( LiquidFunContact* ) { } )
	, onContactRigidPreSolve( []( LiquidFunContact*, const LiquidFunManifold* ) { } )
	, onContactRigidEnd( []( LiquidFunContact* ) { } )
	, onContactLiquidBegin( []( LiquidFunParticle*, LiquidFunParticleBodyContact* ) { } )
	, onContactLiquidEnd( []( LiquidFunFixture*, LiquidFunParticle*, int ) { } )
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
	LiquidFunContactListener* inst { new LiquidFunContactListener() };
	
	if ( inst && inst->init() )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

// 剛体と剛体の接触時に呼ばれるコールバック関数
void LiquidFunContactListener::BeginContact( LiquidFunContact* contact )
{
	onContactRigidBegin( contact );
}

// 剛体と剛体の接触中に呼ばれるコールバック関数
void LiquidFunContactListener::PreSolve( LiquidFunContact* contact, const LiquidFunManifold* oldManifold )
{
	onContactRigidPreSolve( contact, oldManifold );
}

// 剛体と剛体の離脱時に呼ばれるコールバック関数
void LiquidFunContactListener::EndContact( LiquidFunContact* contact )
{
	onContactRigidEnd( contact );
}

// 剛体と液体の接触時に呼ばれるコールバック関数
void LiquidFunContactListener::BeginContact( LiquidFunParticle* particle, LiquidFunParticleBodyContact* contact )
{
	onContactLiquidBegin( particle, contact );
}

// 剛体と液体の離脱時に呼ばれるコールバック関数
void LiquidFunContactListener::EndContact( LiquidFunFixture* fixture, LiquidFunParticle* particle, int index )
{
	onContactLiquidEnd( fixture, particle, index );
}