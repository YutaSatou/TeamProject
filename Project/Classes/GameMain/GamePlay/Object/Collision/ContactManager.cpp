#include "ContactManager.h"
#include "ContactCallback.h"

using namespace cocos2d;

// コンストラクタ
ContactManager::ContactManager()
	: mContactSender( mCallbackContainer )
{
	
}

// デストラクタ
ContactManager::~ContactManager()
{
	mCallbackContainer.clear();
}

// 接触イベントコールバック
void ContactManager::onContactEvent( ContactFuncTag funcTag, PhysicsContact& contact )
{
	mContactSender.send( funcTag, contact );
}

// コールバックの追加
void ContactManager::addCallback( const std::string& nodeName, SharedPtr< ContactCallback > callback )
{
	mCallbackContainer[ nodeName ] = callback;
}

// コールバックの削除
void ContactManager::deleteCallback( const std::string& nodeName )
{
	mCallbackContainer.erase( nodeName );
}