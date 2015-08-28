#ifndef _CONTACT_CATEGORY_H_
#define _CONTACT_CATEGORY_H_

/**
 *	@brief	接触判定用カテゴリ
 */
enum ContactCategory : int
{
	WALL			= 1 << 0,
	BALL			= 1 << 1,
	ALL_CATEGORY	= INT_MAX,
};

#endif