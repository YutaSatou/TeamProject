#include "ContactEventManager.h"
#include "../../LiquidFun/LiquidFunUserAPI.h"
#include "ContactFuncTag.h"
#include "ContactCallback.h"
#include "ContactSender.h"

using namespace cocos2d;

// コンストラクタ
ContactEventManager::ContactEventManager()
	: mContactSender( makeUnique< ContactSender >( mCallbackContainer ) )
{
	
}

// デストラクタ
ContactEventManager::~ContactEventManager()
{
	mCallbackContainer.clear();
}

// 接触イベントコールバック
void ContactEventManager::onContactEvent( const ContactFuncTag& funcTag, LiquidFunContact* contact )
{
	mContactSender->send( funcTag, contact );
}

// コールバックの追加
void ContactEventManager::addCallback( const std::string& nodeName, SharedPtr< ContactCallback > callback )
{
	mCallbackContainer[ nodeName ] = callback;
}

// コールバックの削除
void ContactEventManager::deleteCallback( const std::string& nodeName )
{
	mCallbackContainer.erase( nodeName );
}