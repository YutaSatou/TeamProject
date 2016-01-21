#include "LiquidFunBodyDescCreator.h"
#include "cocos2d.h"
#include "LiquidFunMaterial.h"
#include "../Core/LiquidFunHelper.h"

using namespace cocos2d;

// ボディ設定記述子の生成
LiquidFunBodyDesc LiquidFunBodyDescCreator::createBodyDesc( Node* registerNode, const LiquidFunBodyType& bodyType )
{
	LiquidFunBodyDesc bodyDesc;
	
	bodyDesc.userData	= registerNode;
	bodyDesc.type		= bodyType;
	bodyDesc.position	= LiquidFunHelper::toMeter( registerNode->getPosition() );
	
	return bodyDesc;
}

// フィクスチャ設定記述子の生成
LiquidFunFixtureDesc LiquidFunBodyDescCreator::createFixtureDesc( const LiquidFunShape* shape, const LiquidFunMaterial& material )
{
	LiquidFunFixtureDesc fixtureDesc;
	
	fixtureDesc.shape		= shape;
	fixtureDesc.density		= material.density;
	fixtureDesc.restitution	= material.restitution;
	fixtureDesc.friction	= material.friction;
	
	return fixtureDesc;
}

// フィクスチャ設定記述子( 円形状 )の生成
LiquidFunFixtureDesc LiquidFunBodyDescCreator::createCircle( float radius, const LiquidFunMaterial& material, const Vec2& offset )
{
	LiquidFunCircleShape* shape { new LiquidFunCircleShape() };
	
	shape->m_radius = LiquidFunHelper::toMeter( radius );
	shape->m_p		= LiquidFunHelper::toMeter( offset );
	
	return createFixtureDesc( shape, material );
}

// フィクスチャ設定記述子( 箱形状 )の生成
LiquidFunFixtureDesc LiquidFunBodyDescCreator::createBox( const cocos2d::Size& size, const LiquidFunMaterial& material, const Vec2& offset )
{
	const LiquidFunVec2	halfSize	{ LiquidFunHelper::toMeter( size.width ) / 2.0f, LiquidFunHelper::toMeter( size.height ) / 2.0f };
	const LiquidFunVec2	offsetM		{ LiquidFunHelper::toMeter( offset ) };
	
	LiquidFunPolygonShape* shape { new LiquidFunPolygonShape() };
	
	shape->SetAsBox( halfSize.x, halfSize.y, offsetM, 0.0f );
	
	return createFixtureDesc( shape, material );
}

// フィクスチャ設定記述子( 線形状 )の生成
LiquidFunFixtureDesc LiquidFunBodyDescCreator::createSegment( const Vec2& start, const Vec2& end, float lineWidth, const LiquidFunMaterial& material, const Vec2& offset )
{
	static const auto getCenter = []( float start, float end, float offset )
	{
		return LiquidFunHelper::toMeter( ( start + end ) / 2.0f ) - LiquidFunHelper::toMeter( offset );
	};
	
	const float width		{ LiquidFunHelper::toMeter( std::abs( start.distance( end ) ) ) };
	const float height		{ LiquidFunHelper::toMeter( lineWidth ) };
	const float centerX		{ getCenter( start.x, end.x, offset.x ) };
	const float centerY		{ getCenter( start.y, end.y, offset.y ) };
	const float angle		{ std::atan2( ( start.y - end.y ), ( start.x - end.x ) ) };
	
	LiquidFunPolygonShape* shape { new LiquidFunPolygonShape() };
	
	shape->SetAsBox( width / 2.0f, height / 2.0f, LiquidFunVec2( centerX, centerY ), angle );
	
	return createFixtureDesc( shape, material );
}

// フィクスチャ設定記述子( エッジ線形状 )の生成
LiquidFunFixtureDesc LiquidFunBodyDescCreator::createEdgeSegment( const Vec2& start, const Vec2& end, const LiquidFunMaterial& material )
{
	LiquidFunEdgeShape* shape { new LiquidFunEdgeShape() };
	
	shape->Set( LiquidFunHelper::toMeter( start ), LiquidFunHelper::toMeter( end ) );
	
	return createFixtureDesc( shape, material );
}

// フィクスチャ設定記述子( 多角形形状 )の生成
LiquidFunFixtureDesc LiquidFunBodyDescCreator::createPolygon( const Vec2* points, int pointCount, const LiquidFunMaterial& material )
{
	LiquidFunVec2* vertices { new LiquidFunVec2[ pointCount ] };
	
	for ( int i = 0; i < pointCount; ++i )
	{
		vertices[ i ] = LiquidFunHelper::toMeter( points[ i ] );
	}
	
	LiquidFunPolygonShape* shape { new LiquidFunPolygonShape() };
	
	shape->Set( vertices, pointCount );
	
	CC_SAFE_DELETE( vertices );
	
	return createFixtureDesc( shape, material );
}