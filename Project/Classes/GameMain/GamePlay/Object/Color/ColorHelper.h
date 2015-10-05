#ifndef _COLOR_HELPER_H_
#define _COLOR_HELPER_H_

#include "cocos2d.h"
#include "BlendColor.h"

/*------------------------------------------------------------*/
//	@class		：	ColorHelper
//	@brief		：	合成色の補助
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class ColorHelper
{
	
public:
	
	/**
	 *	@brief	合成色の取得
	 *	@param	node			ノード
	 *	@param	contactNode		接触したノード
	 *	@return	Color3B			合成色
	 */
	cocos2d::Color3B getBlendColor( cocos2d::Node* node, cocos2d::Node* contactNode ) const;
	
private:
	
	/**
	 *	@brief	合成色の抽出
	 *	@param	node		ユーザオブジェクトが設定されているノード
	 *	@return	BlendColor	ユーザオブジェクトから抽出した合成色
	 */
	BlendColor* extractBlendColor( cocos2d::Node* node ) const;
};

#endif