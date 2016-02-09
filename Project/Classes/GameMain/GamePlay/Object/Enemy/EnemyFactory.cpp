#include "EnemyFactory.h"
#include "cocos2d.h"
#include "../Data/ObjectData.h"
#include "Enemys.h"

// コンストラクタ
EnemyFactory::EnemyFactory()
{
	addProductList();
}

// 生成する製品の追加
void EnemyFactory::addProductList()
{
	addCreateFunction( "Enemy_Slime_1",			[]( ObjectDataPtr objectData, const std::string& nodeName )
					   { return Slime::create( objectData, nodeName ); } );
	
	addCreateFunction( "Enemy_Slime_2",			[]( ObjectDataPtr objectData, const std::string& nodeName )
					   { return Slime::create( objectData, nodeName ); } );
	
	addCreateFunction( "Enemy_Cloud",			[]( ObjectDataPtr objectData, const std::string& nodeName )
					   { return Cloud::create( objectData, nodeName ); } );
	
	addCreateFunction( "Enemy_Mud_Left",		[]( ObjectDataPtr objectData, const std::string& nodeName )
					   { return Mud::create( objectData, nodeName ); } );
	
	addCreateFunction( "Enemy_Mud_Right",		[]( ObjectDataPtr objectData, const std::string& nodeName )
					   { return Mud::create( objectData, nodeName ); } );
	
	addCreateFunction( "Enemy_Cannon_Left",		[]( ObjectDataPtr objectData, const std::string& nodeName )
					   { return Cannon::create( objectData, nodeName, { -30.0f, 15.0f } ); } );
	
	addCreateFunction( "Enemy_Cannon_Right",	[]( ObjectDataPtr objectData, const std::string& nodeName )
					   { return Cannon::create( objectData, nodeName, {  30.0f, 15.0f } ); } );
}