#include "GameTitleLayer.h"
#include "../GameStageSelect/GameStageSelectLayer.h"
#include "../../Utility/Assistant/SceneSwitcher.h"
#include "TitleSpriteRenderer.h"

using namespace cocos2d;

GameTitleLayer::GameTitleLayer(){
}

GameTitleLayer::~GameTitleLayer(){
    
    //mPlayer->release();
}

bool GameTitleLayer::init()
{
	if ( !LayerColor::initWithColor( Color4B::BLACK ) )
	{
		return false;
	}
    
    //mPlayer = ADX2Player::create( "Basic.acb", "Basic.awb" );
    //mPlayer->play( 0, SoundType::BGM);
    //mPlayer->retain();
    
    touchListener();
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    //背景
    Sprite* backGraund = TitleSpriteRenderer::createSprite( "Texture/Debug/backgraund.png", Vec2( visibleSize.width / 2.0f + origin.x, visibleSize.height / 2.0f + origin.y ) );
    //タイトルロゴ
    Sprite* titleLogo = TitleSpriteRenderer::createSprite( "Texture/Debug/sprite_menu.png" , Vec2( visibleSize.width / 2.0f + origin.x,
                                                                                           visibleSize.height / 1.2f + origin.y ) );
    
    //TouchStartロゴ
    Sprite* touchLogo = TitleSpriteRenderer::createSprite( "Texture/Debug/image_menu_normal.png", Vec2( visibleSize.width / 2.0f + origin.x,
                                                                                               visibleSize.height / 3.0f + origin.y ) );
    
    addChild(backGraund);
    addChild(titleLogo);
    addChild(touchLogo);
	
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
    listener->onTouchBegan = [](Touch* touch, Event* event){
        log("TouchBegan");
        return true;
    };
    
    //タッチ中
    listener->onTouchMoved = [](Touch* touch, Event* event){
        log("TouchMoved");
    };
    
    //タッチ終了
    listener->onTouchEnded = [](Touch* touch, Event* event){
        
        SceneSwitcher::change( SceneType::STAGE_SELECT );
        log("TouchEnded");
    };
    
    //イベントリスナーを登録
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}