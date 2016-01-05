#include "ColorMixer.h"
#include "cocos2d.h"
#include "ColorHelper.h"

using namespace cocos2d;

namespace
{
	const double COLOR_MAX { 255.0 };	//=> 色の最大値
}

// コンストラクタ
ColorMixer::ColorMixer()
	: mColorHelper( makeShared< ColorHelper >() )
{
	
}

// 色の合成
ColorCMY ColorMixer::blend( Node* blendBaseNode, Node* blendNode, double blendRate ) const
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
ColorCMY ColorMixer::colorBlend( const ColorCMY& src, const ColorCMY& dst, double blendRate ) const
{
	double	c	= std::min( dst.c * 1.0 + src.c * blendRate, COLOR_MAX );
	double	m	= std::min( dst.m * 1.0 + src.m * blendRate, COLOR_MAX );
	double	y	= std::min( dst.y * 1.0 + src.y * blendRate, COLOR_MAX );
	
	c	= std::round( c );
	m	= std::round( m );
	y	= std::round( y );
	
	return ColorCMY( c, m, y );
}