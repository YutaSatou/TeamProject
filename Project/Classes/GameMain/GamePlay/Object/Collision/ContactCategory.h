#ifndef _CONTACT_CATEGORY_H_
#define _CONTACT_CATEGORY_H_

/**
 *	@brief	接触判定用カテゴリ
 */
enum ContactCategory : int
{
	WALL			= 1 << 0,	// 0x00000001
	ALL_CATEGORY	= 0xFFFF,	// 0xFFFFFFFF
};

#endif