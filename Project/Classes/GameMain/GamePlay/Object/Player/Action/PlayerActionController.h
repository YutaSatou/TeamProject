#ifndef _PLAYER_ACTION_CONTROLLER_H_
#define _PLAYER_ACTION_CONTROLLER_H_

#include "../../../LiquidFun/LiquidFunDefine.h"
#include "../../Data/ObjectDataDefine.h"
#include "PlayerActionMediator.h"
#include "Utility/Template/EnumHash.h"
#include <functional>
#include <unordered_map>

namespace cocos2d
{
	class Node;
}

class Player;
class PlayerActionBase;

/*------------------------------------------------------------*/
//	@class		：	PlayerActionController
//	@brief		：	アクション制御者
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class PlayerActionController : public PlayerActionMediator
{
	
private:
	
	using PlayerActionPtr	= std::shared_ptr< PlayerActionBase >;
	using ActionContainer	= std::unordered_map< ActionTag, PlayerActionPtr, EnumHash >;
	
public:
	
	/**
	 *	@brief	コンストラクタ
	 */
	PlayerActionController();
	
	/**
	 *	@brief	デストラクタ
	 */
	~PlayerActionController() = default;
	
	/**
	 *	@brief	アクションの変更
	 *	@param	tag	変更するアクションのタグ
	 */
	virtual void switchAction( const ActionTag& tag ) override;
	
	/**
	 *	@brief	アクションの実行
	 *	@param	contactNode	接触したノード
	 *	@param	fixture		接触したフィクスチャ
	 */
	void execute( cocos2d::Node* contactNode, LiquidFunFixture* fixture );
	
	/**
	 *	@brief	初期化
	 *	@param	owner		アクションを実行するオーナ
	 *	@param	objectData	オブジェクトデータ
	 */
	void init( Player* owner, ObjectDataPtr objectData );
	
	/**
	 *	@param	更新
	 *	@param	deltaTime	デルタ時間
	 */
	void update( float deltaTime );
	
private:
	
	/**
	 *	@brief	アクションの追加
	 *	@param	tag			設定するタグ
	 *	@param	action		追加するアクション
	 */
	void add( const ActionTag& tag, PlayerActionPtr action );
	
private:
	
	ActionContainer	mActionContainer;	//=> アクションのコンテナ
	PlayerActionPtr	mCurrentAction;		//=> 現在実行中のアクション
};

#endif