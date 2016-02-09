#ifndef _ENEMY_DEAD_ACTION_H_
#define _ENEMY_DEAD_ACTION_H_

namespace cocos2d
{
	class ActionInterval;
}

/*------------------------------------------------------------*/
//	@class		：	EnemyDeadAction
//	@brief		：	敵死亡時のアクション
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class EnemyDeadAction
{
	
protected:
	
	/**
	 *	@brief	コンストラクタ
	 */
	EnemyDeadAction() = default;
	
	/**
	 *	@brief	デストラクタ
	 */
	~EnemyDeadAction() = default;
	
public:
	
	/**
	 *	@brief	インスタンスの生成
	 *	@param	deadTime		死亡するまでの時間
	 *	@param	blinkCount		点滅する回数
	 *	@return	ActionInterval	インスタンス
	 */
	static cocos2d::ActionInterval* create( float deadTime, int blinkCount );
};

#endif