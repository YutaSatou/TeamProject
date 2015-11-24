#ifndef _LIQUID_FUN_CONTACT_FILTER_H_
#define _LIQUID_FUN_CONTACT_FILTER_H_

/*------------------------------------------------------------*/
//	@class		：	LiquidFunContactFilter
//	@brief		：	LiquidFunの接触フィルタ
//	@author		：	利川聖太
/*------------------------------------------------------------*/
struct LiquidFunContactFilter
{
	unsigned short	categoryBitmask;	//=> カテゴリビットマスク
	unsigned short	collisionBitmask;	//=> 衝突するオブジェクトのビットマスク
	signed short	groupIndex;			//=> グループインデックス
	
	/**
	 *	@brief	コンストラクタ
	 */
	LiquidFunContactFilter()
		: categoryBitmask( 0x0001 )
		, collisionBitmask( 0xFFFF )
		, groupIndex( 0x0000 ) { }
	
	/**
	 *	@brief	コンストラクタ
	 *	@param	_categoryBitmask	カテゴリビットマスク
	 *	@param	_collisionBitmask	衝突するオブジェクトのビットマスク
	 *	@param	_groupIndex			グループインデックス
	 */
	LiquidFunContactFilter( unsigned short _categoryBitmask, unsigned short _collisionBitmask, signed int _groupIndex )
		: categoryBitmask( _categoryBitmask )
		, collisionBitmask( _collisionBitmask )
		, groupIndex( _groupIndex ) { }
};

#endif