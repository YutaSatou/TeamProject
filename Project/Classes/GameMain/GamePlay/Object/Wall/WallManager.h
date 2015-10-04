#ifndef _WALL_MANAGER_H_
#define _WALL_MANAGER_H_

#include "cocos2d.h"

enum class ContactCategory : int;

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
	
private:
	
	/**
	 *	@brief	壁の装着
	 *	@param	category	設定するカテゴリ
	 *	@param	start		線の開始座標
	 *	@param	end			線の終了座標
	 */
	void attachWall( const ContactCategory& category, const cocos2d::Vec2& start, const cocos2d::Vec2& end );
};

#endif