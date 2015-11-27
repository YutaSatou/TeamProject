#ifndef _WALL_MANAGER_H_
#define _WALL_MANAGER_H_

#include "cocos2d.h"

/*------------------------------------------------------------*/
//	@class		：	WallManager
//	@brief		：	壁管理者
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class WallManager : public cocos2d::Node
{
	
protected:
	
	/**
	 *	@brief	コンストラクタ
	 */
	WallManager() = default;
	
	/**
	 *	@brief	デストラクタ
	 */
	~WallManager() = default;
	
	/**
	 *	@brief	初期化
	 *	@return	bool	初期化が完了したか否か
	 */
	virtual bool init() override;
	
public:
	
	/**
	 *	@brief	インスタンスの生成
	 *	@return	WallManager	インスタンス
	 */
	static WallManager* create();
};

#endif