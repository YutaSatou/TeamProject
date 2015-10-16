#ifndef _COLOR_MIXER_H_
#define _COLOR_MIXER_H_

#include "ColorCMY.h"
#include <memory>

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
	 *	@param	node		ノード
	 *	@param	contactNode	接触したノード
	 *	@param	saturation	色の彩度
	 *	@return	ColorCMY	合成した色
	 */
	ColorCMY blend( cocos2d::Node* node, cocos2d::Node* contactNode, float saturation = 1.0f ) const;
	
private:
	
	/**
	 *	@brief	色の合成
	 *	@param	src			合成する色( 前面 )
	 *	@param	dst			合成する色( 背面 )
	 *	@param	saturation	色の彩度
	 *	@return	ColorCMY	合成した色
	 */
	ColorCMY colorBlend( const ColorCMY& src, const ColorCMY& dst, float saturation ) const;
	
	/**
	 *	@brief	彩度の補正
	 *	@param	colorElement	色の要素
	 *	@param	saturation		色の彩度
	 */
	void revisedSaturation( float* colorElement, float saturation ) const;
	
private:
	
	using ColorHelperPtr = std::shared_ptr< ColorHelper >;
	
	ColorHelperPtr mColorHelper; //=> 合成色の補助
};

#endif