#include "BrushBody.h"
#include "cocos2d.h"
#include "../../LiquidFun/LiquidFunUserAPI.h"
#include "../../Object/Common/LiquidFunBodyDeleter.h"

using namespace cocos2d;

// コンストラクタ
BrushBody::BrushBody()
	: mFixtureDescContainer()
	, mBodyDescCreator( std::make_shared< LiquidFunBodyDescCreator >() )
{
	
}

// デストラクタ
BrushBody::~BrushBody()
{
	clear();
}

// 線形状のフィクスチャ設定記述子の追加
void BrushBody::pushSegment( const Vec2& start, const Vec2& end, float lineWidth )
{
	LiquidFunFixtureDesc segment { mBodyDescCreator->createSegment( start, end, lineWidth, { 0.0f, 0.0f, 1.0f } ) };
	mFixtureDescContainer.push_back( segment );
}

// 線と線を結ぶフィクスチャ設定記述子の追加
void BrushBody::pushConnection( const Vec2& position, float lineWidth )
{
	LiquidFunFixtureDesc circle { mBodyDescCreator->createCircle( lineWidth / 2.0f, { 0.0f, 0.0f, 1.0f }, position ) };
	mFixtureDescContainer.push_back( circle );
}

// コンテナの解放
void BrushBody::clear()
{
	mFixtureDescContainer.clear();
}

// コンテナが空か否か
bool BrushBody::isEmpty() const
{
	return mFixtureDescContainer.empty();
}

// ボディの装着
void BrushBody::attachBody( Node* registerNode )
{
	// フィクスチャ装着用の空ボディを用意する。
	LiquidFunBodyDesc	bodyDesc	{ mBodyDescCreator->createBodyDesc( registerNode, LiquidFunBodyType::b2_staticBody ) };
	LiquidFunBody*		emptyBody	{ LiquidFunBodySettlor::attachEmptyBody( bodyDesc ) };
	
	// コンテナを巡回して、フィクスチャの生成と装着を行う。
	each( [ &emptyBody ]( LiquidFunFixtureDesc& desc ) { LiquidFunBodySettlor::attachFixture( emptyBody, desc ); } );
	
	// ノードが削除されるタイミングで、ボディも削除されるように設定する。
	registerNode->addChild( LiquidFunBodyDeleter::create( emptyBody ) );
}

// コンテナの巡回
void BrushBody::each( std::function< void( LiquidFunFixtureDesc& ) > func )
{
	std::for_each( mFixtureDescContainer.begin(), mFixtureDescContainer.end(), [ & ]( LiquidFunFixtureDesc& desc )
	{
		func( desc );
	} );
}