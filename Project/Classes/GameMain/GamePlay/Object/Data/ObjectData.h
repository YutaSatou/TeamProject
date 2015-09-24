#ifndef _OBJECT_DATA_H_
#define _OBJECT_DATA_H_

#include "cocos2d.h"
#include "../Collision/ContactCategory.h"

/*------------------------------------------------------------*/
//	@struct		：	PhysicsData
//	@brief		：	物理特性のデータ
//	@author		：	利川聖太
/*------------------------------------------------------------*/
struct PhysicsData
{
	cocos2d::PhysicsMaterial	material;	//=> マテリアル
	ContactCategory				category;	//=> カテゴリ
	
	/**
	 *	@brief	コンストラクタ
	 */
	PhysicsData()
		: material( 0.0f, 0.0f, 0.0f )
		, category( ContactCategory::ALL_CATEGORY ) { }
	
	/**
	 *	@brief	コンストラクタ
	 *	@param	_material	マテリアル
	 *	@param	_category	カテゴリ
	 */
	PhysicsData( const cocos2d::PhysicsMaterial& _material, ContactCategory _category )
		: material( _material )
		, category( _category ) { }
};

/*------------------------------------------------------------*/
//	@struct		：	ObjectData
//	@brief		：	オブジェクトのデータ
//	@author		：	利川聖太
/*------------------------------------------------------------*/
struct ObjectData
{
	cocos2d::Vec2		position;	// 座標
	cocos2d::Size		size;		// 大きさ
	cocos2d::Color3B	blendColor;	// 色合成用の色
	PhysicsData			physics;	// 物理特性
	
	/**
	 *	@brief	コンストラクタ
	 */
	ObjectData()
		: position( cocos2d::Vec2::ZERO )
		, size( cocos2d::Size::ZERO )
		, blendColor( cocos2d::Color3B::WHITE )
		, physics() { }
	
	/**
	 *	@brief	コンストラクタ
	 *	@param	_position	座標
	 *	@param	_size		大きさ
	 *	@param	_blendColor	色合成用の色
	 *	@param	_physics	物理特性
	 */
	ObjectData( const cocos2d::Vec2& _position, const cocos2d::Size& _size, const cocos2d::Color3B& _blendColor, const PhysicsData& _physics )
		: position( _position )
		, size( _size )
		, blendColor( _blendColor )
		, physics( _physics ) { }
};

#endif