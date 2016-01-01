#ifndef _LIQUID_FUN_PARTICLE_SETTLOR_H_
#define _LIQUID_FUN_PARTICLE_SETTLOR_H_

#include "../../LiquidFun/LiquidFunDefine.h"

/*------------------------------------------------------------*/
//	@class		：	LiquidFunParticleSettlor
//	@brief		：	LiquidFunのパーティクル設定者
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class LiquidFunParticleSettlor
{
	
public:
	
	/**
	 *	@brief	コンストラクタ
	 */
	LiquidFunParticleSettlor() = delete;
	
	/**
	 *	@brief	デストラクタ
	 */
	~LiquidFunParticleSettlor() = delete;
	
	/**
	 *	@brief	パーティクルの装着
	 *	@param	particleDesc		パーティクル設定記述子
	 *	@return	LiquidFunParticle	パーティクルのインスタンス
	 */
	static LiquidFunParticle* attachParticle( const LiquidFunParticleDesc& particleDesc );
	
	/**
	 *	@brief	パーティクルグループの装着
	 *	@param	particle				パーティクルグループを装着するパーティクル
	 *	@param	groupDesc				パーティクルグループ設定記述子
	 *	@return	LiquidFunParticleGroup	パーティクルグループのインスタンス
	 */
	static LiquidFunParticleGroup* attachParticleGroup( LiquidFunParticle* particle, LiquidFunParticleGroupDesc& groupDesc );
	
	/**
	 *	@brief	パーティクルの装着解除
	 *	@param	particle	装着解除するパーティクル
	 */
	static void detachParticle( LiquidFunParticle* particle );
	
	/**
	 *	@brief	パーティクルグループの装着解除
	 *	@param	particle	パーティクルグループを装着しているパーティクル
	 *	@param	group		装着解除するパーティクルグループ
	 */
	static void detachParticleGroup( LiquidFunParticle* particle, LiquidFunParticleGroup* group );
};

#endif