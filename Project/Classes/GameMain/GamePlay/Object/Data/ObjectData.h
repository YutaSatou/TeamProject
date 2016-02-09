#ifndef _OBJECT_DATA_H_
#define _OBJECT_DATA_H_

#include "cocos2d.h"
#include "../Color/ColorCMY.h"
#include "../Color/ColorStack.h"
#include "../../LiquidFun/User/LiquidFunMaterial.h"

/*------------------------------------------------------------*/
//	@struct		：	ObjectData
//	@brief		：	オブジェクトデータ
//	@author		：	利川聖太
/*------------------------------------------------------------*/
struct ObjectData
{
	ColorCMY			blendColor;		//=> 合成色
	ColorStack			backupColor;	//=> 合成色のバックアップ
	std::string			textureName;	//=> テクスチャの名前
	cocos2d::Color3B	textureColor;	//=> テクスチャの色
	cocos2d::Vec2		position;		//=> 座標
	LiquidFunMaterial	material;		//=> マテリアル
	std::uint8_t		alpha;			//=> α値
	
	/**
	 *	@brief	コンストラクタ
	 */
	ObjectData()
		: blendColor( ColorCMY::WHITE )
		, backupColor()
		, textureName()
		, textureColor( cocos2d::Color3B::WHITE )
		, position( cocos2d::Vec2::ZERO )
		, material()
		, alpha( 0 )
	{
		
	}
	
	/**
	 *	@brief	コンストラクタ
	 *	@param	_textureName	テクスチャの名前
	 *	@param	_textureColor	テクスチャの色
	 *	@param	_position		座標
	 *	@param	_material		マテリアル
	 *	@param	_alpha			α値
	 */
	ObjectData
	(
		const std::string&			_textureName,
		const cocos2d::Color3B&		_textureColor,
		const cocos2d::Vec2&		_position,
		const LiquidFunMaterial&	_material,
		const std::uint8_t			_alpha
	)
		: blendColor( ColorCMY::convertToCMY( _textureColor ) )
		, backupColor()
		, textureName( _textureName )
		, textureColor( _textureColor )
		, position( _position )
		, material( _material )
		, alpha( _alpha )
	{
		
	}
};

#endif