//
//  ResultTexturePhysics.cpp
//  TeamProject
//
//  Created by Satou yuta on 2016/01/18.
//
//

#include "ResultTexturePhysics.h"
#include "../../GamePlay/LiquidFun/LiquidFunUserAPI.h"
#include "../../GamePlay/Control/GameControlMediator.h"
#include "../../GamePlay/Object/Common/LiquidFunBodyDeleter.h"
#include "../../GamePlay/Object/Contact/ContactSettlor.h"
#include "../ResultEvaluation.h"

using namespace cocos2d;

// コンストラクタ
ResultTexturePhysics::ResultTexturePhysics()
: mBody( nullptr )
{
	
}

// 初期化
bool ResultTexturePhysics::init( float radius, const cocos2d::Vec2& pos )
{
	if ( !Node::init() )
	{
		return false;
	}
	
	// 各パラメータを設定する。
	setName( "Circle" );
	setAnchorPoint( Vec2::ANCHOR_MIDDLE );
	setPosition( pos );
	
	// 物理構造の初期化を行う。
	initPhysics( radius );
	
	return true;
}

// インスタンスの生成
ResultTexturePhysics* ResultTexturePhysics::create( float radius, const cocos2d::Vec2& pos )
{
	ResultTexturePhysics* inst { new ResultTexturePhysics() };
	
	if ( inst && inst->init( radius, pos ) )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

void ResultTexturePhysics::initPhysics( float radius )
{
	// マテリアル( 密度, 反発係数, 摩擦係数 )を用意する。
	LiquidFunMaterial material { 0.0f, 0.2f, 1.0f };
	
	// ボディの生成に必要な設定記述子を生成する。
	LiquidFunBodyDescCreator	bodyDescCreator;
	LiquidFunBodyDesc			bodyDesc	{ bodyDescCreator.createBodyDesc( this, LiquidFunBodyType::b2_staticBody ) };
	LiquidFunFixtureDesc		fixtureDesc	{ bodyDescCreator.createCircle( radius, material ) };
	
	// ボディを装着する。
	mBody = LiquidFunBodySettlor::attachBody( bodyDesc, fixtureDesc );
	
	// ノードが削除されるタイミングで、ボディも削除されるように設定する。
	addChild( LiquidFunBodyDeleter::create( mBody ) );
	
	// 接触コールバックを設定する。
	ContactCallback::Ptr callback { std::make_shared< ContactCallback >() };
	callback->onContactLiquidBegin = [ this ]( Node* contactNode, LiquidFunParticle* particle, int index )
	{
		ResultEvaluation* r = ResultEvaluation::create();
		r->setScale( 0.0f );
		r->setPosition( Vec2( 360, 930 ) );
		getParent()->addChild( r );
		
		ActionInterval* act = Spawn::create( FadeTo::create( 1.0f, 255 ), ScaleTo::create( 1.0f, 1.0f ), nullptr );
		r->runAction( act );
		
		this->setName( "Owari" );
	};
	
	// カテゴリの設定、衝突するカテゴリの設定、接触するカテゴリの設定、コールバックの有効化を行う。
	ContactSettlor contactSettlor{ mBody };
	contactSettlor.setupCategory( Contact::Category::WALL );
	contactSettlor.setupCollisionCategory();
	contactSettlor.setupContactCategory( callback, { Contact::Category::LIQUID } );
	contactSettlor.enableContactCallback( getName(), callback );
}