#include "LiquidFunParticleSettlor.h"
#include "../Core/LiquidFunBox2D.h"
#include "../Core/LiquidFunWorldManager.h"

// パーティクルの装着
LiquidFunParticle* LiquidFunParticleSettlor::attachParticle( const LiquidFunParticleDesc& particleDesc )
{
	LiquidFunParticle* particle { LiquidFunWorldManager::getInstance().addParticle( &particleDesc ) };
	
	return particle;
}

// パーティクルグループの装着
LiquidFunParticleGroup* LiquidFunParticleSettlor::attachParticleGroup( LiquidFunParticle* particle, const LiquidFunParticleGroupDesc& groupDesc )
{
	return particle->CreateParticleGroup( groupDesc );
}

// パーティクルの装着解除
void LiquidFunParticleSettlor::detachParticle( LiquidFunParticle* particle )
{
	LiquidFunWorldManager::getInstance().deleteParticle( particle );
}

// パーティクルグループの装着解除
void LiquidFunParticleSettlor::detachParticleGroup( LiquidFunParticle* particle, LiquidFunParticleGroup* group )
{
	const int particleCount { group->GetParticleCount() };
	
	for ( int i = 0; i < particleCount; ++i )
	{
		uint16_t mask = particle->GetFlagsBuffer()[ i ];
		mask |= LiquidFunParticleType::b2_zombieParticle;
		particle->SetParticleFlags( i, mask );
	}
	
	detachParticle( particle );
}