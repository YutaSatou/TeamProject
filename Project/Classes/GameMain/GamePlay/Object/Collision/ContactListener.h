#ifndef _CONTACT_LISTENER_H_
#define _CONTACT_LISTENER_H_

#include "cocos2d.h"

/*------------------------------------------------------------*/
//	@class		：	ContactListener
//	@brief		：	接触検知リスナ
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class ContactListener : public cocos2d::Node
{
	
protected:
	
	/**
	 *	@brief	コンストラクタ
	 */
	ContactListener() = default;
	
	/**
	 *	@brief	デストラクタ
	 */
	~ContactListener() = default;
	
	/**
	 *	@brief	初期化
	 *	@return	bool	初期化が完了したか否か
	 */
	virtual bool init() override;
	
public:
	
	/**
	 *	@brief	インスタンスの生成
	 *	@return	ContactListener	インスタンス
	 */
	static ContactListener* create();
	
private:
	
	/**
	 *	@brief	リスナの初期化
	 */
	void initListener();
};

#endif