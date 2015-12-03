#ifndef _LIQUID_FUN_MATERIAL_H_
#define _LIQUID_FUN_MATERIAL_H_

/*------------------------------------------------------------*/
//	@struct		：	LiquidFunMaterial
//	@brief		：	LiquidFunのマテリアル
//	@author		：	利川聖太
/*------------------------------------------------------------*/
struct LiquidFunMaterial
{
	float	density;		//=> 密度
	float	restitution;	//=> 反発係数
	float	friction;		//=> 摩擦係数
	
	/**
	 *	@brief	コンストラクタ
	 */
	LiquidFunMaterial()
		: density( 0.0f )
		, restitution( 0.0f )
		, friction( 0.0f ) { }
	
	/**
	 *	@brief	コンストラクタ
	 *	@param	_density		密度
	 *	@param	_restitution	反発係数
	 *	@param	_friction		摩擦係数
	 */
	LiquidFunMaterial( float _density, float _restitution, float _friction )
		: density( _density )
		, restitution( _restitution )
		, friction( _friction ) { }
};

#endif