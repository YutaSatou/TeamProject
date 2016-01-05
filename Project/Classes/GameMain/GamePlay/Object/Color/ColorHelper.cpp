#include "ColorHelper.h"
#include "cocos2d.h"

using namespace cocos2d;

// 合成色の取得
ColorCMY ColorHelper::getBlendColor( Node* node, Node* contactNode ) const
{
	// ユーザデータから合成色を抽出する。
	ColorCMY* blendColor		{ extractBlendColor( node ) };
	ColorCMY* contactBlendColor	{ extractBlendColor( contactNode ) };
	
	if ( !blendColor )
	{
		// 両方のノードに合成色が設定されていない場合は即死する。
		assert( contactBlendColor && "両方のオブジェクトで、合成色が設定されていません。" );
		
		// ノードに合成色が設定されていない場合は、接触したノードの合成色を使用する。
		return ( *contactBlendColor );
	}
	
	// 合成色を返却する。
	return ( *blendColor );
}

// 合成色の抽出
ColorCMY* ColorHelper::extractBlendColor( Node* node ) const
{
	return static_cast< ColorCMY* >( node->getUserData() );
}