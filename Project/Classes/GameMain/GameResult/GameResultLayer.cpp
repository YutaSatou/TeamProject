#include "GameResultLayer.h"
#include "Utility/Assistant/Scene/SceneChanger.h"
#include "../GameStageSelect/GameStageSelectLayer.h"
#include "ResultManager.h"
#include "ResultEvaluation.h"

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
    
    touchListener();
    
    drawSprite( "Texture/GameResult/Result_ Background.png", Vec2( SCREEN_SIZE.width / 2, SCREEN_SIZE.height / 2 ) );
    
    mResultManager = ResultManager::create();
    addChild( mResultManager );
	
    scheduleUpdate();
	
	return true;
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
        mResultManager->touchAction();
    };
    
    //イベントリスナーを登録
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority( listener, this );
}