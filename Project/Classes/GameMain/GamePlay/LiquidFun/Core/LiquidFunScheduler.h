#ifndef _LIQUID_FUN_SCHEDULER_H_
#define _LIQUID_FUN_SCHEDULER_H_

class b2World;

using LiquidFunWorld = b2World;

/*------------------------------------------------------------*/
//	@class		：	LiquidFunScheduler
//	@brief		：	LiquidFunの定期実行
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class LiquidFunScheduler
{
	
public:
	
	/**
	 *	@brief	コンストラクタ
	 *	@param	world	ワールド
	 */
	LiquidFunScheduler( LiquidFunWorld* world );
	
	/**
	 *	@brief	デストラクタ
	 */
	~LiquidFunScheduler() = default;
	
	/**
	 *	@brief	更新
	 */
	void update();
	
private:
	
	/**
	 *	@brief	物理エンジンの更新
	 */
	void updateBox2D();
	
	/**
	 *	@brief	ワールド内のノードの更新
	 */
	void updateWorldNode();
	
private:
	
	LiquidFunWorld* mWorld;	//=> ワールド
};

#endif