#include "GameLayer.h"
#include "../Object/Wall/WallManager.h"
#include "../Object/Player/PlayerManager.h"
#include "../Object/Enemy/EnemyManager.h"
#include "../User/Brush/Brush.h"
#include "../Object/Data/ObjectData.h"
#include "../Object/Stage/StageCreator.h"
#include "Utility/Assistant/Scene/SceneCreator.h"
#include "Utility/Assistant/Scene/SceneChanger.h"
#include "GameMain/GameResult/GameResultLayer.h"

using namespace cocos2d;

// コンストラクタ
GameLayer::GameLayer()
	: mWallManager( nullptr )
	, mPlayerManager( nullptr )
	, mEnemyManager( nullptr )
	, mUserBrush( nullptr )
{
	
}

// 初期化
bool GameLayer::init()
{
	if ( !Layer::init() )
	{
		return false;
	}
	
	mWallManager	= WallManager::create( *this );
	mPlayerManager	= PlayerManager::create();
	mEnemyManager	= EnemyManager::create();
	mUserBrush		= Brush::create( *this );
	
	addChild( mWallManager );
	addChild( mPlayerManager );
	addChild( mEnemyManager );
	addChild( mUserBrush );
	
	return true;
}

// インスタンスの生成
GameLayer* GameLayer::create( const std::string& plistFilePath )
{
	GameLayer* inst = new GameLayer();
	
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
	Scene* scene		= SceneCreator::createScene( GameResultLayer::create() );
	Scene* nextScene	= TransitionRotoZoom::create( 0.8f, scene );
	SceneChanger::switchScene( nextScene );
}

// ステージの初期化
void GameLayer::initStage( const std::string& plistFilePath )
{
	StageCreator stageCreator;
	stageCreator.addListener( [ this ]( SharedPtr< ObjectData > data ) { mPlayerManager->onDataLoaded( data ); }	);
	stageCreator.addListener( [ this ]( SharedPtr< ObjectData > data ) { mEnemyManager->onDataLoaded( data ); }		);
	stageCreator.createStage( plistFilePath );
}