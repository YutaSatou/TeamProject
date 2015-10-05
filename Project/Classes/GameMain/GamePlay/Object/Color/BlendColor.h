#ifndef _BLEND_COLOR_H_
#define _BLEND_COLOR_H_

#include "cocos2d.h"

/*------------------------------------------------------------*/
//	@class		：	BlendColor
//	@brief		：	合成色
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class BlendColor : public cocos2d::Ref
{
	
protected:
	
	/**
	 *	@brief	コンストラクタ
	 *	@param	_color	合成色
	 */
	BlendColor( const cocos2d::Color3B& _color );
	
	/**
	 *	@brief	デストラクタ
	 */
	~BlendColor() = default;
	
public:
	
	/**
	 *	@brief	インスタンスの生成
	 *	@param	_color		合成色
	 *	@return	BlendColor	インスタンス
	 */
	static BlendColor* create( const cocos2d::Color3B& _color );
	
public:
	
	cocos2d::Color3B	color;	//=> 合成色
};

#endif