#include "BrushTrail.h"
#include "../Canvas/Canvas.h"

using namespace cocos2d;

// コンストラクタ
BrushTrail::BrushTrail()
	: mBrushBody( BrushBody() )
	, mPreviousTouchPoint( Vec2::ZERO )
	, mShapeOffset( Vec2::ZERO )
	, mCanvas( nullptr )
{
	
}

// 初期化
bool BrushTrail::init()
{
	if ( !Node::init() )
	{
		return false;
	}
	
	mCanvas = Canvas::create();
	addChild( mCanvas );
	
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
	
	// 各座標を初期化する。
	mPreviousTouchPoint	= touch->getLocation();
	mShapeOffset		= Vec2::ZERO;
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
		mBrushBody.pushShape( start, end, 4.0f );
		
		// 軌跡の描画
		drawTrail( touch, distance );
		
		// 前回のタッチ座標を現在のタッチ座標で更新する。
		mPreviousTouchPoint = touchPoint;
		
		// オフセットに移動量を加算する。
		mShapeOffset += delta;
	}
}

// ブラシ描き終わり
void BrushTrail::writeEnd( Touch* touch, Node* parentNode )
{
	// タッチ開始座標を取得する。
	Point touchStartPoint = touch->getStartLocation();
	
	// 空のスプライトを用意してボディを装着する。
	Sprite*			drawer	= Sprite::create();
	PhysicsBody*	body	= mBrushBody.createBody();
	
	// 各パラメータを設定して親ノードに追加する。
	drawer->setAnchorPoint( Vec2::ANCHOR_MIDDLE );
	drawer->setPosition( touchStartPoint );
	drawer->setPhysicsBody( body );
	parentNode->addChild( drawer );
}

// 軌跡の描画
void BrushTrail::drawTrail( Touch* touch, float distance )
{
	// 後でシェーダに変更します。
	// 「良い子は真似しちゃダメ」なソースコードが含まれています。
	mCanvas->renderingBegin();
	{
		Vec2	touchPoint	= touch->getLocation();
		Vec2	delta		= mPreviousTouchPoint - touchPoint;
		
		for ( float i = 0.0f; i < distance; i += 1.0f )
		{
			Sprite* trail = Sprite::create();
			trail->setTextureRect( Rect( 0.0f, 0.0f, 6.0f, 6.0f ) );
			trail->setColor( Color3B::GREEN );
			trail->setPosition( delta * i / distance + touchPoint );
			
			mCanvas->addRenderingTarget( trail );
		}
	}
	mCanvas->renderingEnd();
}