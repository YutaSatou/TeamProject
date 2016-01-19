#include "PlayerEatAction.h"
#include "../../Data/ObjectData.h"
#include "../Player.h"
#include "PlayerActionMediator.h"
#include "../../Color/ColorMixer.h"
#include "Utility/Audio/ADX2Player.h"

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
	ADX2Player::getInstance().play( CRI_HUNGRYSLIMESHEET_SE_PLAYER_EAT );
	
	// 色情報を更新し、同期する。
	mObjectData->backupColor	= mObjectData->blendColor;
	mObjectData->blendColor		= color;
	mObjectData->textureColor	= ColorCMY::convertToRGB( color );
	mOwner->syncColor();
	
	// 色の合成が終了したので、空のアクションに変更する。
	mMediator.switchAction( PlayerActionMediator::ActionTag::NONE );
}