#include "ContactSendChecker.h"

using namespace cocos2d;

// コンストラクタ
ContactSendChecker::ContactSendChecker( ContactEventManager::CallbackContainer& callbackContainer )
	: mCallbackContainer( callbackContainer )
{
	
}

// フィルタチェックを通過したか否か
bool ContactSendChecker::isFilter( const CategoryPair& categoryPair, const NodeNamePair& nodeNamePair ) const
{
	if ( !isFind( nodeNamePair.first ) )	{ return false; }
	if ( !isFind( nodeNamePair.second ) )	{ return false; }
	
	return ( isBitStand( categoryPair.first, mCallbackContainer.at( nodeNamePair.second )->contactBitmask ) &&
			 isBitStand( categoryPair.second, mCallbackContainer.at( nodeNamePair.first )->contactBitmask ) );
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