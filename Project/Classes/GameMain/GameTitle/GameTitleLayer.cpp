#include "GameTitleLayer.h"
#include "../../Utility/Assistant/SceneSwitcher.h"

using namespace cocos2d;

namespace  {
    
    Size SCREEN_SIZE;
    Vec2 ORIGIN_SIZE;
}


GameTitleLayer::GameTitleLayer(){
    
}

GameTitleLayer::~GameTitleLayer(){
    
    ADX2Player::getInstance().stop( mBgm );
}

bool GameTitleLayer::init()
{
	if ( !LayerColor::initWithColor( Color4B::BLACK ) )
	{
		return false;
	}
    
    SCREEN_SIZE = Director::getInstance()->getWinSize();
    ORIGIN_SIZE = Director::getInstance()->getVisibleOrigin();
    
    drawBackGraund();
    drawTitle();
    drawTouch();

    mBgm = ADX2Player::getInstance().play( 4 );
    
    touchListener();
	
	scheduleUpdate();
	
	return true;
}

void GameTitleLayer::update( float deltaTime )
{
    
}

void GameTitleLayer::onEnter()
{
    Layer::onEnter();
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

void GameTitleLayer::drawBackGraund(){

    //背景
    Sprite* backGraund = Sprite::create( "Texture/Debug/BackGround.png" );
    backGraund->setPosition( Vec2( SCREEN_SIZE.width / 2.0f, SCREEN_SIZE.height / 2.0f ) );

    addChild(backGraund);
}

void GameTitleLayer::drawTitle(){

    //タイトルロゴ
    Sprite* titleLogo = Sprite::create( "Texture/Debug/Title.png" );
    titleLogo->setPosition( Vec2( SCREEN_SIZE.width / 2.0f, SCREEN_SIZE.height / 1.2f ) );
    
    addChild(titleLogo);
}

void GameTitleLayer::drawTouch(){

    //TouchStartロゴ
    Sprite* touchLogo = Sprite::create( "Texture/Debug/TouchStart.png" );
    touchLogo->setPosition( Vec2( SCREEN_SIZE.width / 2.0f, SCREEN_SIZE.height / 4.0f ) );
    
    //TouchStartアニメーション
    FadeIn* startTScale = FadeIn::create( 1.0f );
    FadeOut* endTScale = FadeOut::create( 1.0f );
    touchLogo->runAction( RepeatForever::create( Sequence::create( endTScale, startTScale, NULL ) ) );
    
    addChild(touchLogo);
}

void GameTitleLayer::touchListener(){
    
    //イベントリスナーを作成
    EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
    
    //タッチ開始
    listener->onTouchBegan = [ = ](Touch* touch, Event* event){
        return true;
    };
    
    //タッチ終了
    listener->onTouchEnded = [ = ](Touch* touch, Event* event){
        ADX2Player::getInstance().play( 1 );
        SceneSwitcher::change( SceneType::STAGE_SELECT );
    };
    
    //イベントリスナーを登録
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority( listener, this );
}