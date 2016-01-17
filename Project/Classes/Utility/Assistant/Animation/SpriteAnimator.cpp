#include "SpriteAnimator.h"
#include "cocos2d.h"

using namespace cocos2d;

namespace
{
	const int ACTION_TAG_UNIQUE { 1245780 };	//=> アクションのタグ
}

// コンストラクタ
SpriteAnimator::SpriteAnimator( cocos2d::Sprite* targetSprite, const SpriteAnimationData& animationData )
	: mTargetSprtite( targetSprite )
	, mAnimationData( animationData )
{
	
}

// アニメーションの再生
void SpriteAnimator::play( const std::string& animationName, float frameSwitchSpeed, bool isLoop )
{
	// フレーム単位に変換する。
	frameSwitchSpeed *= 0.0166f;
	
	Animate* animate { mAnimationData.createAnimate( animationName, frameSwitchSpeed ) };
	
	if ( isLoop )
	{
		ActionInterval* repeatAction { RepeatForever::create( animate ) };
		repeatAction->setTag( ACTION_TAG_UNIQUE );
		mTargetSprtite->runAction( repeatAction );
		return;
	}
	
	animate->setTag( ACTION_TAG_UNIQUE );
	mTargetSprtite->runAction( animate );
}

// アニメーションの停止
void SpriteAnimator::stop()
{
	mTargetSprtite->stopActionByTag( ACTION_TAG_UNIQUE );
}

// アニメーションを行うスプライトの変更
void SpriteAnimator::changeTarget( Sprite* targetSprite )
{
	mTargetSprtite = targetSprite;
}