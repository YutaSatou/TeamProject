#ifndef _CONTACT_SEND_CHECKER_H_
#define _CONTACT_SEND_CHECKER_H_

#include "ContactEventManager.h"

/*------------------------------------------------------------*/
//	@class		：	ContactSendChecker
//	@brief		：	接触通知確認者
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class ContactSendChecker
{
	
public:
	
	using CategoryPair	= std::pair< uint16_t, uint16_t >;
	using NodeNamePair	= std::pair< std::string, std::string >;
	
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
	 *	@brief	フィルタチェックを通過したか否か
	 *	@param	categoryPair	接触したカテゴリのペア
	 *	@param	nodeNamePair	接触したノードの名前のペア
	 *	@return	bool			フィルタチェックを通過したか否か
	 */
	bool isFilter( const CategoryPair& categoryPair, const NodeNamePair& nodeNamePair ) const;
	
private:
	
	/**
	 *	@brief	検索に成功したか否か
	 *	@param	nodeName	検索するノードの名前
	 *	@return	bool		検索に成功したか否か
	 */
	bool isFind( const std::string& nodeName ) const;
	
	/**
	 *	@brief	ビットが立っているか否か
	 *	@param	bitA	ビットA
	 *	@param	bitB	ビットB
	 *	@return	bool	ビットが立っているか否か
	 */
	bool isBitStand( uint16_t bitA, uint16_t bitB ) const;
	
private:
	
	ContactEventManager::CallbackContainer& mCallbackContainer;	//=> コールバックコンテナ
};

#endif