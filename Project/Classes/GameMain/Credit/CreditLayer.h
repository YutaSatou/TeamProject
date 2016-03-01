#ifndef _CREDIT_LAYER_H_
#define _CREDIT_LAYER_H_

#include "cocos2d.h"

/*------------------------------------------------------------*/
//	@class		：	CreditLayer
//	@brief		：	クレジットレイヤ
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class CreditLayer : public cocos2d::Layer
{
	
protected:
	
	/**
	 *	@brief	コンストラクタ
	 */
	CreditLayer() = default;
	
	/**
	 *	@brief	デストラクタ
	 */
	~CreditLayer() = default;
	
	/**
	 *	@brief	初期化
	 *	@return	bool	初期化が完了したか否か
	 */
	virtual bool init() override;
	
public:
	
	/**
	 *	@brief	インスタンスの生成
	 *	@return	CreditLayer	インスタンス
	 */
	static CreditLayer* create();
	
private:
	
	/**
	 *	@brief	タッチリスナの初期化
	 */
	void initTouchListener();
	
	/**
	 *	@brief	背景の追加
	 */
	void addBackground();
};

#endif