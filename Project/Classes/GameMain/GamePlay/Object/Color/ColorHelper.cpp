#include "ColorHelper.h"

using namespace cocos2d;

// 合成色の取得
Color3B ColorHelper::getBlendColor( Node* node, Node* contactNode ) const
{
	// ユーザオブジェクトから合成色を抽出する。
	const BlendColor* blendColor		= extractBlendColor( node );
	const BlendColor* contactBlendColor	= extractBlendColor( contactNode );
	
	if ( !contactBlendColor )
	{
		// 両方のノードに合成色が設定されていない場合は即死する。
		assert( blendColor && "両方のオブジェクトで合成色が設定されていません。" );
		
		// 接触したノードに合成色が設定されていない場合は、ノードの合成色を使用する。
		contactBlendColor = blendColor;
	}
	
	// 合成色を返却する。
	return contactBlendColor->color;
}

// 合成色の抽出
BlendColor* ColorHelper::extractBlendColor( Node* node ) const
{
	return static_cast< BlendColor* >( node->getUserObject() );
}