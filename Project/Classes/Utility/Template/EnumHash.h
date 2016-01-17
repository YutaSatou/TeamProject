#ifndef _ENUM_HASH_H_
#define _ENUM_HASH_H_

#include <cstddef>
#include <functional>

/*------------------------------------------------------------*/
//	@struct		：	EnumHash
//	@brief		：	map用のHash
//	@author		：	利川聖太
/*------------------------------------------------------------*/
struct EnumHash
{
	/**
	 *	@brief	関数オブジェクト
	 *	@param	t		型
	 *	@return	size_t	要素数
	 */
	template< typename T >
	std::size_t operator () ( T x ) const
	{
		return static_cast< std::size_t >( x );
	}
};

#endif