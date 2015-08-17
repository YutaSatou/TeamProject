#ifndef _CANVAS_H_
#define _CANVAS_H_

#include "cocos2d.h"

/*------------------------------------------------------------*/
//	@class		：	Canvas
//	@brief		：	キャンバス
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class Canvas : public cocos2d::Node
{
	
protected:
	
	/**
	 *	@brief	コンストラクタ
	 */
	Canvas();
	
	/**
	 *	@brief	デストラクタ
	 */
	~Canvas() = default;
	
	/**
	 *	@brief	初期化
	 *	@return	bool	初期化が完了したか否か
	 */
	virtual bool init() override;
	
public:
	
	/**
	 *	@brief	インスタンスの生成
	 *	@return	Canvas	インスタンス
	 */
	static Canvas* create();
	
	/**
	 *	@brief	キャンバスのリセット
	 */
	void resetCanvas();
	
	/**
	 *	@brief	レンダリングの開始
	 */
	void renderingBegin();
	
	/**
	 *	@brief	レンダリングの終了
	 */
	void renderingEnd();
	
	/**
	 *	@brief	レンダリングターゲットの追加
	 *	@param	object	キャンバスに焼き付けるオブジェクト
	 */
	void addRenderingTarget( cocos2d::Node* object );
	
	/**
	 *	@brief	イメージの生成
	 *			キャンバスに描画されているオブジェクトを
	 *			テクスチャ1つにまとめてイメージとして返却する。
	 *	@return	Image	イメージ( 自動解放ではないので注意。 )
	 */
	cocos2d::Image* createImage();
	
private:
	
	cocos2d::RenderTexture* mRenderTexture; //=> レンダテクスチャ
};

#endif