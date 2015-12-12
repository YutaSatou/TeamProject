#include "ContactLiquidSender.h"
#include "../../LiquidFun/LiquidFunUserAPI.h"
#include "../../LiquidFun/LiquidFunCoreAPI.h"
#include "ContactFuncTag.h"
#include "ContactSendChecker.h"

using namespace cocos2d;

// コンストラクタ
ContactLiquidSender::ContactLiquidSender( ContactEventManager::CallbackContainer& callbackContainer )
	: mCallbackContainer( callbackContainer )
	, mSendChecker( makeShared< ContactSendChecker >( callbackContainer ) )
{
	
}

// 通知
void ContactLiquidSender::send( const ContactFuncTag& funcTag, LiquidFunFixture* fixture, LiquidFunParticle* particle, int index )
{
	// 接触したボディとボディに登録されているノードを取得する。パーティクルは登録されているノードの親ノードを取得する。
	LiquidFunBody*	body			= fixture->GetBody();
	Node*			particleNode	= LiquidFunHelper::getNode( particle->GetUserDataBuffer() );
	Node*			rigidBodyNode	= LiquidFunHelper::getNode( body );
	Node*			liquidBodyNode	= particleNode->getParent();
	
	if ( !rigidBodyNode || !liquidBodyNode )
	{
		// ノードが登録されていない場合は終了する。
		return;
	}
	
	if ( !mSendChecker->isLiquidFilter( fixture, rigidBodyNode, liquidBodyNode ) )
	{
		// フィルタチェックを通過できない場合は終了する。
		return;
	}
	
	// オブジェクトに接触を通知する。
	sendContactObject( funcTag, rigidBodyNode->getName(), std::make_tuple( liquidBodyNode, body, particle, index ) );
	sendContactObject( funcTag, liquidBodyNode->getName(), std::make_tuple( rigidBodyNode, body, particle, index ) );
}

// オブジェクトへの接触通知
void ContactLiquidSender::sendContactObject( const ContactFuncTag& funcTag, const std::string& nodeName, const ContactInfo& contact )
{
	// タプルから要素を取得する。
	auto& contactNode	= std::get< 0 >( contact );
	auto& body			= std::get< 1 >( contact );
	auto& particle		= std::get< 2 >( contact );
	auto& index			= std::get< 3 >( contact );
	
	if ( funcTag == ContactFuncTag::LIQUID_BEGIN )
	{
		mCallbackContainer[ nodeName ]->onContactLiquidBegin( contactNode, body, particle, index );
		return;
	}
	
	if ( funcTag == ContactFuncTag::LIQUID_END )
	{
		mCallbackContainer[ nodeName ]->onContactLiquidEnd( contactNode, body, particle, index );
		return;
	}
}