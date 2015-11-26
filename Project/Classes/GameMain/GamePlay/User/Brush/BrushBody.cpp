#include "BrushBody.h"
#include "cocos2d.h"
#include "../../LiquidFun/LiquidFunUserAPI.h"
#include "../../Object/Common/LiquidFunBodyDeleter.h"

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

// 線形状のフィクスチャ設定記述子の追加
void BrushBody::pushSegment( const Vec2& start, const Vec2& end, float lineWidth )
{
	// マテリアル( 密度, 反発係数, 摩擦係数 )を用意する。
	LiquidFunMaterial material( 0.0f, 0.0f, 0.8f );
	
	// 線形状のフィクスチャ設定記述子を生成し、格納する。
	LiquidFunFixtureDesc segment = mBodyDescCreator->createSegment( start, end, lineWidth, material );
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
	LiquidFunBody*		emptyBody	= LiquidFunBodySettlor::attachEmptyBody( bodyDesc );
	
	// コンテナを巡回して、フィクスチャの生成と装着を行う。
	each( [ &emptyBody ]( LiquidFunFixtureDesc& desc ) { LiquidFunBodySettlor::attachFixture( emptyBody, desc ); } );
	
	// ノードが削除されるタイミングでボディも削除されるように設定する。
	registerNode->addChild( LiquidFunBodyDeleter::create( emptyBody ) );
}

// コンテナの巡回
void BrushBody::each( std::function< void( LiquidFunFixtureDesc& ) > func )
{
	std::for_each( mSegmentContainer.begin(), mSegmentContainer.end(), [ & ]( LiquidFunFixtureDesc& desc )
	{
		func( desc );
	} );
}