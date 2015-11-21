#include "BrushBody.h"
#include "cocos2d.h"
#include "../../LiquidFun/LiquidFunUserAPI.h"

using namespace cocos2d;

// コンストラクタ
BrushBody::BrushBody()
	: mSegmentContainer()
	, mBodyDescCreator( makeUnique< LiquidFunBodyDescCreator >() )
{
	
}

// デストラクタ
BrushBody::~BrushBody()
{
	clear();
}

// 線の追加
void BrushBody::pushSegment( const Vec2& start, const Vec2& end, float lineWidth )
{
	// マテリアル( 密度, 反発係数, 摩擦係数 )を用意する。
	LiquidFunMaterial material( 0.0f, 0.0f, 0.8f );
	
	// 線のフィクスチャ設定記述子を生成する。
	LiquidFunFixtureDesc segment = mBodyDescCreator->createSegment( start, end, lineWidth, material );
	
	// 格納する。
	mSegmentContainer.push_back( std::move( segment ) );
}

// コンテナの解放
void BrushBody::clear()
{
	mSegmentContainer.clear();
}

// コンテナが空か否か
bool BrushBody::isEmpty() const
{
	return mSegmentContainer.empty();
}

// ボディの装着
void BrushBody::attachBody( Node* registerNode )
{
	// フィクスチャ装着用の空ボディを用意する。
	LiquidFunBodyDesc	bodyDesc	= mBodyDescCreator->createBodyDesc( registerNode, LiquidFunBodyType::b2_staticBody );
	LiquidFunBody*		parentBody	= LiquidFunBodySettlor::attachEmptyBody( bodyDesc );
	
	// コンテナを巡回してフィクスチャを装着する。
	each( [ &parentBody ]( LiquidFunFixtureDesc& desc ) { LiquidFunBodySettlor::attachFixture( parentBody, desc ); } );
}

// コンテナの巡回
void BrushBody::each( std::function< void( LiquidFunFixtureDesc& ) > func )
{
	std::for_each( mSegmentContainer.begin(), mSegmentContainer.end(), [ & ]( LiquidFunFixtureDesc& desc )
	{
		func( desc );
	} );
}