#include "GameTitleLayer.h"
#include "../GameStageSelect/StageSelectLayer.h"
#include "../../Utility/Assistant/SceneCreator.h"
#include "TitleSpriteRenderer.h"

using namespace cocos2d;

bool GameTitleLayer::init()
{
	if ( !LayerColor::initWithColor( Color4B::BLACK ) )
	{
		return false;
	}
    
    touchListener();
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    //背景
    Sprite* backGraund = TitleSpriteRenderer::createSprite( "Title/BG.png", Vec2( visibleSize.width / 2.0f + origin.x,
                                                                                          visibleSize.height / 2.0f + origin.y ) );
    //タイトルロゴ
    Sprite* titleLogo = TitleSpriteRenderer::createSprite( "Title/sprite_menu.png" , Vec2( visibleSize.width / 2.0f + origin.x,
                                                                                           visibleSize.height / 1.5f + origin.y ) );
    
    //TouchStartロゴ
    Sprite* touchLogo = TitleSpriteRenderer::createSprite( "Title/image_menu_normal.png", Vec2( visibleSize.width / 2.0f + origin.x,
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
        Director::getInstance()->replaceScene(TransitionFade::create(1.0f, SceneCreator::createScene( StageSelectLayer::create() ), Color3B::WHITE));
        log("TouchEnded");
    };
    
    //イベントリスナーを登録
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}