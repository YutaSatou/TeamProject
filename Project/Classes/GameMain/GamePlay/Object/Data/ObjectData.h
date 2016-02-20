#ifndef _OBJECT_DATA_H_
#define _OBJECT_DATA_H_

#include "cocos2d.h"
#include "../Color/ColorRYB.h"
#include "../Color/ColorStack.h"
#include "../../LiquidFun/User/LiquidFunMaterial.h"

/*------------------------------------------------------------*/
//	@struct		：	ObjectData
//	@brief		：	オブジェクトデータ
//	@author		：	利川聖太
/*------------------------------------------------------------*/
struct ObjectData
{
	ColorRYB			blendColor;		//=> 合成色
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
		: blendColor( ColorRYB::WHITE )
		, backupColor()
		, textureName()
		, textureColor( cocos2d::Color3B::WHITE )
		, position( cocos2d::Vec2::ZERO )
		, material()
		, alpha( 0 )
	{
		
	}
};

#endif