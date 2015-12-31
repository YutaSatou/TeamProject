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
	LiquidFunParticleDescCreator() = default;
	
	/**
	 *	@brief	デストラクタ
	 */
	~LiquidFunParticleDescCreator() = default;
	
	/**
	 *	@brief	パーティクル設定記述子の生成
	 *	@param	particleSize			パーティクル単体の大きさ
	 *	@return	LiquidFunParticleDesc	パーティクル設定記述子
	 */
	LiquidFunParticleDesc createParticleDesc( float particleSize );
	
	/**
	 *	@brief	パーティクルグループ設定記述子の生成
	 *	@param	color						パーティクルの色
	 *	@param	position					パーティクルの座標
	 *	@param	particleType				パーティクルの種類
	 *	@param	groupSize					パーティクルグループの大きさ
	 *	@return	LiquidFunParticleGroupDesc	パーティクルグループ設定記述子
	 */
	LiquidFunParticleGroupDesc createParticleGroupDesc( const cocos2d::Color3B& color, const cocos2d::Vec2& position, uint16_t particleType, float groupSize );
};

#endif