#include "PlayerActionController.h"
#include "cocos2d.h"
#include "../../Data/ObjectData.h"
#include "Player.h"
#include "PlayerNoneAction.h"
#include "PlayerEatAction.h"

using namespace cocos2d;

namespace
{
	PlayerActionMediator::ActionTag getActionTag( LiquidFunFixture* fixture )
	{
		return Contact::toEnum( fixture->GetFilterData().categoryBits );
	}
}

// コンストラクタ
PlayerActionController::PlayerActionController()
	: mActionContainer()
	, mCurrentAction( std::make_shared< PlayerNoneAction >( *this ) )
{
	
}

// アクションの変更
void PlayerActionController::switchAction( const ActionTag& tag )
{
	if ( mActionContainer.find( tag ) == mActionContainer.end() )
	{
		CCLOG( "登録されていないアクションです。" );
		return;
	}
	
	mCurrentAction = mActionContainer.at( tag );
}

// アクションの実行
void PlayerActionController::execute( Node* contactNode, LiquidFunFixture* fixture )
{
	const ActionTag& tag { getActionTag( fixture ) };
	
	switchAction( tag );
	
	mCurrentAction->execute( contactNode, fixture );
}

// 初期化
void PlayerActionController::init( Player* owner, ObjectDataPtr objectData )
{
	add( ActionTag::NONE,	std::make_shared< PlayerNoneAction >( *this ) );
	add( ActionTag::SLIME,	std::make_shared< PlayerEatAction >( *this, owner, objectData ) );
}

// 更新
void PlayerActionController::update( float deltaTime )
{
	mCurrentAction->update( deltaTime );
}

// アクションの追加
void PlayerActionController::add( const ActionTag& tag, PlayerActionPtr action )
{
	mActionContainer[ tag ] = action;
}