#ifndef _LIQUID_FUN_CONTACT_FILTER_H_
#define _LIQUID_FUN_CONTACT_FILTER_H_

#include <cstdint>

/*------------------------------------------------------------*/
//	@struct		：	LiquidFunContactFilter
//	@brief		：	LiquidFunの接触フィルタ
//	@author		：	利川聖太
/*------------------------------------------------------------*/
struct LiquidFunContactFilter
{
	std::uint16_t	categoryBitmask;	//=> カテゴリビットマスク
	std::uint16_t	collisionBitmask;	//=> 衝突するオブジェクトのビットマスク
	short			groupIndex;			//=> グループインデックス
	
	/**
	 *	@brief	コンストラクタ
	 */
	LiquidFunContactFilter()
		: categoryBitmask( 0x0001 )
		, collisionBitmask( 0xFFFF )
		, groupIndex( 0x0000 )
	{
		
	}
	
	/**
	 *	@brief	コンストラクタ
	 *	@param	_categoryBitmask	カテゴリビットマスク
	 *	@param	_collisionBitmask	衝突するオブジェクトのビットマスク
	 *	@param	_groupIndex			グループインデックス
	 */
	LiquidFunContactFilter( std::uint16_t _categoryBitmask, std::uint16_t _collisionBitmask, short _groupIndex )
		: categoryBitmask( _categoryBitmask )
		, collisionBitmask( _collisionBitmask )
		, groupIndex( _groupIndex )
	{
		
	}
};

#endif