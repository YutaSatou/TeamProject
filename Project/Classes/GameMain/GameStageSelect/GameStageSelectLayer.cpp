#include "GameStageSelectLayer.h"
#include "StageSelectLayOut.h"
#include "../../Utility/Audio/ADX2Player.h"
#include "ui/CocosGUI.h"

using namespace cocos2d;
using namespace ui;

#define VISIBLESIZE Director::getInstance()->getVisibleSize()
#define ORIGINSIZE Director::getInstance()->getVisibleOrigin()

GameStageSelectLayer::GameStageSelectLayer(){
}

GameStageSelectLayer::~GameStageSelectLayer(){
}

bool GameStageSelectLayer::init()
{
    if ( !LayerColor::initWithColor( Color4B::BLACK ) )
    {
        return false;
    }
    
    drawBackGraund();
    drawStageSelectLogo();
    
    PageView* page = StageSelectLayOut::createPage( 3 );
    addChild( page );
    
    
    scheduleUpdate();
    
    return true;
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
    Sprite* sprite = Sprite::create( "Texture/Debug/backgraund.png" );
    sprite->setPosition( Vec2( VISIBLESIZE.width / 2.0f, VISIBLESIZE.height / 2.0f ) );
    sprite->setScale( 2.0f, 2.0f );
    addChild( sprite );
}

void GameStageSelectLayer::drawStageSelectLogo(){
    
    //Logo
    Sprite* stageimage = Sprite::create( "Texture/Debug/image_menu_normal.png" );
    stageimage->setPosition( Vec2( VISIBLESIZE.width / 2.0f, VISIBLESIZE.height / 1.1f ) );
    stageimage->setScale( 2.0f, 2.0f );
    addChild( stageimage );
}