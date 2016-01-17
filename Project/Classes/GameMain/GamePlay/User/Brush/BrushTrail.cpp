#include "BrushTrail.h"
#include "../Canvas/Canvas.h"

using namespace cocos2d;

namespace
{
	const float DISTANCE_MIN	{ 20.0f };	//=> 線を引いたと認識する最低距離
	const float LINE_WIDTH		{  6.0f };	//=> 線の幅
}

// コンストラクタ
BrushTrail::BrushTrail()
	: mCanvas( nullptr )
	, mBrushBody()
	, mPreviousTouchPoint( Vec2::ZERO )
	, mTrailOffset( Vec2::ZERO )
{
	
}

// 初期化
bool BrushTrail::init()
{
	if ( !Node::init() )
	{
		return false;
	}
	
	// 自身の子ノードとして追加する。
	mCanvas = Canvas::create();
	addChild( mCanvas );
	
	return true;
}

// インスタンスの生成
BrushTrail* BrushTrail::create()
{
	BrushTrail* inst { new BrushTrail() };
	
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
	mTrailOffset		= Vec2::ZERO;
}

// ブラシ描き途中
void BrushTrail::writeMove( Touch* touch )
{
	// タッチ座標を取得する。
	const Vec2& touchPoint { touch->getLocation() };
	
	// 現在のタッチ座標と前回のタッチ座標から、移動量と2点間の距離を算出する。
	const Vec2&	delta		{ touchPoint - mPreviousTouchPoint };
	const float	distance	{ touchPoint.distance( mPreviousTouchPoint ) };
	
	if ( distance > DISTANCE_MIN )
	{
		// 線形状のフィクスチャ設定記述子を追加し、軌跡を描画する。
		mBrushBody.pushSegment( mTrailOffset, delta + mTrailOffset, LINE_WIDTH );
		drawTrail( mPreviousTouchPoint, touchPoint );
		
		// 各座標を更新する。
		mPreviousTouchPoint	 = touchPoint;
		mTrailOffset		+= delta;
	}
}

// ブラシ描き終わり
bool BrushTrail::writeEnd( Touch* touch, Node* parentNode )
{
	if ( mBrushBody.isEmpty() )
	{
		// コンテナが空の場合は、線を引いていないので終了する。
		return false;
	}
	
	// タッチ開始座標を取得する。
	const Point& touchStartPoint { touch->getStartLocation() };
	
	// 空のスプライトを生成する。
	Sprite* drawer { Sprite::create() };
	drawer->setAnchorPoint( Vec2::ANCHOR_MIDDLE );
	drawer->setPosition( touchStartPoint );
	
	// ボディを装着して、親ノードに追加する。
	mBrushBody.attachBody( drawer );
	parentNode->addChild( drawer );
	
	return true;
}

// 軌跡の描画
void BrushTrail::drawTrail( const Vec2& start, const Vec2& end )
{
	mCanvas->renderingBegin();
	
	DrawNode* drawNode { DrawNode::create() };
	drawNode->drawSegment( start, end, LINE_WIDTH, Color4F::WHITE );
	mCanvas->addRenderingTarget( drawNode );
	
	mCanvas->renderingEnd();
}