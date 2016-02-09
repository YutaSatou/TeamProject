#ifndef _LIQUID_FUN_DEBUG_DRAWER_H_
#define _LIQUID_FUN_DEBUG_DRAWER_H_

#include "cocos2d.h"

class GLESDebugDraw;

/*------------------------------------------------------------*/
//	@class		：	LiquidFunDebugDrawer
//	@brief		：	LiquidFunのデバッグ描画
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class LiquidFunDebugDrawer : public cocos2d::Layer
{
	
protected:
	
	/**
	 *	@brief	コンストラクタ
	 */
	LiquidFunDebugDrawer();
	
	/**
	 *	@brief	デストラクタ
	 */
	~LiquidFunDebugDrawer();
	
	/**
	 *	@brief	初期化
	 *	@return	bool	初期化が完了したか否か
	 */
	virtual bool init() override;
	
	/**
	 *	@brief	描画
	 *	@param	renderer	レンダラ
	 *	@param	transform	トランスフォーム
	 *	@param	flags		ビットフラグ
	 */
	virtual void draw( cocos2d::Renderer* renderer, const cocos2d::Mat4& transform, std::uint32_t flags ) override;
	
public:
	
	/**
	 *	@brief	インスタンスの生成
	 *	@return	LiquidFunDebugDrawer	インスタンス
	 */
	static LiquidFunDebugDrawer* create();
	
private:
	
	/**
	 *	@brief	デバッグ描画フラグの初期化
	 */
	void initDebugDrawFlags();
	
	/**
	 *	@brief	描画のコールバック関数
	 */
	void onDraw();
	
private:
	
	GLESDebugDraw*			mDebugRenderer;		//=> デバッグ描画用レンダラ
	cocos2d::CustomCommand	mDebugDrawCommand;	//=> デバッグ描画用コマンド
	cocos2d::Mat4			mModelView;			//=> モデルビュ
};

#endif