#ifndef _LIQUID_FUN_PARTICLE_DESC_CREATOR_H_
#define _LIQUID_FUN_PARTICLE_DESC_CREATOR_H_

#include "../Core/LiquidFunBox2D.h"

namespace cocos2d
{
	class Color3B;
	class Vec2;
}

/*------------------------------------------------------------*/
//	@class		：	LiquidFunParticleDescCreator
//	@brief		：	LiquidFunのパーティクル設定記述子生成者
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class LiquidFunParticleDescCreator
{
	
public:
	
	/**
	 *	@brief	コンストラクタ
	 */
	LiquidFunParticleDescCreator() = delete;
	
	/**
	 *	@brief	デストラクタ
	 */
	~LiquidFunParticleDescCreator() = delete;
	
	/**
	 *	@brief	パーティクル設定記述子の生成
	 *	@param	particleSize			粒子1つの大きさ
	 *	@return	LiquidFunParticleDesc	パーティクル設定記述子
	 */
	LiquidFunParticleDesc createParticleDesc( float particleSize );
	
	/**
	 *	@brief	パーティクルグループ設定記述子の生成
	 *	@param	particleType				パーティクルの種類
	 *	@param	color						パーティクルの色
	 *	@param	position					パーティクルグループの座標
	 *	@param	groupSize					パーティクルグループの大きさ
	 *	@param	alpha						パーティクルのα値
	 *	@return	LiquidFunParticleGroupDesc	パーティクルグループ設定記述子
	 */
	LiquidFunParticleGroupDesc createParticleGroupDesc( const LiquidFunParticleType& particleType, const cocos2d::Color3B& color, const cocos2d::Vec2& position, float groupSize, float alpha = 255.0f );
};

#endif