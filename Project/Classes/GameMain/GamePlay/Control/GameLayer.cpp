#include "GameLayer.h"
#include "../Object/Player/PlayerManager.h"
#include "../Object/Enemy/EnemyManager.h"
#include "../Object/Stage/StageTerrainManager.h"
#include "../Object/Wall/WallManager.h"
#include "../User/Brush/Brush.h"
#include "../Object/Data/ObjectData.h"
#include "../Object/Stage/StageCreator.h"
#include "GameMain/GameResult/GameResultLayer.h"
#include "Utility/Assistant/Scene/SceneCreator.h"
#include "Utility/Assistant/Scene/SceneChanger.h"

using namespace cocos2d;

// コンストラクタ
GameLayer::GameLayer()
	: mPlayerManager( nullptr )
	, mEnemyManager( nullptr )
	, mStageTerrainManager( nullptr )
{
	
}

// 初期化
bool GameLayer::init()
{
	if ( !Layer::init() )
	{
		return false;
	}
	
	mPlayerManager			= PlayerManager::create();
	mEnemyManager			= EnemyManager::create();
	mStageTerrainManager	= StageTerrainManager::create();
	
	addChild( mPlayerManager );
	addChild( mEnemyManager );
	addChild( mStageTerrainManager );
	addChild( WallManager::create( *this ) );
	addChild( Brush::create( *this ) );
	
	return true;
}

// インスタンスの生成
GameLayer* GameLayer::create( const std::string& plistFilePath )
{
	GameLayer* inst { new GameLayer() };
	
	if ( inst && inst->init() )
	{
		inst->autorelease();
		inst->initStage( plistFilePath );
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

// ゲーム開始
void GameLayer::gameStart()
{
	mPlayerManager->onGameStart();
}

// ゲーム終了
void GameLayer::gameEnd()
{
	Scene* scene		{ SceneCreator::createScene( GameResultLayer::create() ) };
	Scene* nextScene	{ TransitionRotoZoom::create( 0.8f, scene ) };
	SceneChanger::switchScene( nextScene );
}

// ステージの初期化
void GameLayer::initStage( const std::string& plistFilePath )
{
	StageCreator stageCreator;
	stageCreator.addListener( [ this ]( SharedPtr< ObjectData > data ) { mPlayerManager->onDataLoaded( data ); }		);
	stageCreator.addListener( [ this ]( SharedPtr< ObjectData > data ) { mEnemyManager->onDataLoaded( data ); }			);
	stageCreator.addListener( [ this ]( SharedPtr< ObjectData > data ) { mStageTerrainManager->onDataLoaded( data ); }	);
	stageCreator.createStage( plistFilePath );
}