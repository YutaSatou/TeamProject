#ifndef _ADX2_MANAGER_H_
#define _ADX2_MANAGER_H_

#include "cocos2d.h"
#include "cri_adx2le.h"
#include "../Template/Singleton.h"

/*------------------------------------------------------------*/
//	@class		：	ADX2Manager
//	@brief		：	ADX2管理者
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class ADX2Manager : public Singleton< ADX2Manager >
{
	
public:
	
	/**
	 *	@brief	デストラクタ
	 */
	~ADX2Manager();
	
	/**
	 *	@brief	初期化
	 *	@param	acf		ACFファイルのパス
	 *	@return	bool	初期化に成功したか否か
	 */
	bool init( const std::string& acf );
	
	/**
	 *	@brief	更新
	 *			ライブラリの内部更新を行うため
	 *			シーン内で毎フレーム呼び出す必要がある。
	 */
	void update();
	
	/**
	 *	@brief	アプリ中断時のコールバック関数
	 */
	void pauseApp();
	
	/**
	 *	@brief	アプリ再開時のコールバック関数
	 */
	void resumeApp();
	
private:
	
	/**
	 *	@brief	コンストラクタ
	 */
	ADX2Manager();
	
	/**
	 *	@brief	プラットフォーム別の初期化
	 */
	void initPlatformSetting();
	
private:
	
	friend class Singleton< ADX2Manager >;	//=>	シングルトンクラスからはコンストラクトを許可
	
	CriAtomDbasId mDbasID;	//=>	D-BAS管理用ID
};

#endif