#ifndef _PLAYER_NONE_ACTION_H_
#define _PLAYER_NONE_ACTION_H_

#include "PlayerActionBase.h"

/*------------------------------------------------------------*/
//	@class		：	PlayerNoneAction
//	@brief		：	空のアクション
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class PlayerNoneAction : public PlayerActionBase
{
	
public:
	
	/**
	 *	@brief	コンストラクタ
	 *	@param	mediator	アクション制御仲介者
	 */
	PlayerNoneAction( PlayerActionMediator& mediator );
	
	/**
	 *	@brief	デストラクタ
	 */
	~PlayerNoneAction() = default;
	
	/**
	 *	@brief	アクションの実行
	 *	@param	contactNode	接触したノード
	 *	@param	fixture		接触したフィクスチャ
	 */
	virtual void execute( cocos2d::Node* contactNode, LiquidFunFixture* fixture ) override;
};

#endif