#include "LiquidFunFilteringSettlor.h"
#include "../Core/LiquidFunBox2D.h"
#include "LiquidFunContactFilter.h"

// フィルタの設定
void LiquidFunFilteringSettlor::setupFilter( LiquidFunFixture* fixture, const LiquidFunContactFilter& contactFilter )
{
	LiquidFunFilter filter;
	
	filter.categoryBits	= contactFilter.categoryBitmask;
	filter.maskBits		= contactFilter.collisionBitmask;
	filter.groupIndex	= contactFilter.groupIndex;
	
	fixture->SetFilterData( filter );
}

// フィルタの設定
void LiquidFunFilteringSettlor::setupFilter( LiquidFunBody* body, const LiquidFunContactFilter& contactFilter )
{
	for ( LiquidFunFixture* fixture { body->GetFixtureList() }; fixture; fixture = fixture->GetNext() )
	{
		setupFilter( fixture, contactFilter );
	}
}