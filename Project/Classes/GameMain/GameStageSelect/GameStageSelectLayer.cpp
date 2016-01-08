#include "GameStageSelectLayer.h"
#include "../../Utility/Audio/ADX2Player.h"
#include "StageSelectPage.h"
#include "PageCursor.h"
// #include "StageSelectOption.h"
#include "ui/CocosGUI.h"

using namespace cocos2d;
using namespace ui;

namespace  {
    
    Size SCREEN_SIZE;
    Vec2 ORIGIN_SIZE;
}

GameStageSelectLayer::GameStageSelectLayer(){
    
}

GameStageSelectLayer::~GameStageSelectLayer(){
    //ADX2Player::getInstance().stop( mBgm );
}

bool GameStageSelectLayer::init()
{
    if ( !LayerColor::initWithColor( Color4B::BLACK ) )
    {
        return false;
    }
    
    SCREEN_SIZE = Director::getInstance()->getVisibleSize();
    ORIGIN_SIZE = Director::getInstance()->getVisibleOrigin();
    
    drawBackGraund();
    
    //mBgm = ADX2Player::getInstance().play( 0 );
    
    StageSelectPage* page = StageSelectPage::create( 3 );
    
    //StageSelectOption* sso = StageSelectOption::create();
    
    addChild( page );
    //addChild( sso );
    
    scheduleUpdate();
    
    return true;
}

void GameStageSelectLayer::onEnter()
{
    Layer::onEnter();
}

void GameStageSelectLayer::update( float deltaTime )
{
}

GameStageSelectLayer* GameStageSelectLayer::create()
{
    GameStageSelectLayer* inst = new GameStageSelectLayer();
    
    if ( inst && inst->init() )
    {
        inst->autorelease();
        return inst;
    }
    
    CC_SAFE_DELETE( inst );
    return nullptr;
}

void GameStageSelectLayer::drawBackGraund(){
    
    //背景
    Sprite* sprite = Sprite::create( "Texture/GameTitle/BackScreen.png" );
    sprite->setPosition( Vec2( SCREEN_SIZE.width / 2.0f, SCREEN_SIZE.height / 2.0f ) );
    addChild( sprite );
}