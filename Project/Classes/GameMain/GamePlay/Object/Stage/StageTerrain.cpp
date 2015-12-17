#include "StageTerrain.h"
#include "../../LiquidFun/LiquidFunUserAPI.h"
#include "../Data/ObjectData.h"
#include "../Common/LiquidFunBodyDeleter.h"
#include "Utility/Template/EnumHash.h"

using namespace cocos2d;

namespace
{
	using FixtureDescCreateFunc				= std::function< LiquidFunFixtureDesc( LiquidFunBodyDescCreator& creator ) >;
	using FixtureDescCreateFuncContainer	= std::unordered_map< StageTerrainType, FixtureDescCreateFunc, EnumHash >;
}

// コンストラクタ
StageTerrain::StageTerrain()
	: mObjectData( nullptr )
{
	
}

// 初期化
bool StageTerrain::init( SharedPtr< ObjectData > objectData, const StageTerrainType& terrainType )
{
	if ( !Sprite::initWithFile( objectData->textureName ) )
	{
		return false;
	}
	
	// オブジェクトデータを登録する。
	mObjectData = objectData;
	
	// 各パラメータを設定する。
	setColor( mObjectData->textureColor );
	setAnchorPoint( Vec2::ANCHOR_MIDDLE );
	setPosition( mObjectData->position );
	
	// 物理構造の初期化を行う。
	initPhysics( terrainType );
	
	return true;
}

// インスタンスの生成
StageTerrain* StageTerrain::create( SharedPtr< ObjectData > objectData, const StageTerrainType& terrainType )
{
	StageTerrain* inst = new StageTerrain();
	
	if ( inst && inst->init( objectData, terrainType ) )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

// 物理構造の初期化
void StageTerrain::initPhysics( const StageTerrainType& terrainType )
{
	static FixtureDescCreateFuncContainer fixtureDescCreateFuncContainer
	{
		{
			StageTerrainType::BOX, [ this ]( LiquidFunBodyDescCreator& creator )
			{
				return creator.createBox( getContentSize(), mObjectData->material );
			}
		},
		{
			StageTerrainType::TRIANGLE, [ this ]( LiquidFunBodyDescCreator& creator )
			{
				Vec2 vertices[] = { { 0.0f, 0.0f }, { 0.0f, getContentSize().height }, { getContentSize().width, 0.0f } };
				return creator.createPolygon( vertices, 3, mObjectData->material );
			}
		},
		{
			StageTerrainType::CIRCLE, [ this ]( LiquidFunBodyDescCreator& creator )
			{
				return creator.createCircle( getContentSize().width / 2.0f, mObjectData->material );
			}
		},
	};
	
	// ボディの生成に必要な設定記述子を生成する。
	LiquidFunBodyDescCreator	bodyDescCreator;
	LiquidFunBodyDesc			bodyDesc	= bodyDescCreator.createBodyDesc( this, LiquidFunBodyType::b2_staticBody );
	LiquidFunFixtureDesc		fixtureDesc	= fixtureDescCreateFuncContainer[ terrainType ]( bodyDescCreator );
	
	// ボディを装着する。
	LiquidFunBody* body = LiquidFunBodySettlor::attachBody( bodyDesc, fixtureDesc );
	addChild( LiquidFunBodyDeleter::create( body ) );
}