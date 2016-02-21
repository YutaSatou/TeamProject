#ifndef _CONTACT_CATEGORY_H_
#define _CONTACT_CATEGORY_H_

#include <cstdint>
#include <limits>

namespace Contact
{
	/**
	 *	@brief	接触判定用カテゴリ
	 */
	enum class Category : std::uint16_t
	{
		NONE			= 0x0000,
		DEFAULT			= 1 << 0,
		LIQUID			= 1 << 1,
		WALL			= 1 << 2,
		WALL_EVENT		= 1 << 3,
		SLIME			= 1 << 4,
		CLOUD			= 1 << 5,
		MUD				= 1 << 6,
		CANNON			= 1 << 7,
		ALL_CATEGORY	= std::numeric_limits< std::uint16_t >::max(),
	};
	
	/**
	 *	@brief	uint16_tへの変換
	 *	@param	category	変換するカテゴリ
	 *	@return	uint16_t	変換された値
	 */
	static std::uint16_t toUShort( const Category& category )
	{
		return static_cast< std::uint16_t >( category );
	}
	
	/**
	 *	@brief	enumへの変換
	 *	@param	category	変換するカテゴリ
	 *	@return	Category	変換された値
	 */
	static Contact::Category toEnum( std::uint16_t category )
	{
		return static_cast< Contact::Category >( category );
	}
}

#endif