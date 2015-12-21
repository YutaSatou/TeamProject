#include "StageTerrain.h"
#include "../../LiquidFun/LiquidFunUserAPI.h"
#include "../Data/ObjectData.h"
#include "../Common/LiquidFunBodyDeleter.h"
#include "Utility/Template/EnumHash.h"

using namespace cocos2d;

namespace
{
	using DescCreateFunc			= std::function< LiquidFunFixtureDesc( LiquidFunBodyDescCreator&, const Size&, const LiquidFunMaterial& ) >;
	using DescCreateFuncContainer	= std::unordered_map< StageTerrainType, DescCreateFunc, EnumHash >;
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
	static DescCreateFuncContainer descCreateFuncContainer
	{
		{
			StageTerrainType::BOX,		[]( LiquidFunBodyDescCreator& creator, const Size& size, const LiquidFunMaterial& material )
			{
				return creator.createBox( size, material );
			}
		},
		{
			StageTerrainType::TRIANGLE,	[]( LiquidFunBodyDescCreator& creator, const Size& size, const LiquidFunMaterial& material )
			{
				const float	halfW		= size.width	/ 2.0f;
				const float	halfH		= size.height	/ 2.0f;
				const Vec2	vertices[]	= { { -halfW, -halfH }, { -halfW, halfH }, { halfW, -halfH } };
				
				return creator.createPolygon( vertices, 3, material );
			}
		},
		{
			StageTerrainType::CIRCLE,	[]( LiquidFunBodyDescCreator& creator, const Size& size, const LiquidFunMaterial& material )
			{
				return creator.createCircle( size.width / 2.0f, material );
			}
		},
	};
	
	// ボディの生成に必要な設定記述子を生成する。
	LiquidFunBodyDescCreator	bodyDescCreator;
	LiquidFunBodyDesc			bodyDesc	= bodyDescCreator.createBodyDesc( this, LiquidFunBodyType::b2_staticBody );
	LiquidFunFixtureDesc		fixtureDesc	= descCreateFuncContainer[ terrainType ]( bodyDescCreator, getContentSize(), mObjectData->material );
	
	// ボディを装着する。
	LiquidFunBody* body = LiquidFunBodySettlor::attachBody( bodyDesc, fixtureDesc );
	
	// ノードが削除されるタイミングでボディも削除されるように設定する。
	addChild( LiquidFunBodyDeleter::create( body ) );
}