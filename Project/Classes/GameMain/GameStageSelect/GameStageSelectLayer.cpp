#include "GameStageSelectLayer.h"
#include "StageSelectLayOut.h"
#include "../../Utility/Audio/ADX2Player.h"
#include "ui/CocosGUI.h"

using namespace cocos2d;
using namespace ui;

namespace  {
    
    Size SCREEN_SIZE = Director::getInstance()->getVisibleSize();
    Vec2 ORIGIN_SIZE = Director::getInstance()->getVisibleOrigin();
}

GameStageSelectLayer::GameStageSelectLayer(){
    
}

GameStageSelectLayer::~GameStageSelectLayer(){
    
    mPlayer->release();
}

bool GameStageSelectLayer::init()
{
    if ( !LayerColor::initWithColor( Color4B::BLACK ) )
    {
        return false;
    }
    
    
    SCREEN_SIZE = Director::getInstance()->getVisibleSize();
    ORIGIN_SIZE = Director::getInstance()->getVisibleOrigin();
    
    //仮
    auto a  =CallFunc::create( [this](){
    
        mPlayer = ADX2Player::create( "Basic.acb", "Basic.awb" );
        mPlayer->play( 3, SoundType::BGM);
        mPlayer->retain();
    } );
    auto b = DelayTime::create( 1.0f );
    auto s = Sequence::create( b, a, nullptr );
    
    runAction( s );
    //ここまで
    
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
    sprite->setPosition( Vec2( SCREEN_SIZE.width / 2.0f, SCREEN_SIZE.height / 2.0f ) );
    sprite->setScale( 2.0f, 2.0f );
    addChild( sprite );
}

void GameStageSelectLayer::drawStageSelectLogo(){
    
    //Logo
    Sprite* stageimage = Sprite::create( "Texture/Debug/stageselectlogo.png" );
    stageimage->setPosition( Vec2( SCREEN_SIZE.width / 2.0f, SCREEN_SIZE.height / 1.1f ) );
    stageimage->setScale( 2.0f, 2.0f );
    addChild( stageimage );
}