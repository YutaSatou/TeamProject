#ifndef _PLAYER_SHOOT_ACTION_H_
#define _PLAYER_SHOOT_ACTION_H_

#include "PlayerActionBase.h"

/*------------------------------------------------------------*/
//	@class		：	PlayerShootAction
//	@brief		：	大砲から発射された時のアクション
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class PlayerShootAction : public PlayerActionBase
{
	
public:
	
	/**
	 *	@brief	コンストラクタ
	 *	@param	mediator	アクション制御仲介者
	 *	@param	owner		アクションを実行するオーナ
	 *	@param	objectData	オブジェクトデータ
	 */
	PlayerShootAction( PlayerActionMediator& mediator, Player* owner, ObjectDataPtr objectData );
	
	/**
	 *	@brief	デストラクタ
	 */
	~PlayerShootAction() = default;
	
	/**
	 *	@brief	アクションの実行
	 *	@param	contactNode	接触したノード
	 *	@param	fixture		接触したフィクスチャ
	 */
	virtual void execute( cocos2d::Node* contactNode, LiquidFunFixture* fixture ) override;
	
private:
	
	/**
	 *	@brief	発射の準備
	 *	@param	shootPosition	発射を開始する座標
	 */
	void ready( const cocos2d::Vec2& shootPosition );
	
	/**
	 *	@brief	発射時に呼び出されるコールバック関数
	 *	@param	shootPower	発射する力
	 */
	void onShoot( const cocos2d::Vec2& shootPower );
};

#endif