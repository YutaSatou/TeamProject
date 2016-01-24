#include "PlayerGoalAction.h"
#include "../../Data/ObjectData.h"
#include "../Player.h"
#include "PlayerActionMediator.h"
#include "Utility/Audio/ADX2Player.h"

using namespace cocos2d;

// コンストラクタ
PlayerGoalAction::PlayerGoalAction( PlayerActionMediator& mediator, Player* owner, ObjectDataPtr objectData )
	: PlayerActionBase( mediator, owner, objectData )
{
	
}

// アクションの実行
void PlayerGoalAction::execute( Node* contactNode, LiquidFunFixture* fixture )
{
	// SEを再生する。
	ADX2Player::getInstance().play( CRI_HUNGRYSLIMESHEET_SE_GAMECLEAR );
	
	// スケジュール登録を解除する。
	mOwner->unscheduleUpdate();
}