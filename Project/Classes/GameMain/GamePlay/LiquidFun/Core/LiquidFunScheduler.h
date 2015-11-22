#ifndef _LIQUID_FUN_SCHEDULER_H_
#define _LIQUID_FUN_SCHEDULER_H_

#include "Utility/Template/SmartPtr.h"
#include "LiquidFunDefine.h"

/*------------------------------------------------------------*/
//	@class		：	LiquidFunScheduler
//	@brief		：	LiquidFunの定期実行者
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class LiquidFunScheduler
{
	
public:
	
	/**
	 *	@brief	コンストラクタ
	 *	@param	world	ワールド
	 */
	LiquidFunScheduler( SharedPtr< LiquidFunWorld > world );
	
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
	
	SharedPtr< LiquidFunWorld > mWorld;	//=> ワールド
};

#endif