#include "EnemyFactory.h"
#include "cocos2d.h"
#include "../Data/ObjectData.h"
#include "Slime.h"

// コンストラクタ
EnemyFactory::EnemyFactory()
{
	initProductList();
}

// 生成する製品の初期化
void EnemyFactory::initProductList()
{
	addCreateFunction( "Slime", []( SharedPtr< ObjectData > objectData, const std::string& nodeName )
					   { return Slime::create( objectData, nodeName ); } );
}