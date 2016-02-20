#include "ColorMixer.h"
#include "cocos2d.h"
#include "ColorHelper.h"

using namespace cocos2d;

namespace
{
	const double COLOR_MAX { 1.0 };	//=> 色の最大値
}

// コンストラクタ
ColorMixer::ColorMixer()
	: mColorHelper( std::make_shared< ColorHelper >() )
{
	
}

// 色の合成
ColorRYB ColorMixer::blend( Node* blendBaseNode, Node* blendNode ) const
{
	const ColorRYB&	dst	{ mColorHelper->getBlendColor( blendBaseNode, blendNode ) };
	const ColorRYB&	src	{ mColorHelper->getBlendColor( blendNode, blendBaseNode ) };
	
	if ( dst == src )
	{
		return dst;
	}
	
	if ( dst == ColorRYB::WHITE )
	{
		return src;
	}
	
	return colorBlend( src, dst );
}

// 色の合成
ColorRYB ColorMixer::colorBlend( const ColorRYB& src, const ColorRYB& dst ) const
{
	double	r	{ std::min( dst.r + src.r, COLOR_MAX ) };
	double	y	{ std::min( dst.y + src.y, COLOR_MAX ) };
	double	b	{ std::min( dst.b + src.b, COLOR_MAX ) };
	
	return { r, y, b };
}