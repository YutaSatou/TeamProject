#include "LiquidFunBodySettlor.h"
#include "../../Core/LiquidFunBox2D.h"
#include "../../Core/LiquidFunWorldManager.h"

// 空のボディの装着
LiquidFunBody* LiquidFunBodySettlor::attachEmptyBody( const LiquidFunBodyDesc& bodyDesc )
{
	LiquidFunBody* body = LiquidFunWorldManager::getInstance().addBody( &bodyDesc );
	
	return body;
}

// ボディの装着
LiquidFunBody* LiquidFunBodySettlor::attachBody( const LiquidFunBodyDesc& bodyDesc, const LiquidFunFixtureDesc& fixtureDesc )
{
	LiquidFunBody* body = attachEmptyBody( bodyDesc );
	
	attachFixture( body, fixtureDesc );
	
	return body;
}

// フィクスチャの装着
LiquidFunFixture* LiquidFunBodySettlor::attachFixture( LiquidFunBody* body, const LiquidFunFixtureDesc& fixtureDesc )
{
	return body->CreateFixture( &fixtureDesc );
}

// ボディの装着解除
void LiquidFunBodySettlor::detachBody( LiquidFunBody* body )
{
	LiquidFunWorldManager::getInstance().deleteBody( body );
}

// フィクスチャの装着解除
void LiquidFunBodySettlor::detachFixture( LiquidFunBody* body, LiquidFunFixture* fixture )
{
	body->DestroyFixture( fixture );
}