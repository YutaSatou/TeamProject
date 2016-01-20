#ifndef _PLAYER_GOAL_ACTION_H_
#define _PLAYER_GOAL_ACTION_H_

#include "PlayerActionBase.h"

/*------------------------------------------------------------*/
//	@class		：	PlayerGoalAction
//	@brief		：	ゴールに辿り着いた時のアクション
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class PlayerGoalAction : public PlayerActionBase
{
	
public:
	
	/**
	 *	@brief	コンストラクタ
	 *	@param	mediator	アクション制御仲介者
	 *	@param	owner		アクションを実行するオーナ
	 *	@param	objectData	オブジェクトデータ
	 */
	PlayerGoalAction( PlayerActionMediator& mediator, Player* owner, ObjectDataPtr objectData );
	
	/**
	 *	@brief	デストラクタ
	 */
	~PlayerGoalAction() = default;
	
	/**
	 *	@brief	アクションの実行
	 *	@param	contactNode	接触したノード
	 *	@param	fixture		接触したフィクスチャ
	 */
	virtual void execute( cocos2d::Node* contactNode, LiquidFunFixture* fixture ) override;
};

#endif