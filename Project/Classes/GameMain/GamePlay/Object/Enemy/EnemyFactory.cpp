#include "EnemyFactory.h"
#include "cocos2d.h"
#include "../Data/ObjectData.h"
#include "Slime.h"
#include "Cloud.h"

// コンストラクタ
EnemyFactory::EnemyFactory()
{
	addProductList();
}

// 生成する製品の追加
void EnemyFactory::addProductList()
{
	addCreateFunction( "Enemy_Slime_1",	[]( ObjectDataPtr objectData, const std::string& nodeName )
					   { return Slime::create( objectData, nodeName ); } );
	
	addCreateFunction( "Enemy_Slime_2",	[]( ObjectDataPtr objectData, const std::string& nodeName )
					   { return Slime::create( objectData, nodeName ); } );
	
	addCreateFunction( "Enemy_Cloud",	[]( ObjectDataPtr objectData, const std::string& nodeName )
					   { return Cloud::create( objectData, nodeName ); } );
}