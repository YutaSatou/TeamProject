#include "ColorStack.h"

// 末尾への追加
void ColorStack::push( const ColorCMY& color )
{
	mStack.emplace( color.c, color.m, color.y );
}

// 末尾の取得
ColorCMY ColorStack::pop( bool isDelete )
{
	if ( mStack.empty() )
	{
		return ColorCMY::WHITE;
	}
	
	ColorCMY c { mStack.top() };
	
	if ( isDelete )
	{
		mStack.pop();
	}
	
	return c;
}