#include "Goal.h"
#include "../../LiquidFun/LiquidFunUserAPI.h"
#include "../Common/LiquidFunBodyDeleter.h"
#include "Utility/FileIO/PlistReader.h"
#include "Utility/DataIO/TargetColor.h"

using namespace cocos2d;

// 初期化
bool Goal::init( const Vec2& position )
{
	if ( !Sprite::initWithFile( "Texture/GamePlay/Goal.png" ) )
	{
		return false;
	}
	
	TargetColor t;
	
	// 各パラメータを設定する。
	setAnchorPoint( Vec2::ANCHOR_MIDDLE );
	setColor( t.readColorTarget() );
	setOpacity( 190 );
	setPosition( position );
	
	// 物理構造の初期化を行う。
	initPhysics();
	
	// 旗を描画する。
	drawFlag();
	
	return true;
}

// インスタンスの生成
Goal* Goal::create( const Vec2& position )
{
	Goal* inst { new Goal() };
	
	if ( inst && inst->init( position ) )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

// 物理構造の初期化
void Goal::initPhysics()
{
	// ボディ管理用ノードを生成して、自身の子ノードとして追加する。
	Node* bodyManageNode { Node::create() };
	addChild( bodyManageNode );
	
	// ボディを生成する。
	createBody( bodyManageNode, "Plist/ShapeData/Goal_Left.plist" );
	createBody( bodyManageNode, "Plist/ShapeData/Goal_Right.plist" );
}

// ボディの生成
void Goal::createBody( Node* registerNode, const std::string& plistFilePath )
{
	// ボディの生成に必要な設定記述子を生成する。
	LiquidFunBodyDescCreator	bodyDescCreator;
	LiquidFunBodyDesc			bodyDesc { bodyDescCreator.createBodyDesc( registerNode, LiquidFunBodyType::b2_staticBody ) };
	
	// プロパティリストファイルを読み込む。
	PlistReader	reader;
	auto		valueMapContainer = reader.read( plistFilePath );
	
	for ( std::size_t i = 0; i < valueMapContainer.size() - 1; ++i )
	{
		const std::size_t next { i + 1 };
		
		// 読み込んだデータを格納する。
		float startX	{ valueMapContainer[ i		].at( "PositionX" ).asFloat() };
		float startY	{ valueMapContainer[ i		].at( "PositionY" ).asFloat() };
		float endX		{ valueMapContainer[ next	].at( "PositionX" ).asFloat() };
		float endY		{ valueMapContainer[ next	].at( "PositionY" ).asFloat() };
		
		// ボディを装着する。
		LiquidFunFixtureDesc	fixtureDesc	{ bodyDescCreator.createEdgeSegment( { startX, startY }, { endX, endY }, { 0.0f, 0.0f, 0.0f } ) };
		LiquidFunBody*			body		{ LiquidFunBodySettlor::attachBody( bodyDesc, fixtureDesc ) };
		
		// ノードが削除されるタイミングで、ボディも削除されるように設定する。
		registerNode->addChild( LiquidFunBodyDeleter::create( body ) );
	}
}

// 旗の描画
void Goal::drawFlag()
{
	Sprite* flag { Sprite::create( "Texture/GamePlay/Goal_Flag.png" ) };
	flag->setPosition( getPosition() );
	addChild( flag );
}