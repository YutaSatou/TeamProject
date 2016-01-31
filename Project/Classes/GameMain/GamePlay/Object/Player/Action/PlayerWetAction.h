#ifndef _PLAYER_WET_ACTION_H_
#define _PLAYER_WET_ACTION_H_

#include "PlayerActionBase.h"

/*------------------------------------------------------------*/
//	@class		：	PlayerWetAction
//	@brief		：	濡れた時のアクション
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class PlayerWetAction : public PlayerActionBase
{
	
public:
	
	/**
	 *	@brief	コンストラクタ
	 *	@param	mediator	アクション制御仲介者
	 *	@param	owner		アクションを実行するオーナ
	 *	@param	objectData	オブジェクトデータ
	 */
	PlayerEatAction( PlayerActionMediator& mediator, Player* owner, ObjectDataPtr objectData );
	
	/**
	 *	@brief	デストラクタ
	 */
	~PlayerEatAction() = default;
	
	/**
	 *	@brief	アクションの実行
	 *	@param	contactNode	接触したノード
	 *	@param	fixture		接触したフィクスチャ
	 */
	virtual void execute( cocos2d::Node* contactNode, LiquidFunFixture* fixture ) override;
};

#endif