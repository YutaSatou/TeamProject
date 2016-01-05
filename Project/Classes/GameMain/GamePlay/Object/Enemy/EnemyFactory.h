#ifndef _ENEMY_FACTORY_H_
#define _ENEMY_FACTORY_H_

#include "../Data/ObjectFactory.h"
#include "Utility/Template/SmartPtr.h"

namespace cocos2d
{
	class Node;
}

struct ObjectData;

/*------------------------------------------------------------*/
//	@class		：	EnemyFactory
//	@brief		：	敵生成工場
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class EnemyFactory : public ObjectFactory< cocos2d::Node, SharedPtr< ObjectData >, const std::string& >
{
	
public:
	
	/**
	 *	@brief	コンストラクタ
	 */
	EnemyFactory();
	
	/**
	 *	@brief	デストラクタ
	 */
	~EnemyFactory() = default;
	
private:
	
	/**
	 *	@brief	生成する製品の追加
	 */
	void addProductList();
};

#endif