#ifndef _CONTACT_CALLBACK_H_
#define _CONTACT_CALLBACK_H_

#include "cocos2d.h"
#include "../../LiquidFun/LiquidFunUserAPI.h"

/*------------------------------------------------------------*/
//	@struct		：	ContactCallback
//	@brief		：	接触用コールバック
//	@author		：	利川聖太
/*------------------------------------------------------------*/
struct ContactCallback
{
	using CallbackFunction = std::function< void( cocos2d::Node*, LiquidFunBody* ) >;
	
	CallbackFunction	onContactBegin;		//=> 接触時に呼ばれるコールバック関数
	CallbackFunction	onContactPreSolve;	//=> 接触中に呼ばれるコールバック関数
	CallbackFunction	onContactEnd;		//=> 離脱時に呼ばれるコールバック関数
	
	/**
	 *	@brief	コンストラクタ
	 */
	ContactCallback()
		: onContactBegin(		[]( cocos2d::Node*, LiquidFunBody* ) { } )
		, onContactPreSolve(	[]( cocos2d::Node*, LiquidFunBody* ) { } )
		, onContactEnd(			[]( cocos2d::Node*, LiquidFunBody* ) { } )
	{
		// 空のラムダ式で初期化する。
	}
};

#endif