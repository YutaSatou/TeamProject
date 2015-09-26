#ifndef _OBJECT_DATA_H_
#define _OBJECT_DATA_H_

#include "cocos2d.h"
#include "../Color/BlendColor.h"

/*------------------------------------------------------------*/
//	@struct		：	ObjectData
//	@brief		：	オブジェクトデータ
//	@author		：	利川聖太
/*------------------------------------------------------------*/
struct ObjectData
{
	using Ptr = std::shared_ptr< ObjectData >;
	
	BlendColor*					blendColor;	//=> 合成色
	cocos2d::Vec2				position;	//=> 座標
	cocos2d::PhysicsMaterial	material;	//=> 物理特性
	
	/**
	 *	@brief	コンストラクタ
	 */
	ObjectData()
		: blendColor( BlendColor::create( BlendColorType::COLORLESS ) )
		, position( cocos2d::Vec2::ZERO )
		, material()
	{
		
	}
	
	/**
	 *	@brief	コンストラクタ
	 *	@param	_type		合成色
	 *	@param	_position	座標
	 *	@param	_material	物理特性
	 */
	ObjectData( const BlendColorType& _type, const cocos2d::Vec2& _position, const cocos2d::PhysicsMaterial& _material )
		: blendColor( BlendColor::create( _type ) )
		, position( _position )
		, material( _material )
	{
		
	}
};

#endif