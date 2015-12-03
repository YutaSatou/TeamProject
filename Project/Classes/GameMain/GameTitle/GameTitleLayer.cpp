#include "GameTitleLayer.h"
#include "ui/CocosGUI.h"
#include "../../GameMain/GameStageSelect/GameStageSelectLayer.h"
#include "../../Utility/Assistant/SceneChanger.h"

using namespace cocos2d;
using namespace ui;

namespace  {
    
    Size SCREEN_SIZE;
    Vec2 ORIGIN_SIZE;
}


GameTitleLayer::GameTitleLayer(){
    
}

GameTitleLayer::~GameTitleLayer(){
    //ADX2Player::getInstance().stop( mBgm );
    //mManager->release();
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
    
    /*mManager = ParticleManager::createPool( ParticleType::SPLASH, 100 );
    mManager->retain();*/
    
    //mManager->playParicle( this, Vec2( SCREEN_SIZE.width / 2, SCREEN_SIZE.height / 2 ) ):

    mBgm = ADX2Player::getInstance().play( 0 );
    
    touchListener();
	
	scheduleUpdate();
	
	return true;
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
    Sprite* backGraund = Sprite::create( "Texture/GameTitle/BackScreen.png" );
    backGraund->setPosition( Vec2( SCREEN_SIZE.width / 2.0f, SCREEN_SIZE.height / 2.0f ) );

    addChild(backGraund);
}

void GameTitleLayer::drawTitle(){

    //タイトルロゴ
    Sprite* titleLogo = Sprite::create( "Texture/GameTitle/Title.png" );
    titleLogo->setPosition( Vec2( SCREEN_SIZE.width / 2.0f, SCREEN_SIZE.height / 1.2f ) );
    
    addChild(titleLogo);
}

void GameTitleLayer::drawTouch(){

    //TouchStartロゴ
    Button* touchLogo = Button::create( "Texture/GameTitle/Title_Button.png" );
    touchLogo->setTitleText( "タップスタート" );
    touchLogo->setTitleFontName( "Font/RiiPopkkR.otf" );
    touchLogo->setTitleFontSize( 68 );
    touchLogo->setTitleColor( Color3B::BLACK );
    touchLogo->setEnabled( false );
    touchLogo->setPosition( Vec2( 359, 307 ) );
    
    //TouchStartアニメーション
    FadeIn* startTScale = FadeIn::create( 1.0f );
    FadeOut* endTScale = FadeOut::create( 1.0f );
    touchLogo->runAction( RepeatForever::create( Sequence::create( endTScale, startTScale, NULL ) ) );
    
    addChild( touchLogo );
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
        ADX2Player::getInstance().play( 6 );
        SceneChanger::switchScene( GameStageSelectLayer::create() );
    };
    
    //イベントリスナーを登録
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority( listener, this );
}