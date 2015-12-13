#include "LiquidFunParticleDescCreator.h"
#include "cocos2d.h"
#include "../Core/LiquidFunHelper.h"

using namespace cocos2d;

// パーティクル設定記述子の生成
LiquidFunParticleDesc LiquidFunParticleDescCreator::createParticleDesc( float particleSize )
{
	LiquidFunParticleDesc particleDesc;
	
	particleDesc.radius				= LiquidFunHelper::toMeter( particleSize / 2.0f );
	particleDesc.strictContactCheck	= true;
	
	return particleDesc;
}

// パーティクルグループ設定記述子の生成
LiquidFunParticleGroupDesc LiquidFunParticleDescCreator::createParticleGroupDesc( const LiquidFunParticleType& particleType, const Color3B& color, const Vec2& position, float groupSize, float alpha )
{
	LiquidFunCircleShape		shape;
	LiquidFunParticleGroupDesc	groupDesc;
	
	shape.m_radius		= LiquidFunHelper::toMeter( groupSize / 2.0f );
	groupDesc.shape		= &shape;
	groupDesc.flags		= particleType | LiquidFunParticleType::b2_fixtureContactListenerParticle;
	groupDesc.color		= LiquidFunParticleColor( color.r, color.g, color.b, alpha );
	groupDesc.position	= LiquidFunHelper::toMeter( position );
	
	return groupDesc;
}