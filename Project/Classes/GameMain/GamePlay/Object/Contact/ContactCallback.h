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
	using Ptr				= std::shared_ptr< ContactCallback >;
	using ContactRigidFunc	= std::function< void( cocos2d::Node*, LiquidFunFixture* ) >;
	using ContactLiquidFunc	= std::function< void( cocos2d::Node*, LiquidFunParticle*, int ) >;
	
	ContactRigidFunc	onContactRigidBegin;	//=> 剛体と接触した時に呼ばれるコールバック関数
	ContactRigidFunc	onContactRigidPreSolve;	//=> 剛体と接触している時に呼ばれるコールバック関数
	ContactRigidFunc	onContactRigidEnd;		//=> 剛体と接触し終わった時に呼ばれるコールバック関数
	ContactLiquidFunc	onContactLiquidBegin;	//=> 液体と接触した時に呼ばれるコールバック関数
	ContactLiquidFunc	onContactLiquidEnd;		//=> 液体と接触し終わった時に呼ばれるコールバック関数
	uint16_t			contactBitmask;			//=> 接触するオブジェクトのビットマスク
	
	/**
	 *	@brief	コンストラクタ
	 */
	ContactCallback()
		: onContactRigidBegin(		[]( cocos2d::Node*, LiquidFunFixture* ) { } )
		, onContactRigidPreSolve(	[]( cocos2d::Node*, LiquidFunFixture* ) { } )
		, onContactRigidEnd(		[]( cocos2d::Node*, LiquidFunFixture* ) { } )
		, onContactLiquidBegin(		[]( cocos2d::Node*, LiquidFunParticle*, int ) { } )
		, onContactLiquidEnd(		[]( cocos2d::Node*, LiquidFunParticle*, int ) { } )
		, contactBitmask( Contact::toUShort( Contact::Category::NONE ) )
	{
		
	}
};

#endif