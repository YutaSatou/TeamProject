#include "ColorConverter.h"
#include "ColorRYB.h"
#include <limits>

using namespace cocos2d;

// コンストラクタ
ColorConverter::ColorConverter()
	: mColorCube()
{
	initColorCube();
}

// 色の三原色（絵の具）から光の三原色への変換
Color3B ColorConverter::rybToRGB( const ColorRYB& colorRYB ) const
{
	static const double UC_MAX { std::numeric_limits< std::uint8_t >::max() };
	
	double	r	{ getColor( colorRYB, []( const ColorRGB& color ) { return std::get< 0 >( color ); } ) * UC_MAX };
	double	g	{ getColor( colorRYB, []( const ColorRGB& color ) { return std::get< 1 >( color ); } ) * UC_MAX };
	double	b	{ getColor( colorRYB, []( const ColorRGB& color ) { return std::get< 2 >( color ); } ) * UC_MAX };
	
	r	= std::min( r, UC_MAX );
	g	= std::min( g, UC_MAX );
	b	= std::min( b, UC_MAX );
	
	return Color3B( r, g, b );
}

// カラーキューブの初期化
void ColorConverter::initColorCube()
{
	mColorCube[ 0 ]	= std::make_tuple( 1.000, 1.000, 1.000 );
	mColorCube[ 1 ]	= std::make_tuple( 1.000, 1.000, 0.000 );
	mColorCube[ 2 ]	= std::make_tuple( 1.000, 0.000, 0.000 );
	mColorCube[ 3 ]	= std::make_tuple( 1.000, 0.500, 0.000 );
	mColorCube[ 4 ]	= std::make_tuple( 0.008, 0.278, 0.996 );
	mColorCube[ 5 ]	= std::make_tuple( 0.000, 0.660, 0.200 );
	mColorCube[ 6 ]	= std::make_tuple( 0.500, 0.000, 0.500 );
	mColorCube[ 7 ]	= std::make_tuple( 0.000, 0.000, 0.000 );
}

// 色の取得
double ColorConverter::getColor( const ColorRYB& color, const ColorSelectFunc& func ) const
{
	static const auto cubicInt = []( double t, double valueA, double valueB )
	{
		double weight { t * t * ( 3.0 - 2.0 * t ) };
		
		return valueA + weight * ( valueB - valueA );
	};
	
	double	tempA	{ cubicInt( color.b, func( mColorCube[ 0 ] ), func( mColorCube[ 4 ] ) ) };
	double	tempB	{ cubicInt( color.b, func( mColorCube[ 1 ] ), func( mColorCube[ 5 ] ) ) };
	double	tempC	{ cubicInt( color.b, func( mColorCube[ 2 ] ), func( mColorCube[ 6 ] ) ) };
	double	tempD	{ cubicInt( color.b, func( mColorCube[ 3 ] ), func( mColorCube[ 7 ] ) ) };
	double	valueA	{ cubicInt( color.y, tempA, tempB ) };
	double	valueB	{ cubicInt( color.y, tempC, tempD ) };
	
	return cubicInt( color.r, valueA, valueB );
}