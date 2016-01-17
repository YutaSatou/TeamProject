#include "ContactEventManager.h"
#include "ContactFuncTag.h"
#include "ContactSender.h"

// コンストラクタ
ContactEventManager::ContactEventManager()
	: mCallbackContainer()
	, mContactSender( std::make_shared< ContactSender >( mCallbackContainer ) )
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

// 接触イベントコールバック
void ContactEventManager::onContactEvent( const ContactFuncTag& funcTag, LiquidFunFixture* fixture, LiquidFunParticle* particle, int index )
{
	mContactSender->send( funcTag, fixture, particle, index );
}

// コールバックの追加
void ContactEventManager::addCallback( const std::string& nodeName, ContactCallback::Ptr callback )
{
	mCallbackContainer[ nodeName ] = callback;
}

// コールバックの削除
void ContactEventManager::deleteCallback( const std::string& nodeName )
{
	mCallbackContainer.erase( nodeName );
}