#include "LiquidObject.h"
#include "../../LiquidFun/LiquidFunCoreAPI.h"
#include "../Contact/ContactSettlor.h"

using namespace cocos2d;
using namespace std::placeholders;

// コンストラクタ
LiquidObject::LiquidObject()
	: mParticle( nullptr )
	, mParticleGroup( nullptr )
{
	
}

// デストラクタ
LiquidObject::~LiquidObject()
{
	LiquidFunParticleSettlor::detachParticleGroup( mParticle, mParticleGroup );
}

// パーティクルの更新
void LiquidObject::updateParticle()
{
	eachBuffer( [ this ]( UserDataPointer* userData, LiquidFunParticleColor* color, LiquidFunVec2* position )
	{
		// ユーザデータからノードを取得する。
		Node* node = LiquidFunHelper::getNode( userData );
		
		if ( !node )
		{
			// 取得に失敗した場合は終了する。
			return;
		}
		
		// 各バッファの情報をノードに適応する。
		node->setColor( Color3B( ( *color ).r, ( *color ).g, ( *color ).b ) );
		node->setPosition( LiquidFunHelper::toPixsel( ( *position ) ) + ( getContentSize() / 2.0f ) );
		node->setOpacity( ( *color ).a );
	} );
}

// 剛体と液体の接触時に呼ばれるコールバック関数
void LiquidObject::onContactLiquidBegin( Node* contactNode, LiquidFunBody* body, LiquidFunParticle* particle, int index )
{
	return;
}

// 剛体と液体の離脱時に呼ばれるコールバック関数
void LiquidObject::onContactLiquidEnd( Node* contactNode, LiquidFunBody* body, LiquidFunParticle* particle, int index )
{
	return;
}

// テクスチャの登録
void LiquidObject::registerTexture( const std::string& textureName )
{
	eachBuffer( [ this, &textureName ]( UserDataPointer* userData, LiquidFunParticleColor* color, LiquidFunVec2* position )
	{
		// パーティクル用のスプライトを生成する。
		Sprite* particle = Sprite::create( textureName );
		
		// ユーザデータにスプライトを登録する。
		( *userData ) = particle;
		
		// 自身に追加する。
		addChild( particle );
	} );
}

// 接触コールバックの設定
void LiquidObject::setupContactCallback()
{
	// 接触コールバックを設定する。
	SharedPtr< ContactCallback > callback	= makeShared< ContactCallback >();
	callback->onContactLiquidBegin			= std::bind( &LiquidObject::onContactLiquidBegin,	this, _1, _2, _3, _4 );
	callback->onContactLiquidEnd			= std::bind( &LiquidObject::onContactLiquidEnd,		this, _1, _2, _3, _4 );
	
	// 接触するカテゴリの設定、コールバックの有効化を行う。
	ContactSettlor contactSettlor( nullptr );
	contactSettlor.setupContactCategory( callback );
	contactSettlor.enableContactCallback( getName(), callback );
}

// バッファの巡回
void LiquidObject::eachBuffer( const EachBufferFunc& func )
{
	// パーティクルカウントとバッファインデックスオフセットを取得する。
	const auto& particleCount	= mParticle->GetParticleCount();
	const auto& bufferIndex		= mParticleGroup->GetBufferIndex();
	
	// 各バッファのアドレスを取得する。
	auto userData	= mParticle->GetUserDataBuffer()	+ bufferIndex;
	auto color		= mParticle->GetColorBuffer()		+ bufferIndex;
	auto position	= mParticle->GetPositionBuffer()	+ bufferIndex;
	
	for ( int i = 0; i < particleCount; ++i )
	{
		// 関数を実行する。
		func( userData, color, position );
		
		// 各バッファのアドレスを進める。
		++userData, ++color, ++position;
	}
}