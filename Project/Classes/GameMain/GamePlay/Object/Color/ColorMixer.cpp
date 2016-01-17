#include "ColorMixer.h"
#include "cocos2d.h"
#include "ColorHelper.h"

using namespace cocos2d;

namespace
{
	const float COLOR_MAX { 255.0f };	//=> 色の最大値
}

// コンストラクタ
ColorMixer::ColorMixer()
	: mColorHelper( std::make_shared< ColorHelper >() )
{
	
}

// 色の合成
ColorCMY ColorMixer::blend( Node* blendBaseNode, Node* blendNode, float blendRate ) const
{
	const ColorCMY&	dst	{ mColorHelper->getBlendColor( blendBaseNode, blendNode ) };
	const ColorCMY&	src	{ mColorHelper->getBlendColor( blendNode, blendBaseNode ) };
	
	if ( dst == src )
	{
		return dst;
	}
	
	return colorBlend( src, dst, blendRate );
}

// 色の合成
ColorCMY ColorMixer::colorBlend( const ColorCMY& src, const ColorCMY& dst, float blendRate ) const
{
	float	c	{ std::min( dst.c * 1.0f + src.c * blendRate, COLOR_MAX ) };
	float	m	{ std::min( dst.m * 1.0f + src.m * blendRate, COLOR_MAX ) };
	float	y	{ std::min( dst.y * 1.0f + src.y * blendRate, COLOR_MAX ) };
	
	// std::roundと書きたいが、std::to_stringと同じで、NDKが対応してない？
	c	= round( c );
	m	= round( m );
	y	= round( y );
	
	return ColorCMY( c, m, y );
}