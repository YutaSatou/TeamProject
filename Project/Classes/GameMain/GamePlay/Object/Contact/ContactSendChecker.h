#ifndef _CONTACT_SEND_CHECKER_H_
#define _CONTACT_SEND_CHECKER_H_

#include "../../LiquidFun/LiquidFunDefine.h"
#include "ContactEventManager.h"

namespace cocos2d
{
	class Node;
}

/*------------------------------------------------------------*/
//	@class		：	ContactSendChecker
//	@brief		：	接触通知確認者
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class ContactSendChecker
{
	
public:
	
	/**
	 *	@brief	コンストラクタ
	 *	@param	callbackContainer	コールバックコンテナ
	 */
	ContactSendChecker( ContactEventManager::CallbackContainer& callbackContainer );
	
	/**
	 *	@brief	デストラクタ
	 */
	~ContactSendChecker() = default;
	
	/**
	 *	@brief	剛体のフィルタチェックを通過したか否か
	 *	@param	contact	接触したオブジェクトの情報
	 *	@param	nodeA	接触したボディに登録されているノード
	 *	@param	nodeB	接触したボディに登録されているノード
	 *	@return	bool	フィルタチェックを通過したか否か
	 */
	bool isRigidFilter( LiquidFunContact* contact, cocos2d::Node* nodeA, cocos2d::Node* nodeB ) const;
	
	/**
	 *	@brief	液体のフィルタチェックを通過したか否か
	 *	@param	fixture			接触したフィクスチャ
	 *	@param	rigidBodyNode	剛体に登録されているノード
	 *	@param	liquidBodyNode	液体に登録されているノード
	 *	@return	bool			フィルタチェックを通過したか否か
	 */
	bool isLiquidFilter( LiquidFunFixture* fixture, cocos2d::Node* rigidBodyNode, cocos2d::Node* liquidBodyNode ) const;
	
private:
	
	/**
	 *	@brief	検索に成功したか否か
	 *	@param	nodeName	検索するノードの名前
	 *	@return	bool		検索に成功したか否か
	 */
	bool isFind( const std::string& nodeName ) const;
	
	/**
	 *	@brief	ビットが立っているか否か
	 *	@param	bitA	ビット
	 *	@param	bitB	ビット
	 *	@return	bool	ビットが立っているか否か
	 */
	bool isBitStand( unsigned short bitA, unsigned short bitB ) const;
	
private:
	
	ContactEventManager::CallbackContainer& mCallbackContainer;	//=> コールバックコンテナ
};

#endif