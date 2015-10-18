#include "ContactSettlor.h"
#include "ContactManager.h"

using namespace cocos2d;

// コンストラクタ
ContactSettlor::ContactSettlor( PhysicsBody* targetBody, bool isSetupShape )
	: mTargetBody( targetBody )
	, mIsSetupShape( isSetupShape )
{
	
}

// カテゴリの設定
void ContactSettlor::setupCategory( ContactCategory category )
{
	int bitMask = intCast( category );
	
	mTargetBody->setCategoryBitmask( bitMask );
	eachShapeVector( [ &bitMask ]( PhysicsShape* shape ) { shape->setCategoryBitmask( bitMask ); } );
}

// 衝突の有効化
void ContactSettlor::enableCollision( OtherCategory otherCategory )
{
	int bitmask = getBitmask( otherCategory );
	
	mTargetBody->setCollisionBitmask( bitmask );
	eachShapeVector( [ &bitmask ]( PhysicsShape* shape ) { shape->setCollisionBitmask( bitmask ); } );
}

// 接触の有効化
void ContactSettlor::enableContact( OtherCategory otherCategory )
{
	int bitmask = getBitmask( otherCategory );
	
	mTargetBody->setContactTestBitmask( bitmask );
	eachShapeVector( [ &bitmask ]( PhysicsShape* shape ) { shape->setContactTestBitmask( bitmask ); } );
}

// 接触コールバックの有効化
void ContactSettlor::enableContactCallback( const std::string& nodeName, SharedPtr< ContactCallback > callback )
{
	auto isNotEmpty	= !nodeName.empty();
	auto errMessage	= "ノードに名前が設定されていません。接触用コールバックを受け取りたい場合は、ノードに名前を設定する必要があります。";
	
	// ノードに名前が設定されていない場合は即死。
	assert( isNotEmpty && errMessage );
	
	ContactManager::getInstance().addCallback( nodeName, callback );
}

// 接触コールバックの無効化
void ContactSettlor::disableContactCallback( const std::string& nodeName )
{
	ContactManager::getInstance().deleteCallback( nodeName );
}

// シェイプベクタの巡回
void ContactSettlor::eachShapeVector( std::function< void( PhysicsShape* ) > func )
{
	if ( !mIsSetupShape ) { return; }
	
	// ボディからシェイプベクタを取得する。
	auto& shapes = mTargetBody->getShapes();
	
	if ( shapes.empty() ) { return; }
	
	std::for_each( shapes.begin(), shapes.end(), [ &func ]( PhysicsShape* shape )
	{
		func( shape );
	} );
}

// ビットマスクの取得
int ContactSettlor::getBitmask( OtherCategory otherCategory )
{
	int bitmask = 0;
	
	for ( ContactCategory bit : otherCategory )
	{
		// 全ての要素とOR演算する。
		bitmask = bitmask | intCast( bit );
	}
	
	return bitmask;
}

// カテゴリからint型への変換
int ContactSettlor::intCast( ContactCategory category )
{
	return static_cast< int >( category );
}