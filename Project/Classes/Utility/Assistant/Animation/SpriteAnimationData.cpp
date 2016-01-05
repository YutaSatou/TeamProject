#include "SpriteAnimationData.h"
#include "cocos2d.h"

using namespace cocos2d;

// コンストラクタ
SpriteAnimationData::SpriteAnimationData()
	: mAnimationCache( AnimationCache::getInstance() )
{
	
}

// アニメーションの追加
void SpriteAnimationData::addAnimation( const std::string& fileName, const std::string& animationName, const cocos2d::Size& frameSize, int frameCount )
{
	Animation*		animation			{ Animation::create() };
	SpriteFrame*	frame				{ SpriteFrame::create( fileName, Rect::ZERO ) };
	const Size&		textureSize			{ frame->getTexture()->getContentSize() };
	int				currentFrameCount	{ 0 };
	
	const int frameWidth	= textureSize.width		/ frameSize.width;
	const int frameHeight	= textureSize.height	/ frameSize.height;
	
	const auto addFrame = [ & ]( int y )
	{
		for ( int x = 0; x < frameWidth; ++x )
		{
			if ( currentFrameCount == frameCount )
			{
				return false;
			}
			
			Rect rect { frameSize.width * x, frameSize.height * y, frameSize.width, frameSize.height };
			animation->setRestoreOriginalFrame( true );
			animation->addSpriteFrame( SpriteFrame::create( fileName, rect ) );
			++currentFrameCount;
		}
		
		return true;
	};
	
	for ( int y = 0; y < frameHeight; ++y )
	{
		if ( !addFrame( y ) )
		{
			break;
		}
	}
	
	mAnimationCache->addAnimation( animation, animationName );
}

// アニメイトの生成
Animate* SpriteAnimationData::createAnimate( const std::string& animationName, float frameSwitchSpeed )
{
	Animation* animation { mAnimationCache->getAnimation( animationName ) };
	animation->setDelayPerUnit( frameSwitchSpeed );
	
	return Animate::create( animation );
}