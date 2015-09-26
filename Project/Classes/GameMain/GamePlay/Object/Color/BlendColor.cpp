#include "BlendColor.h"

// コンストラクタ
BlendColor::BlendColor( BlendColorType _type )
	: type( _type )
{
	
}

// インスタンスの生成
BlendColor* BlendColor::create( BlendColorType _type )
{
	BlendColor* inst = new BlendColor( _type );
	inst->autorelease();
	return inst;
}