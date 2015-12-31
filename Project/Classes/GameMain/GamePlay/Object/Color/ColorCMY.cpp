#include "ColorCMY.h"

using namespace cocos2d;

const ColorCMY ColorCMY::WHITE(		  0,   0,   0 );
const ColorCMY ColorCMY::BLACK(		255, 255, 255 );
const ColorCMY ColorCMY::CYAN(		255,   0,   0 );
const ColorCMY ColorCMY::MAGENTA(	  0, 255,   0 );
const ColorCMY ColorCMY::YELLOW(	  0,   0, 255 );
const ColorCMY ColorCMY::RED(		  0, 255, 255 );
const ColorCMY ColorCMY::GREEN(		255,   0, 255 );
const ColorCMY ColorCMY::BLUE(		255, 255,   0 );

// コンストラクタ
ColorCMY::ColorCMY()
	: c( 0 )
	, m( 0 )
	, y( 0 ) { }

// コンストラクタ
ColorCMY::ColorCMY( uint8_t _c, uint8_t _m, uint8_t _y )
	: c( _c )
	, m( _m )
	, y( _y ) { }

// コンストラクタ
ColorCMY::ColorCMY( const Color3B& colorRGB )
	: c( 0 )
	, m( 0 )
	, y( 0 )
{
	ColorCMY color { convertToCMY( colorRGB ) };
	
	c	= color.c;
	m	= color.m;
	y	= color.y;
}

// 色の三原色( CMY )から光の三原色( RGB )への変換
Color3B ColorCMY::convertToRGB( const ColorCMY& colorCMY )
{
	uint8_t r, g, b;
	std::tie( r, g, b ) = convertColor( colorCMY.c, colorCMY.m, colorCMY.y );
	return { r, g, b };
}

// 光の三原色( RGB )から色の三原色( CMY )への変換
ColorCMY ColorCMY::convertToCMY( const Color3B& colorRGB )
{
	uint8_t c, m, y;
	std::tie( c, m, y ) = convertColor( colorRGB.r, colorRGB.g, colorRGB.b );
	return { c, m, y };
}

// 等価演算子
bool ColorCMY::operator == ( const ColorCMY& colorCMY ) const
{
	return ( c == colorCMY.c && m == colorCMY.m && y == colorCMY.y );
}

// 等価演算子
bool ColorCMY::operator == ( const Color3B& colorRGB ) const
{
	ColorCMY color { convertToCMY( colorRGB ) };
	
	return ( c == color.c && m == color.m && y == color.y );
}

// 非等価演算子
bool ColorCMY::operator != ( const ColorCMY& colorCMY ) const
{
	return !( *this == colorCMY );
}

// 非等価演算子
bool ColorCMY::operator != ( const Color3B& colorRGB ) const
{
	ColorCMY color { convertToCMY( colorRGB ) };
	
	return !( *this == color );
}

// RGB⇔CMYの相互変換
ColorCMY::ColorTuple ColorCMY::convertColor( uint8_t element1, uint8_t element2, uint8_t element3 )
{
	return std::make_tuple( ( 255 - element1 ), ( 255 - element2 ), ( 255 - element3 ) );
}