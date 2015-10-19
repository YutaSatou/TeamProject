#include "GameStageSelectLayer.h"
#include "StageSelectLayOut.h"
#include "../../Utility/Audio/ADX2Player.h"
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
    
    CC_SAFE_RELEASE( mPlayer );
}

bool GameStageSelectLayer::init()
{
    if ( !LayerColor::initWithColor( Color4B::BLACK ) )
    {
        return false;
    }
    
    
    SCREEN_SIZE = Director::getInstance()->getVisibleSize();
    ORIGIN_SIZE = Director::getInstance()->getVisibleOrigin();
    
    /*
    //仮
    mPlayer = ADX2Player::create( "Audio/StageSelect.acb" );
    mPlayer->play( 0, SoundType::BGM);
    //mPlayer = ADX2Player::create( "Audio/StageSelect.acb" );
    //mPlayer->play( 0, SoundType::BGM);
    //CC_SAFE_RETAIN( mPlayer );CC_SAFE_RETAIN( mPlayer );
    auto a  =CallFunc::create( [this](){
    
        //mPlayer = ADX2Player::create( "Audio/StageSelect.acb" );
        //mPlayer->play( 0, SoundType::BGM);
        //CC_SAFE_RETAIN( mPlayer );
    } );
    auto b = DelayTime::create( 1.0f );
    auto s = Sequence::create( b, a, nullptr );
     */
    
    //runAction( s );
    //ここまで
    
    drawBackGraund();
    drawStageSelectLogo();
    
    StageSelectLayOut* stage = StageSelectLayOut::create();
    
    addChild( stage );
    
    scheduleUpdate();
    
    return true;
}

void GameStageSelectLayer::onEnter()
{
    Layer::onEnter();
    mPlayer = ADX2Player::create( "Audio/StageSelect.acb" );
    mPlayer->play( 0, SoundType::BGM);
    CC_SAFE_RETAIN( mPlayer );
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