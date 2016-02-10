#include "PlayerShootAction.h"
#include "../../Data/ObjectData.h"
#include "../Player.h"
#include "PlayerActionMediator.h"
#include "../../Enemy/Cannon.h"
#include "Utility/Audio/ADX2Player.h"

using namespace cocos2d;

// コンストラクタ
PlayerShootAction::PlayerShootAction( PlayerActionMediator& mediator, Player* owner, ObjectDataPtr objectData )
	: PlayerActionBase( mediator, owner, objectData )
{
	
}

// アクションの実行
void PlayerShootAction::execute( Node* contactNode, LiquidFunFixture* fixture )
{
	// やりたくないけど。
	Cannon* cannon { dynamic_cast< Cannon* >( contactNode ) };
	
	if ( !cannon )
	{
		return;
	}
	
	// 発射の準備をする。
	ready( cannon->getPosition() );
	
	// 発射時に呼び出されるコールバック関数を登録する。
	cannon->registerShootListener( CC_CALLBACK_1( PlayerShootAction::onShoot, this ) );
}

// 発射の準備
void PlayerShootAction::ready( const Vec2& shootPosition )
{
	// 発射位置を設定する。
	mObjectData->position = shootPosition;
	
	// 不可視状態にして、液体挙動を無効化する。
	mOwner->setVisible( false );
	mOwner->disableLiquidBehavior();
}

// 発射時に呼び出されるコールバック関数
void PlayerShootAction::onShoot( const Vec2& shootPower )
{
	// SEを再生する。
	ADX2Player::getInstance().play( CRI_HUNGRYSLIMESHEET_SE_GIMMICK_CANNON );
	
	// 座標の同期、不可視状態の解除、液体挙動の有効化を行う。
	mOwner->syncPosition();
	mOwner->setVisible( true );
	mOwner->enableLiquidBehavior();
	
	// 大砲発射の力を加える。
	mOwner->applyLinearImpulse( shootPower );
	
	// 力を加え終わったら、空のアクションに変更する。
	mMediator.switchAction( PlayerActionMediator::ActionTag::NONE );
}