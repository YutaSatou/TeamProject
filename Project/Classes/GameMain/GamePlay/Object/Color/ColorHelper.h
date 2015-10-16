#ifndef _COLOR_HELPER_H_
#define _COLOR_HELPER_H_

#include "ColorCMY.h"

namespace cocos2d
{
	class Node;
}

/*------------------------------------------------------------*/
//	@class		：	ColorHelper
//	@brief		：	合成色の補助
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class ColorHelper
{
	
public:
	
	/**
	 *	@brief	コンストラクタ
	 */
	ColorHelper() = default;
	
	/**
	 *	@brief	デストラクタ
	 */
	~ColorHelper() = default;
	
	/**
	 *	@brief	合成色の取得
	 *	@param	node			ノード
	 *	@param	contactNode		接触したノード
	 *	@return	ColorCMY		合成色
	 */
	ColorCMY getBlendColor( cocos2d::Node* node, cocos2d::Node* contactNode ) const;
	
private:
	
	/**
	 *	@brief	合成色の抽出
	 *	@param	node		ユーザデータが設定されているノード
	 *	@return	ColorCMY	ユーザデータから抽出した合成色
	 */
	ColorCMY* extractBlendColor( cocos2d::Node* node ) const;
};

#endif