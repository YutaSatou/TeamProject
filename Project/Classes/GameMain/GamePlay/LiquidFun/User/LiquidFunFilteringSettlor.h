#ifndef _LIQUID_FUN_FILTERING_SETTLOR_H_
#define _LIQUID_FUN_FILTERING_SETTLOR_H_

#include "../LiquidFunDefine.h"

struct LiquidFunContactFilter;

/*------------------------------------------------------------*/
//	@class		：	LiquidFunFilteringSettlor
//	@brief		：	LiquidFunのフィルタリング設定者
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class LiquidFunFilteringSettlor
{
	
public:
	
	/**
	 *	@brief	コンストラクタ
	 */
	LiquidFunFilteringSettlor() = delete;
	
	/**
	 *	@brief	デストラクタ
	 */
	~LiquidFunFilteringSettlor() = delete;
	
	/**
	 *	@brief	フィルタの設定
	 *	@param	fixture			フィルタを設定するフィクスチャ
	 *	@param	contactFilter	設定するコンタクトフィルタ
	 */
	static void setupFilter( LiquidFunFixture* fixture, const LiquidFunContactFilter& contactFilter );
	
	/**
	 *	@brief	フィルタの設定
	 *	@param	body			フィルタを設定するボディ
	 *	@param	contactFilter	設定するコンタクトフィルタ
	 */
	static void setupFilter( LiquidFunBody* body, const LiquidFunContactFilter& contactFilter );
};

#endif