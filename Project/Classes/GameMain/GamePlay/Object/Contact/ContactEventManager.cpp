#include "ContactEventManager.h"
#include "../../LiquidFun/LiquidFunUserAPI.h"
#include "ContactFuncTag.h"
#include "ContactCallback.h"
#include "ContactRigidSender.h"
#include "ContactLiquidSender.h"

// コンストラクタ
ContactEventManager::ContactEventManager()
	: mCallbackContainer()
	, mContactRigidSender( makeShared< ContactRigidSender >( mCallbackContainer ) )
	, mContactLiquidSender( makeShared< ContactLiquidSender >( mCallbackContainer ) )
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
	mContactRigidSender->send( funcTag, contact );
}

// 接触イベントコールバック
void ContactEventManager::onContactEvent( const ContactFuncTag& funcTag, LiquidFunFixture* fixture, LiquidFunParticle* particle, int index )
{
	mContactLiquidSender->send( funcTag, fixture, particle, index );
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