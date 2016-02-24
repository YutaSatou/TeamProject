#include "PlayerMudAction.h"
#include "../../Data/ObjectData.h"
#include "../Player.h"
#include "PlayerActionMediator.h"
#include "Utility/Audio/ADX2Player.h"

using namespace cocos2d;

// コンストラクタ
PlayerMudAction::PlayerMudAction( PlayerActionMediator& mediator, Player* owner, ObjectDataPtr objectData )
	: PlayerActionBase( mediator, owner, objectData )
{
	
}

// アクションの実行
void PlayerMudAction::execute( Node* contactNode, LiquidFunFixture* fixture )
{
	// SEを再生する。
	ADX2Player::getInstance().play( CRI_HUNGRYSLIMESHEET_SE_GIMMICK_MUD );
	
	// 泥の色を定義する。
	const ColorRYB mudColor { 0.600, 0.600, 0.00 };
	
	// 泥の色を適応して、同期する。
	mObjectData->backupColor.push( mObjectData->blendColor );
	mObjectData->blendColor		= mudColor;
	mObjectData->textureColor	= ColorRYB::convertToRGB( mudColor );
	mOwner->syncColor();
	
	// 色の合成が終了したので、空のアクションに変更する。
	mMediator.switchAction( PlayerActionMediator::ActionTag::NONE );
}