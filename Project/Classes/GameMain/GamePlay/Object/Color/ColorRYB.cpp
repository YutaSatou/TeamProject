#include "ColorRYB.h"

const ColorRYB ColorRYB::WHITE(		0.00, 0.00, 0.00 );
const ColorRYB ColorRYB::RED(		1.00, 0.00, 0.00 );
const ColorRYB ColorRYB::YELLOW(	0.00, 1.00, 0.00 );
const ColorRYB ColorRYB::BLUE(		0.00, 0.00, 1.00 );
const ColorRYB ColorRYB::ORANGE(	1.00, 1.00, 0.00 );
const ColorRYB ColorRYB::GREEN(		0.00, 1.00, 1.00 );
const ColorRYB ColorRYB::PURPLE(	1.00, 0.00, 1.00 );
const ColorRYB ColorRYB::BLACK(		1.00, 1.00, 1.00 );

// コンストラクタ
ColorRYB::ColorRYB()
	: r( 0.00 )
	, y( 0.00 )
	, b( 0.00 )
{
	
}

// コンストラクタ
ColorRYB::ColorRYB( double _r, double _y, double _b )
	: r( _r )
	, y( _y )
	, b( _b )
{
	
}

// コピーコンストラクタ
ColorRYB::ColorRYB( const ColorRYB& copy )
	: r( copy.r )
	, y( copy.y )
	, b( copy.b )
{
	
}

// 等価演算子
bool ColorRYB::operator==( const ColorRYB& color ) const
{
	return ( r == color.r && y == color.y && b == color.b );
}

// 非等価演算子
bool ColorRYB::operator!=( const ColorRYB& color ) const
{
	return !( ( *this ) == color );
}