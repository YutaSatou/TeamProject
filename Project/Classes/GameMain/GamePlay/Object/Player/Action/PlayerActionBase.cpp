#include "PlayerActionBase.h"
#include "../../../LiquidFun/LiquidFunUserAPI.h"
#include "../../Data/ObjectData.h"
#include "../Player.h"
#include "PlayerActionMediator.h"

// コンストラクタ
PlayerActionBase::PlayerActionBase( PlayerActionMediator& mediator )
	: PlayerActionBase( mediator, nullptr, nullptr )
{
	
}

// コンストラクタ
PlayerActionBase::PlayerActionBase( PlayerActionMediator& mediator, Player* owner, ObjectDataPtr objectData )
	: mMediator( mediator )
	, mOwner( owner )
	, mObjectData( objectData )
{
	
}

// 更新
void PlayerActionBase::update( float deltaTime )
{
	
}