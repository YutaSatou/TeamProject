#include "ContactSendChecker.h"
#include "../../LiquidFun/LiquidFunUserAPI.h"
#include "ContactCallback.h"

using namespace cocos2d;

// コンストラクタ
ContactSendChecker::ContactSendChecker( ContactEventManager::CallbackContainer& callbackContainer )
	: mCallbackContainer( callbackContainer )
{
	
}

// 剛体のフィルタチェックを通過したか否か
bool ContactSendChecker::isRigidFilter( LiquidFunContact* contact, Node* nodeA, Node* nodeB ) const
{
	const std::string& nodeNameA = nodeA->getName();
	const std::string& nodeNameB = nodeB->getName();
	
	if ( !isFind( nodeNameA ) || !isFind( nodeNameB ) )
	{
		return false;
	}
	
	const LiquidFunFilter& filterA = contact->GetFixtureA()->GetFilterData();
	const LiquidFunFilter& filterB = contact->GetFixtureB()->GetFilterData();
	
	return ( isBitStand( filterA.categoryBits, mCallbackContainer[ nodeNameB ]->contactBitmask ) &&
			 isBitStand( filterB.categoryBits, mCallbackContainer[ nodeNameA ]->contactBitmask ) );
}

// 液体のフィルタチェックを通過したか否か
bool ContactSendChecker::isLiquidFilter( LiquidFunFixture* fixture, Node* rigidBodyNode, Node* liquidBodyNode ) const
{
	const std::string& rigidBodyNodeName	= rigidBodyNode->getName();
	const std::string& liquidBodyNodeName	= liquidBodyNode->getName();
	
	if ( !isFind( rigidBodyNodeName ) || !isFind( liquidBodyNodeName ) )
	{
		return false;
	}
	
	const LiquidFunFilter&	filter		= fixture->GetFilterData();
	const unsigned short	liquidBit	= Contact::toUShort( Contact::Category::LIQUID );
	
	return ( isBitStand( filter.categoryBits, mCallbackContainer[ liquidBodyNodeName ]->contactBitmask ) &&
			 isBitStand( liquidBit, mCallbackContainer[ rigidBodyNodeName ]->contactBitmask ) );
}

// 検索に成功したか否か
bool ContactSendChecker::isFind( const std::string& nodeName ) const
{
	return ( mCallbackContainer.find( nodeName ) != mCallbackContainer.end() );
}

// ビットが立っているか否か
bool ContactSendChecker::isBitStand( unsigned short bitA, unsigned short bitB ) const
{
	return ( ( bitA & bitB ) != 0 );
}