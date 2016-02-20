#include "ColorStack.h"

// 末尾への追加
void ColorStack::push( const ColorRYB& color )
{
	mStack.emplace( color.r, color.y, color.b );
}

// 末尾の取得
ColorRYB ColorStack::pop( bool isDelete )
{
	if ( mStack.empty() )
	{
		return ColorRYB::WHITE;
	}
	
	ColorRYB c { mStack.top() };
	
	if ( isDelete )
	{
		mStack.pop();
	}
	
	return c;
}