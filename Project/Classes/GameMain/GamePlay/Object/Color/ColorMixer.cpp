#include "ColorMixer.h"
#include "cocos2d.h"
#include "ColorHelper.h"

using namespace cocos2d;

namespace
{
	const float SATURATION_MIN	=   0.1f;	//=> 彩度の最低値
	const float COLOR_MAX		= 255.0f;	//=> 色の最大値
}

// コンストラクタ
ColorMixer::ColorMixer()
	: mColorHelper( makeShared< ColorHelper >() )
{
	
}

// 色の合成
ColorCMY ColorMixer::blend( Node* node, Node* contactNode, float saturation ) const
{
	ColorCMY src = mColorHelper->getBlendColor( node, contactNode );
	ColorCMY dst = mColorHelper->getBlendColor( contactNode, node );
	
	if ( src == ColorCMY::WHITE )
	{
		// ゲームの仕様上、白は透明として扱う。
		return dst;
	}
	
	if ( src == dst )
	{
		return src;
	}
	
	return colorBlend( src, dst, saturation );
}

// 色の合成
ColorCMY ColorMixer::colorBlend( const ColorCMY& src, const ColorCMY& dst, float saturation ) const
{
	static const auto alphaBlend = []( float src, float dst )
	{
		return ( src * 0.5f ) + ( dst * 0.5f );
	};
	
	// 色を合成する。
	float c = alphaBlend( src.c, dst.c );
	float m = alphaBlend( src.m, dst.m );
	float y = alphaBlend( src.y, dst.y );
	
	// 彩度を補正する。
	revisedSaturation( &c, saturation );
	revisedSaturation( &m, saturation );
	revisedSaturation( &y, saturation );
	
	return ColorCMY( c, m, y );
}

// 彩度の補正
void ColorMixer::revisedSaturation( float* colorElement, float saturation ) const
{
	if ( *colorElement >= COLOR_MAX )
	{
		return;
	}
	
	// CMYからRGBに変換される前に彩度を調整する。
	saturation = std::max( ( 2.0f - saturation ), SATURATION_MIN );
	
	// 彩度を適応する。
	*colorElement = std::max( ( *colorElement ) * saturation, 0.0f );
}