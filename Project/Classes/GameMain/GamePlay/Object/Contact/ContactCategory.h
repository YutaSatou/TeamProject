#ifndef _CONTACT_CATEGORY_H_
#define _CONTACT_CATEGORY_H_

#include <climits>
#include <cstdint>

namespace Contact
{
	/**
	 *	@brief	接触判定用カテゴリ
	 */
	enum class Category : uint16_t
	{
		NONE			= 0x0000,
		WALL			= 1 << 0,
		WALL_EVENT		= 1 << 1,
		LIQUID			= 1 << 2,
		PLAYER			= 1 << 3,
		SLIME			= 1 << 4,
		ALL_CATEGORY	= USHRT_MAX,
	};
	
	/**
	 *	@brief	uint16_tへの変換
	 *	@param	category	変換するカテゴリ
	 *	@return	uint16_t	変換された値
	 */
	static uint16_t toUShort( const Category& category )
	{
		return static_cast< uint16_t >( category );
	}
	
	/**
	 *	@brief	enumへの変換
	 *	@param	category	変換するカテゴリ
	 *	@return	Category	変換された値
	 */
	static Contact::Category toEnum( uint16_t category )
	{
		return static_cast< Contact::Category >( category );
	}
}

#endif