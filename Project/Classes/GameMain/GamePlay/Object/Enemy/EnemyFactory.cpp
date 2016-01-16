#include "EnemyFactory.h"
#include "cocos2d.h"
#include "../Data/ObjectData.h"
#include "Slime.h"

// コンストラクタ
EnemyFactory::EnemyFactory()
{
	addProductList();
}

// 生成する製品の追加
void EnemyFactory::addProductList()
{
	addCreateFunction( "Slime_1", []( ObjectDataPtr objectData, const std::string& nodeName )
					   { return Slime::create( objectData, nodeName ); } );
	
	addCreateFunction( "Slime_2", []( ObjectDataPtr objectData, const std::string& nodeName )
					   { return Slime::create( objectData, nodeName ); } );
}