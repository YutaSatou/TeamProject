#ifndef _CONTACT_CALLBACK_H_
#define _CONTACT_CALLBACK_H_

#include "cocos2d.h"
#include "ContactCategory.h"
#include "../../LiquidFun/LiquidFunUserAPI.h"

/*------------------------------------------------------------*/
//	@struct		：	ContactCallback
//	@brief		：	接触用コールバック
//	@author		：	利川聖太
/*------------------------------------------------------------*/
struct ContactCallback
{
	using ContactRigidFunc	= std::function< void( cocos2d::Node*, LiquidFunBody* ) >;
	using ContactLiquidFunc	= std::function< void( cocos2d::Node*, LiquidFunBody*, LiquidFunParticle*, int ) >;
	
	ContactRigidFunc	onContactRigidBegin;	//=> 剛体と剛体の接触時に呼ばれるコールバック関数
	ContactRigidFunc	onContactRigidPreSolve;	//=> 剛体と剛体の接触中に呼ばれるコールバック関数
	ContactRigidFunc	onContactRigidEnd;		//=> 剛体と剛体の離脱時に呼ばれるコールバック関数
	ContactLiquidFunc	onContactLiquidBegin;	//=> 剛体と液体の接触時に呼ばれるコールバック関数
	ContactLiquidFunc	onContactLiquidEnd;		//=> 剛体と液体の離脱時に呼ばれるコールバック関数
	unsigned short		contactBitmask;			//=> 接触するオブジェクトのビットマスク
	
	/**
	 *	@brief	コンストラクタ
	 */
	ContactCallback()
		: onContactRigidBegin(		[]( cocos2d::Node*, LiquidFunBody* ) { } )
		, onContactRigidPreSolve(	[]( cocos2d::Node*, LiquidFunBody* ) { } )
		, onContactRigidEnd(		[]( cocos2d::Node*, LiquidFunBody* ) { } )
		, onContactLiquidBegin(		[]( cocos2d::Node*, LiquidFunBody*, LiquidFunParticle*, int ) { } )
		, onContactLiquidEnd(		[]( cocos2d::Node*, LiquidFunBody*, LiquidFunParticle*, int ) { } )
		, contactBitmask( Contact::toUShort( Contact::Category::NONE ) )
	{
		
	}
};

#endif