#include "ContactSettlor.h"
#include "../../LiquidFun/LiquidFunUserAPI.h"
#include "ContactEventManager.h"

namespace
{
	/**
	 *	@brief	キャスト
	 *	@param	category		キャストするカテゴリ
	 *	@return	unsigned short	キャストされたカテゴリ
	 */
	unsigned short cast( const ContactCategory& category )
	{
		return static_cast< unsigned short >( category );
	}
}

// コンストラクタ
ContactSettlor::ContactSettlor( LiquidFunBody* targetBody )
	: mTargetBody( targetBody )
	, mContactFilter()
{
	
}

// カテゴリの設定
void ContactSettlor::setupCategory( const ContactCategory& category )
{
	mContactFilter.categoryBitmask = cast( category );
	LiquidFunFilteringSettlor::setupFilter( mTargetBody, mContactFilter );
}

// 衝突するカテゴリの設定
void ContactSettlor::setupCollisionCategory( const OtherCategory& otherCategory )
{
	mContactFilter.collisionBitmask = orCalculate( otherCategory );
	LiquidFunFilteringSettlor::setupFilter( mTargetBody, mContactFilter );
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
	unsigned short bitmask = 0;
	
	for ( auto& bit : otherCategory )
	{
		bitmask = bitmask | cast( bit );
	}
	
	return bitmask;
}
