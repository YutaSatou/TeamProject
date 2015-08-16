#ifndef _APP_DELEGATE_H_
#define _APP_DELEGATE_H_

#include "cocos2d.h"

/*------------------------------------------------------------*/
//	@class		：	AppDelegate
//	@brief		：	アプリケーション統括者
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class AppDelegate : private cocos2d::Application
{
	
public:
	
	/**
	 *	@brief	コンストラクタ
	 */
	AppDelegate() = default;
	
	/**
	 *	@brief	デストラクタ
	 */
	virtual ~AppDelegate() = default;
	
	/**
	 *	@brief	GLコンテキストの初期化
	 */
	virtual void initGLContextAttrs() override;
	
	/**
	 *	@brief	アプリケーションの起動準備が整った時に呼ばれるコールバック関数
	 *	@return	bool	アプリケーションの初期化に成功したか否か
	 */
	virtual bool applicationDidFinishLaunching() override;
	
	/**
	 *	@brief	アプリケーションが非アクティブ状態になった時に呼ばれるコールバック関数
	 */
	virtual void applicationDidEnterBackground() override;
	
	/**
	 *	@brief	アプリケーションがアクティブ状態になった時に呼ばれるコールバック関数
	 */
	virtual void applicationWillEnterForeground() override;
};

#endif