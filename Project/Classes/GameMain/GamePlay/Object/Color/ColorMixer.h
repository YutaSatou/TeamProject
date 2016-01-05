#ifndef _COLOR_MIXER_H_
#define _COLOR_MIXER_H_

#include "ColorCMY.h"
#include "Utility/Template/SmartPtr.h"

namespace cocos2d
{
	class Node;
}

class ColorHelper;

/*------------------------------------------------------------*/
//	@class		：	ColorMixer
//	@brief		：	色合成者
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class ColorMixer
{
	
public:
	
	/**
	 *	@brief	コンストラクタ
	 */
	ColorMixer();
	
	/**
	 *	@brief	デストラクタ
	 */
	~ColorMixer() = default;
	
	/**
	 *	@brief	色の合成
	 *	@param	blendBaseNode	合成元の色を持つノード
	 *	@param	blendNode		合成する色を持つノード
	 *	@param	blendRate		合成する割合
	 *	@return	ColorCMY		合成した色
	 */
	ColorCMY blend( cocos2d::Node* blendBaseNode, cocos2d::Node* blendNode, double blendRate = 0.5 ) const;
	
private:
	
	/**
	 *	@brief	色の合成
	 *	@param	src			合成する色( 前面 )
	 *	@param	dst			合成する色( 背面 )
	 *	@param	blendRate	合成する割合
	 *	@return	ColorCMY	合成した色
	 */
	ColorCMY colorBlend( const ColorCMY& src, const ColorCMY& dst, double blendRate ) const;
	
private:
	
	SharedPtr< ColorHelper > mColorHelper;	//=> 合成色の補助
};

#endif