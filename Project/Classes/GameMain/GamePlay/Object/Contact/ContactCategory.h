#ifndef _CONTACT_CATEGORY_H_
#define _CONTACT_CATEGORY_H_

#include <climits>

/**
 *	@brief	接触判定用カテゴリ
 */
enum class ContactCategory : unsigned short
{
	NONE			= 0x0000,
	WALL			= 1 << 0,
	WALL_EVENT		= 1 << 1,
	TERRAIN			= 1 << 2,
	PLAYER			= 1 << 3,
	SLIME			= 1 << 4,
	ALL_CATEGORY	= USHRT_MAX,
};
	
#endif