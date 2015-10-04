#ifndef _CONTACT_CATEGORY_H_
#define _CONTACT_CATEGORY_H_

#include <climits>

/**
 *	@brief	接触判定用カテゴリ
 */
enum class ContactCategory : int
{
	WALL_UP			= 1 << 0,
	WALL_DOWN		= 1 << 1,
	WALL_LEFT		= 1 << 2,
	WALL_RIGHT		= 1 << 3,
	PLAYER			= 1 << 4,
	SLIME			= 1 << 5,
	ALL_CATEGORY	= INT_MAX,
};

#endif