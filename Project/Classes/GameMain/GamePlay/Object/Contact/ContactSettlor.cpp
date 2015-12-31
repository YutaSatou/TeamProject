#include "ContactSettlor.h"
#include "ContactEventManager.h"

// コンストラクタ
ContactSettlor::ContactSettlor( LiquidFunBody* targetBody )
	: mTargetBody( targetBody )
	, mContactFilter()
{
	
}

// カテゴリの設定
void ContactSettlor::setupCategory( const Contact::Category& category )
{
	mContactFilter.categoryBitmask = Contact::toUShort( category );
	LiquidFunFilteringSettlor::setupFilter( mTargetBody, mContactFilter );
}

// 衝突するカテゴリの設定
void ContactSettlor::setupCollisionCategory( const OtherCategory& otherCategory )
{
	mContactFilter.collisionBitmask = orCalculate( otherCategory );
	LiquidFunFilteringSettlor::setupFilter( mTargetBody, mContactFilter );
}

// 接触するカテゴリの設定
void ContactSettlor::setupContactCategory( SharedPtr< ContactCallback > callback, const OtherCategory& otherCategory )
{
	callback->contactBitmask = orCalculate( otherCategory );
}

// 接触コールバックの有効化
void ContactSettlor::enableContactCallback( const std::string& nodeName, SharedPtr< ContactCallback > callback )
{
	auto isNotEmpty	= !nodeName.empty();
	auto errMessage	= "ノードに名前が設定されていません。接触用コールバックを受け取りたい場合は、ノードに名前を設定する必要があります。";
	
	assert( isNotEmpty && errMessage );
	
	ContactEventManager::getInstance().addCallback( nodeName, callback );
}

// 接触コールバックの無効化
void ContactSettlor::disableContactCallback( const std::string& nodeName )
{
	ContactEventManager::getInstance().deleteCallback( nodeName );
}

// OR演算
unsigned short ContactSettlor::orCalculate( const OtherCategory& otherCategory )
{
	uint16_t bitmask { 0 };
	
	for ( auto& bit : otherCategory )
	{
		bitmask = bitmask | Contact::toUShort( bit );
	}
	
	return bitmask;
}