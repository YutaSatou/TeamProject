#ifndef _LIQUID_FUN_BODY_DELETER_H_
#define _LIQUID_FUN_BODY_DELETER_H_

#include "cocos2d.h"
#include "Utility/Template/Deleter.h"
#include "../../LiquidFun/LiquidFunDefine.h"

/*------------------------------------------------------------*/
//	@class		：	LiquidFunBodyDeleter
//	@brief		：	ボディデストラクトラッパ
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class LiquidFunBodyDeleter : public cocos2d::Node, public Deleter< LiquidFunBody >
{
	
protected:
	
	/**
	 *	@brief	コンストラクタ
	 */
	LiquidFunBodyDeleter();
	
	/**
	 *	@brief	デストラクタ
	 */
	~LiquidFunBodyDeleter() = default;
	
public:
	
	/**
	 *	@brief	インスタンスの生成
	 *	@param	body					削除するボディ
	 *	@return	LiquidFunBodyDeleter	インスタンス
	 */
	static LiquidFunBodyDeleter* create( LiquidFunBody* body );
};

#endif