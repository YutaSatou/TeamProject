#include "GameTitleLayer.h"
#include "../GameStageSelect/GameStageSelectLayer.h"
#include "../../Utility/Assistant/SceneSwitcher.h"
#include "TitleSpriteRenderer.h"
#include "../../Utility/Particle/EffectManager.h"

using namespace cocos2d;

namespace  {
    
    Size SCREEN_SIZE;
    Vec2 ORIGIN_SIZE;
}


GameTitleLayer::GameTitleLayer(){
    
}

GameTitleLayer::~GameTitleLayer(){
    
    mPlayer->release();
}

bool GameTitleLayer::init()
{
	if ( !LayerColor::initWithColor( Color4B::BLACK ) )
	{
		return false;
	}
    
    SCREEN_SIZE = Director::getInstance()->getWinSize();
    ORIGIN_SIZE = Director::getInstance()->getVisibleOrigin();
    
    mPlayer = ADX2Player::create( "Basic.acb", "Basic.awb" );
    mPlayer->play( 0, SoundType::BGM);
    mPlayer->retain();
    
    touchListener();
    
    //背景
    Sprite* backGraund = TitleSpriteRenderer::createSprite( "Texture/Debug/backgraund.png", Vec2( SCREEN_SIZE.width / 2.0f /*+ ORIGIN_SIZE.x*/,
                                                                                                  SCREEN_SIZE.height / 2.0f /*+ ORIGIN_SIZE.y */) );
    
    //タイトルロゴ
    Sprite* titleLogo = TitleSpriteRenderer::createSprite( "Texture/Debug/title.png", Vec2( SCREEN_SIZE.width / 2.0f /*+ ORIGIN_SIZE.x*/,
                                                                                                   SCREEN_SIZE.height / 2.0f /*+ ORIGIN_SIZE.y*/ ) );
    
    //TouchStartロゴ
    /*Sprite* touchLogo = TitleSpriteRenderer::createSprite( "Texture/Debug/image_menu_normal.png", Vec2( SCREEN_SIZE.width / 2.0f + ORIGIN_SIZE.x,
                                                                                                        SCREEN_SIZE.height / 3.0f + ORIGIN_SIZE.y ) );*/

    
    addChild(backGraund);
    addChild(titleLogo);
    //addChild(touchLogo);
	
	scheduleUpdate();
	
	return true;
}

void GameTitleLayer::update( float deltaTime )
{
    
}

GameTitleLayer* GameTitleLayer::create()
{
	GameTitleLayer* inst = new GameTitleLayer();
	
	if ( inst && inst->init() )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

void GameTitleLayer::touchListener(){
    
    //イベントリスナーを作成
    EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
    
    //タッチ開始
    listener->onTouchBegan = [&](Touch* touch, Event* event){
        return true;
    };
    
    //タッチ中
    listener->onTouchMoved = [](Touch* touch, Event* event){
        
    };
    
    //タッチ終了
    listener->onTouchEnded = [](Touch* touch, Event* event){
        
        SceneSwitcher::change( SceneType::STAGE_SELECT );
    };
    
    //イベントリスナーを登録
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority( listener, this );
}