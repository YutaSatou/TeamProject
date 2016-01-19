#ifndef _PLAYER_EAT_ACTION_H_
#define _PLAYER_EAT_ACTION_H_

#include "PlayerActionBase.h"

class ColorMixer;

/*------------------------------------------------------------*/
//	@class		：	PlayerEatAction
//	@brief		：	敵を食べた時のアクション
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class PlayerEatAction : public PlayerActionBase
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
	
private:
	
	using ColorMixerPtr = std::shared_ptr< ColorMixer >;
	
	ColorMixerPtr mColorMixer;	//=> 色合成者
};

#endif