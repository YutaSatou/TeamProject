#ifndef _BRUSH_TRAIL_H_
#define _BRUSH_TRAIL_H_

#include "cocos2d.h"
#include "BrushBody.h"

class Canvas;

/*------------------------------------------------------------*/
//	@class		：	BrushTrail
//	@brief		：	ブラシの軌跡
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class BrushTrail : public cocos2d::Node
{
	
protected:
	
	/**
	 *	@brief	コンストラクタ
	 */
	BrushTrail();
	
	/**
	 *	@brief	デストラクタ
	 */
	~BrushTrail() = default;
	
	/**
	 *	@brief	初期化
	 *	@return	bool	初期化が完了したか否か
	 */
	virtual bool init() override;
	
public:
	
	/**
	 *	@brief	インスタンスの生成
	 *	@return	BrushTrail	インスタンス
	 */
	static BrushTrail* create();
	
	/**
	 *	@brief	ブラシ描き始め
	 *	@param	touch	タッチ情報
	 */
	void writeBegin( cocos2d::Touch* touch );
	
	/**
	 *	@brief	ブラシ描き途中
	 *	@param	touch	タッチ情報
	 */
	void writeMove( cocos2d::Touch* touch );
	
	/**
	 *	@brief	ブラシ描き終わり
	 *	@param	touch		タッチ情報
	 *	@param	parentNode	親ノード
	 *	@return	bool		描くことに成功したか否か
	 */
	bool writeEnd( cocos2d::Touch* touch, cocos2d::Node* parentNode );
	
private:
	
	/**
	 *	@brief	軌跡の描画
	 *	@param	start	軌跡の開始地点
	 *	@param	end		軌跡の終了地点
	 */
	void drawTrail( const cocos2d::Vec2& start, const cocos2d::Vec2& end );
	
private:
	
	Canvas*				mCanvas;				//=> キャンバス
	BrushBody			mBrushBody;				//=> ブラシ用のボディ
	cocos2d::Vec2		mPreviousTouchPoint;	//=> 前回のタッチ座標
	cocos2d::Vec2		mTrailOffset;			//=> 軌跡の座標オフセット
};

#endif