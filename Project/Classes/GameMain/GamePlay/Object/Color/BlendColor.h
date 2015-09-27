#ifndef _BLEND_COLOR_H_
#define _BLEND_COLOR_H_

#include "cocos2d.h"

/**
 *	@brief	合成色の種類
 */
enum BlendColorType : int
{
	COLORLESS	= 0,	// 無
	RED			= 1,	// 赤
	BLUE		= 2,	// 青
	PURPLE		= 3,	// 紫
	LENGTH,
};

/*------------------------------------------------------------*/
//	@struct		：	BlendColor
//	@brief		：	合成色
//	@author		：	利川聖太
/*------------------------------------------------------------*/
struct BlendColor : public cocos2d::Ref
{
	
protected:
	
	/**
	 *	@brief	コンストラクタ
	 *	@param	_type	合成色
	 */
	BlendColor( BlendColorType _type );
	
	/**
	 *	@brief	デストラクタ
	 */
	~BlendColor() = default;
	
public:
	
	/**
	 *	@brief	インスタンスの生成
	 *	@param	_type		合成色
	 *	@return	BlendColor	インスタンス
	 */
	static BlendColor* create( BlendColorType _type );
	
public:
	
	BlendColorType	type;	//=> 合成色
};

#endif