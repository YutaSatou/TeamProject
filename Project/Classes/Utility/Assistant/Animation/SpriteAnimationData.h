#ifndef _SPRITE_ANIMATION_DATA_H_
#define _SPRITE_ANIMATION_DATA_H_

#include <string>

namespace cocos2d
{
	class Size;
	class Animate;
	class AnimationCache;
}

/*------------------------------------------------------------*/
//	@class		：	SpriteAnimationData
//	@brief		：	スプライトアニメーションデータ
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class SpriteAnimationData
{
	
public:
	
	/**
	 *	@brief	コンストラクタ
	 */
	SpriteAnimationData();
	
	/**
	 *	@brief	デストラクタ
	 */
	~SpriteAnimationData() = default;
	
	/**
	 *	@brief	アニメーションの追加
	 *	@param	fileName		アニメーションを作成するテクスチャの名前
	 *	@param	animationName	作成したアニメーションに紐付ける名前
	 *	@param	frameSize		切り出すフレームの大きさ
	 *	@param	frameCount		切り出すフレームの数
	 */
	void addAnimation( const std::string& fileName, const std::string& animationName, const cocos2d::Size& frameSize, int frameCount );
	
	/**
	 *	@brief	アニメイトの生成
	 *	@param	animationName		アニメーションの名前
	 *	@param	frameSwitchSpeed	フレームを切り替える速度
	 *	@return	Animate				インスタンス
	 */
	cocos2d::Animate* createAnimate( const std::string& animationName, float frameSwitchSpeed );
	
private:
	
	cocos2d::AnimationCache* mAnimationCache;	//=> アニメーションキャッシュ
};

#endif