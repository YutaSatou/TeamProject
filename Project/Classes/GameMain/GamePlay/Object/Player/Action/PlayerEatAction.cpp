#include "PlayerEatAction.h"
#include "../../Data/ObjectData.h"
#include "../Player.h"
#include "PlayerActionMediator.h"
#include "../../Color/ColorMixer.h"

using namespace cocos2d;

// コンストラクタ
PlayerEatAction::PlayerEatAction( PlayerActionMediator& mediator, Player* owner, ObjectDataPtr objectData )
	: PlayerActionBase( mediator, owner, objectData )
	, mColorMixer( std::make_shared< ColorMixer >() )
{
	
}

// アクションの実行
void PlayerEatAction::execute( Node* contactNode, LiquidFunFixture* fixture )
{
	// プレイヤと衝突したノードの色を合成する。
	const ColorCMY& color { mColorMixer->blend( mOwner, contactNode ) };
	
	// 色情報を更新し、同期する。
	mObjectData->backupColor	= mObjectData->blendColor;
	mObjectData->blendColor		= color;
	mObjectData->textureColor	= ColorCMY::convertToRGB( color );
	mOwner->syncColor();
}