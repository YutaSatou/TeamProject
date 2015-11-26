#ifndef _UI_LAYER_H_
#define _UI_LAYER_H_

#include "cocos2d.h"

/*------------------------------------------------------------*/
//	@class		：	UILayer
//	@brief		：	ユーザインタフェイスレイヤ
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class UILayer : public cocos2d::Layer
{
	
protected:
	
	/**
	 *	@brief	コンストラクタ
	 */
	UILayer() = default;
	
	/**
	 *	@brief	デストラクタ
	 */
	~UILayer() = default;
	
	/**
	 *	@brief	初期化
	 *	@return	bool	初期化が完了したか否か
	 */
	virtual bool init() override;
	
public:
	
	/**
	 *	@brief	インスタンスの生成
	 *	@return	UILayer	インスタンス
	 */
	static UILayer* create();
};

#endif