#ifndef _CONTACT_CATEGORY_H_
#define _CONTACT_CATEGORY_H_

#include <climits>

/**
 *	@brief	接触判定用カテゴリ
 */
enum ContactCategory : int
{
	WALL			= 1 << 0,
	PLAYER			= 1 << 1,
	SLIME			= 1 << 2,
	ALL_CATEGORY	= INT_MAX,
};

#endif