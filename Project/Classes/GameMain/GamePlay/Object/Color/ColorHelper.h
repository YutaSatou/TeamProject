#ifndef _COLOR_HELPER_H_
#define _COLOR_HELPER_H_

#include "ColorRYB.h"

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
	 *	@return	ColorRYB		合成色
	 */
	ColorRYB getBlendColor( cocos2d::Node* node, cocos2d::Node* contactNode ) const;
	
private:
	
	/**
	 *	@brief	合成色の抽出
	 *	@param	node		ユーザデータが設定されているノード
	 *	@return	ColorRYB	ユーザデータから抽出した合成色
	 */
	ColorRYB* extractBlendColor( cocos2d::Node* node ) const;
};

#endif