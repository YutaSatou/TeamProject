#include "GameResultLayer.h"
#include "Utility/Assistant/Scene/SceneChanger.h"
#include "../GameStageSelect/GameStageSelectLayer.h"
#include "ResultManager.h"
#include "ResultEvaluation.h"

//
#include "ResultSlime/ResultSlimeObject.h"
#include "../GamePlay/LiquidFun/LiquidFunCoreAPI.h"
#include "ResultWall/ResultWallManager.h"

#include "ResultTexturePhyiscs/ResultTexturePhysics.h"
#include "../GamePlay/Object/Contact/ContactListener.h"

#include "Utility/Assistant/Scene/SceneChanger.h"
#include "../../Utility/Assistant/Scene/SceneCreator.h"
#include "../GameStageSelect/GameStageSelectLayer.h"

using namespace cocos2d;

namespace  {
    
    Size SCREEN_SIZE;
    Vec2 ORIGIN_SIZE;
}

bool GameResultLayer::init()
{
	if ( !LayerColor::initWithColor( Color4B::BLACK ) )
	{
		return false;
	}
	
	SCREEN_SIZE = Director::getInstance()->getWinSize();
	ORIGIN_SIZE = Director::getInstance()->getVisibleOrigin();
	
	drawSprite( "Texture/GameResult/Result_ Background.png", Vec2( SCREEN_SIZE.width / 2, SCREEN_SIZE.height / 2 ) );
	
	//addChild( LiquidFunDebugDrawer::create() );
	addChild( ContactListener::create() );
	
	touchListener();
	
	mResultManager = ResultManager::create();
	addChild( mResultManager );
	
	ResultSlimeObject* r = ResultSlimeObject::create();
	addChild( r );
	
	ResultWallManager* wall = ResultWallManager::create();
	addChild( wall );
	
	ResultTexturePhysics* rs { ResultTexturePhysics::create( 30.0f, { 720 / 2, 900 } ) };
	addChild( rs );
	
	scheduleUpdate();
	
	mGamePlayGravity = LiquidFunWorldManager::getInstance().getGravity();
	
	LiquidFunWorldManager::getInstance().setGravity( { 0.0f, -16.8f } );
	
	
	return true;
}

void GameResultLayer::update( float deltaTime )
{
		Layer::update( deltaTime );
	LiquidFunWorldManager::getInstance().update();
}

GameResultLayer* GameResultLayer::create()
{
	GameResultLayer* inst = new GameResultLayer();
	
	if ( inst && inst->init() )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}


void GameResultLayer::drawSprite( const std::string& fileName, const Vec2& pos )
{
    //単純スプライトを表示させる
    Sprite* sprite = Sprite::create( fileName );
    sprite->setPosition( pos );
    this->addChild( sprite );
}

void GameResultLayer::touchListener(){
    
    //イベントリスナーを作成
    EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
    
    //タッチ開始
    listener->onTouchBegan = [ = ](Touch* touch, Event* event){
        return true;
    };
    
    //タッチ終了
    listener->onTouchEnded = [ = ](Touch* touch, Event* event){
        //mResultManager->touchAction();
		LiquidFunWorldManager::getInstance().setGravity( mGamePlayGravity );
		Scene* scene		{ SceneCreator::createScene( GameStageSelectLayer::create() ) };
		Scene* nextScene	{ TransitionRotoZoom::create( 0.8f, scene ) };
		SceneChanger::switchScene( nextScene );
    };
	
    //イベントリスナーを登録
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority( listener, this );
}