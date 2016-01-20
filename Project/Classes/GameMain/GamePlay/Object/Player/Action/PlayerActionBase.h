#ifndef _PLAYER_ACTION_BASE_H_
#define _PLAYER_ACTION_BASE_H_

#include "../../../LiquidFun/LiquidFunDefine.h"
#include "../../Data/ObjectDataDefine.h"

namespace cocos2d
{
	class Node;
}

class Player;
class PlayerActionMediator;

/*------------------------------------------------------------*/
//	@class		：	PlayerActionBase
//	@brief		：	アクションの基底
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class PlayerActionBase
{
	
protected:
	
	/**
	 *	@brief	コンストラクタ
	 *	@param	mediator	アクション制御仲介者
	 */
	PlayerActionBase( PlayerActionMediator& mediator );
	
	/**
	 *	@brief	コンストラクタ
	 *	@param	mediator	アクション制御仲介者
	 *	@param	owner		アクションを実行するオーナ
	 *	@param	objectData	オブジェクトデータ
	 */
	PlayerActionBase( PlayerActionMediator& mediator, Player* owner, ObjectDataPtr objectData );
	
	/**
	 *	@brief	デストラクタ
	 */
	virtual ~PlayerActionBase() = default;
	
public:
	
	/**
	 *	@brief	アクションの実行
	 *	@param	contactNode	接触したノード
	 *	@param	fixture		接触したフィクスチャ
	 */
	virtual void execute( cocos2d::Node* contactNode, LiquidFunFixture* fixture ) = 0;
	
	/**
	 *	@brief	更新
	 *	@param	deltaTime	デルタ時間
	 */
	virtual void update( float deltaTime );
	
protected:
	
	PlayerActionMediator&	mMediator;		// アクション制御仲介者
	Player*					mOwner;			// アクションを実行するオーナ
	ObjectDataPtr			mObjectData;	// オブジェクトデータ
};

#endif