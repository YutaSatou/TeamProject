#ifndef _CONTACT_FUNC_TAG_H_
#define _CONTACT_FUNC_TAG_H_

/**
 *	@brief	接触関数のタグ
 */
enum class ContactFuncTag : int
{
	RIGID_BEGIN		= 0,
	RIGID_PRESOLVE	= 1,
	RIGID_END		= 2,
	LIQUID_BEGIN	= 3,
	LIQUID_END		= 4,
};

#endif