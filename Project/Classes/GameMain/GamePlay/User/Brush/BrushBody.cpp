#include "BrushBody.h"
#include "cocos2d.h"

using namespace cocos2d;

// コンストラクタ
BrushBody::BrushBody()
{
	
}

// デストラクタ
BrushBody::~BrushBody()
{
	clear();
}

// シェイプの追加
void BrushBody::pushShape( const Vec2& start, const Vec2& end, float lineSize )
{
	// 物理特性( 密度, 反発係数, 摩擦係数 )を用意する。
	PhysicsMaterial material;
	material.density		= 0.3f;
	material.restitution	= 0.8f;
	material.friction		= 0.6f;
	
	// 線のシェイプを生成する。
	PhysicsShape* edgeSegment = PhysicsShapeEdgeSegment::create( start, end, material, lineSize );
	
	// 解放されないように参照カウンタを加算して格納する。
	CC_SAFE_RETAIN( edgeSegment );
	mShapeContainer.push_back( edgeSegment );
}

// コンテナの解放
void BrushBody::clear()
{
	// 各要素の参照カウンタを減算する。
	each( []( PhysicsShape* shape ) { CC_SAFE_RELEASE_NULL( shape ); } );
	
	// コンテナをクリアする。
	mShapeContainer.clear();
}

// コンテナが空か否か
bool BrushBody::isEmpty() const
{
	return mShapeContainer.empty();
}

// ボディの生成
PhysicsBody* BrushBody::createBody()
{
	// シェイプ装着用の空ボディを用意する。
	PhysicsBody* parentBody = PhysicsBody::create();
	parentBody->setDynamic( false );
	
	// コンテナを巡回してシェイプを装着する。
	each( [ &parentBody ]( PhysicsShape* shape ) { parentBody->addShape( shape ); } );
	
	return parentBody;
}

// コンテナの巡回
void BrushBody::each( std::function< void( PhysicsShape* ) > func )
{
	std::for_each( mShapeContainer.begin(), mShapeContainer.end(), [ & ]( PhysicsShape* shape )
	{
		func( shape );
	} );
}