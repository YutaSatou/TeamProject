#include "BrushTrail.h"

using namespace cocos2d;

// コンストラクタ
BrushTrail::BrushTrail()
	: mBrushBody( BrushBody() )
	, mPreviousTouchPoint( Vec2::ZERO )
	, mShapeOffset( Vec2::ZERO )
	, mDummySprite( nullptr )
{
	
}

// 初期化
bool BrushTrail::init()
{
	if ( !Node::init() )
	{
		return false;
	}
	
	return true;
}

// インスタンスの生成
BrushTrail* BrushTrail::create()
{
	BrushTrail* inst = new BrushTrail();
	
	if ( inst && inst->init() )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

// ブラシ描き始め
void BrushTrail::writeBegin( Touch* touch )
{
	// コンテナを解放する。
	mBrushBody.clear();
	
	// メンバ変数を初期化する。
	mPreviousTouchPoint	= touch->getLocation();
	mShapeOffset		= Vec2::ZERO;
	
	// Debug.
	mDummySprite = Sprite::create();
	mDummySprite->setAnchorPoint( Vec2::ANCHOR_MIDDLE );
	mDummySprite->setPosition( mPreviousTouchPoint );
	addChild( mDummySprite );
}

// ブラシ描き途中
void BrushTrail::writeMove( Touch* touch )
{
	// タッチ座標を取得する。
	Vec2 touchPoint = touch->getLocation();
	
	// 現在のタッチ座標と前回のタッチ座標から、移動量と2点間の距離を算出する。
	Vec2	delta		= touchPoint - mPreviousTouchPoint;
	float	distance	= touchPoint.distance( mPreviousTouchPoint );
	
	if ( distance > 10.0f )
	{
		// 始点と終点を算出する。
		Vec2	start	= mShapeOffset;
		Vec2	end		= delta + mShapeOffset;
		
		// 線のシェイプを追加する。
		mBrushBody.pushShape( start, end, 4 );
		
		// 前回のタッチ座標を現在のタッチ座標で更新する。
		mPreviousTouchPoint = touchPoint;
		
		// オフセットに移動量を加算する。
		mShapeOffset += delta;
	}
}

// ブラシ描き終わり
void BrushTrail::writeEnd( Touch* touch )
{
	// Debug.
	PhysicsBody* body = mBrushBody.createBody();
	mDummySprite->setPhysicsBody( body );
}