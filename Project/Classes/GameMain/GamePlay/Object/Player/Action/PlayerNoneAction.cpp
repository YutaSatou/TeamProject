#include "PlayerNoneAction.h"
#include "PlayerActionMediator.h"

using namespace cocos2d;

// コンストラクタ
PlayerNoneAction::PlayerNoneAction( PlayerActionMediator& mediator )
	: PlayerActionBase( mediator )
{
	
}

// アクションの実行
void PlayerNoneAction::execute( Node* contactNode, LiquidFunFixture* fixture )
{
	
}