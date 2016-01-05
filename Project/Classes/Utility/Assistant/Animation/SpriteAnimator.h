#ifndef _SPRITE_ANIMATOR_H_
#define _SPRITE_ANIMATOR_H_

#include "SpriteAnimationData.h"
#include <string>

namespace cocos2d
{
	class Sprite;
}

/*------------------------------------------------------------*/
//	@class		：	SpriteAnimator
//	@brief		：	スプライトアニメーション再生者
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class SpriteAnimator
{
	
public:
	
	/**
	 *	@brief	コンストラクタ
	 *	@param	targetSprite	アニメーションを行うスプライト
	 *	@param	animationData	登録するアニメーションデータ
	 */
	SpriteAnimator( cocos2d::Sprite* targetSprite, const SpriteAnimationData& animationData );
	
	/**
	 *	@brief	デストラクタ
	 */
	~SpriteAnimator() = default;
	
	/**
	 *	@brief	アニメーションの再生
	 *	@param	animationName		再生するアニメーションの名前
	 *	@param	frameSwitchSpeed	フレームを切り替える速度( 1.0f = 1Fで切り替える )
	 *	@param	isLoop				アニメーションをループさせるか否か
	 */
	void play( const std::string& animationName, float frameSwitchSpeed = 1.0f, bool isLoop = true );
	
	/**
	 *	@brief	アニメーションの停止
	 */
	void stop();
	
	/**
	 *	@brief	アニメーションを行うスプライトの変更
	 *	@param	targetSprite	アニメーションを行うスプライト
	 */
	void changeTarget( cocos2d::Sprite* targetSprite );
	
private:
	
	cocos2d::Sprite*	mTargetSprtite;	//=> アニメーションを行うスプライト
	SpriteAnimationData	mAnimationData;	//=> アニメーションデータ
};

#endif