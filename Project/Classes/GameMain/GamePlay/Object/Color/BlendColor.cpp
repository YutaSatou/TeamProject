#include "BlendColor.h"

using namespace cocos2d;

// コンストラクタ
BlendColor::BlendColor( const Color3B& _color )
	: color( _color )
{
	
}

// インスタンスの生成
BlendColor* BlendColor::create( const Color3B& _color )
{
	BlendColor* inst = new BlendColor( _color );
	inst->autorelease();
	return inst;
}