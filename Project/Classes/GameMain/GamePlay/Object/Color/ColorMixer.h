#ifndef _COLOR_MIXER_H_
#define _COLOR_MIXER_H_

#include "ColorRYB.h"
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
	 *	@param	blendBaseNode	合成元の色を持つノード
	 *	@param	blendNode		合成する色を持つノード
	 *	@return	ColorRYB		合成した色
	 */
	ColorRYB blend( cocos2d::Node* blendBaseNode, cocos2d::Node* blendNode ) const;
	
private:
	
	/**
	 *	@brief	色の合成
	 *	@param	src			合成する色( 前面 )
	 *	@param	dst			合成する色( 背面 )
	 *	@return	ColorRYB	合成した色
	 */
	ColorRYB colorBlend( const ColorRYB& src, const ColorRYB& dst ) const;
	
private:
	
	using ColorHelperPtr = std::shared_ptr< ColorHelper >;
	
	ColorHelperPtr mColorHelper;	//=> 合成色の補助
};

#endif