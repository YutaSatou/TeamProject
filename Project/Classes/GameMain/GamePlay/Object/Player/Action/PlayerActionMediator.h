#ifndef _PLAYER_ACTION_MEDIATOR_H_
#define _PLAYER_ACTION_MEDIATOR_H_

#include "../../Contact/ContactCategory.h"

/*------------------------------------------------------------*/
//	@class		：	PlayerEatAction
//	@brief		：	アクション制御仲介者
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class PlayerActionMediator
{
	
public:
	
	using ActionTag = Contact::Category;
	
public:
	
	/**
	 *	@brief	アクションの変更
	 *	@param	tag	変更するアクションのタグ
	 */
	virtual void switchAction( const ActionTag& tag ) = 0;
	
protected:
	
	/**
	 *	@brief	コンストラクタ
	 */
	PlayerActionMediator() = default;
	
	/**
	 *	@brief	デストラクタ
	 */
	virtual ~PlayerActionMediator() = default;
};

#endif