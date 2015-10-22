#include "GameTitleLayer.h"
#include "../../Utility/Assistant/SceneSwitcher.h"
#include "../../Utility/Particle/EffectManager.h"

using namespace cocos2d;

namespace  {
    
    Size SCREEN_SIZE;
    Vec2 ORIGIN_SIZE;
}


GameTitleLayer::GameTitleLayer(){
    
}

GameTitleLayer::~GameTitleLayer(){
    CC_SAFE_RELEASE( mPlayer );
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
    
    mPlayer = ADX2Player::create( "Audio/Title.acb" );
    mPlayer->play( 0, SoundType::BGM);
    CC_SAFE_RETAIN( mPlayer );
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
    Sprite* backGraund = Sprite::create( "Texture/Debug/backgraund.png" );
    backGraund->setPosition( Vec2( SCREEN_SIZE.width / 2.0f, SCREEN_SIZE.height / 2.0f ) );

    addChild(backGraund);
}

void GameTitleLayer::drawTitle(){

    //タイトルロゴ
    Sprite* titleLogo = Sprite::create( "Texture/Debug/title.png" );
    titleLogo->setPosition( Vec2( SCREEN_SIZE.width / 2.0f, SCREEN_SIZE.height / 1.2f ) );
    
    addChild(titleLogo);
}

void GameTitleLayer::drawTouch(){

    //TouchStartロゴ
    Sprite* touchLogo = Sprite::create( "Texture/Debug/TocuhStart.png" );
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
        mPlayer->play( 1, SoundType::SE);
        SceneSwitcher::change( SceneType::STAGE_SELECT );
    };
    
    //イベントリスナーを登録
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority( listener, this );
}