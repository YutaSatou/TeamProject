#include "PlayerWetAction.h"
#include "../../Data/ObjectData.h"
#include "../Player.h"
#include "PlayerActionMediator.h"
#include "Utility/Audio/ADX2Player.h"

using namespace cocos2d;

// コンストラクタ
PlayerWetAction::PlayerWetAction( PlayerActionMediator& mediator, Player* owner, ObjectDataPtr objectData )
	: PlayerActionBase( mediator, owner, objectData )
{
	
}

// アクションの実行
void PlayerWetAction::execute( Node* contactNode, LiquidFunFixture* fixture )
{
	// SEを再生する。
	ADX2Player::getInstance().play( CRI_HUNGRYSLIMESHEET_SE_GIMMICK_SHOWER );
	
	// バックアップから色情報を復元し、同期する。
	mObjectData->blendColor		= mObjectData->backupColor.pop();
	mObjectData->textureColor	= ColorRYB::convertToRGB( mObjectData->blendColor );
	mOwner->syncColor();
	
	// 色の復元が終了したので、空のアクションに変更する。
	mMediator.switchAction( PlayerActionMediator::ActionTag::NONE );
}