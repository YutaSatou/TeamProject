#ifndef _BRUSH_H_
#define _BRUSH_H_

#include "cocos2d.h"

class BrushTrail;
class GameControlMediator;

/*------------------------------------------------------------*/
//	@class		：	Brush
//	@brief		：	ブラシ
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class Brush : public cocos2d::Node
{
	
protected:
	
	/**
	 *	@brief	コンストラクタ
	 *	@param	mediator	ゲーム制御仲介者
	 */
	explicit Brush( GameControlMediator& mediator );
	
	/**
	 *	@brief	デストラクタ
	 */
	~Brush() = default;
	
	/**
	 *	@brief	初期化
	 *	@return	bool	初期化が完了したか否か
	 */
	virtual bool init() override;
	
public:
	
	/**
	 *	@brief	インスタンスの生成
	 *	@param	mediator	ゲーム制御仲介者
	 *	@return	Brush		インスタンス
	 */
	static Brush* create( GameControlMediator& mediator );
	
	/**
	 *	@brief	タッチ開始時のコールバック関数
	 *	@param	touch	タッチ情報
	 *	@param	event	イベント情報
	 *	@return	bool	タッチ判定を有効にするか否か
	 */
	bool onTouchBegan( cocos2d::Touch* touch, cocos2d::Event* event );
	
	/**
	 *	@brief	タッチ移動時のコールバック関数
	 *	@param	touch	タッチ情報
	 *	@param	event	イベント情報
	 */
	void onTouchMoved( cocos2d::Touch* touch, cocos2d::Event* event );
	
	/**
	 *	@brief	タッチ終了時のコールバック関数
	 *	@param	touch	タッチ情報
	 *	@param	event	イベント情報
	 */
	void onTouchEnded( cocos2d::Touch* touch, cocos2d::Event* event );
	
private:
	
	/**
	 *	@brief	タッチリスナの初期化
	 */
	void initTouchListener();
	
private:
	
	BrushTrail*				mBrushTrail;	//=> ブラシの軌跡
	GameControlMediator&	mMediator;		//=> ゲーム制御仲介者
	bool					mIsWrite;		//=> 書いているか否か
	bool					mIsFirstWrite;	//=> 初めて書くか否か
};

#endif