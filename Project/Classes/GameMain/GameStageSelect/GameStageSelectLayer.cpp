#include "GameStageSelectLayer.h"
#include "StageSelectLayout.h"
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
    ADX2Player::getInstance().play( mBgm );
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
    drawStageSelectLogo();
    
    mBgm = ADX2Player::getInstance().play( 3 );
    
    StageSelectLayout* stage = StageSelectLayout::create();
    
    addChild( stage );
    
    Slider* cursor = Slider::create();
    //スライダーの背景
    cursor->loadBarTexture( "Texture/Debug/SliderBackGraund.png" );
    //スライダーのつまみ
    cursor->loadSlidBallTextures( "Texture/Debug/SliderBall.png" );
    //スライダー進歩状況
    cursor->loadProgressBarTexture( "Texture/Debug/SliderBar.png" );
    cursor->setPosition( Vec2( SCREEN_SIZE.width / 2, SCREEN_SIZE.height / 5.0f ) );
    
    cursor->addEventListener( [ ]( Ref* ref,Slider::EventType type ){
        
        // スライダーのキャスト変換
        //auto s = static_cast<Slider*>( ref );
        
        // 数値をログ表示
        //log( "数値 %d", s->getPercent() );
    });
    addChild( cursor );
    
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
    Sprite* sprite = Sprite::create( "Texture/Debug/BackGround.png" );
    sprite->setPosition( Vec2( SCREEN_SIZE.width / 2.0f, SCREEN_SIZE.height / 2.0f ) );
    sprite->setScale( 2.0f, 2.0f );
    addChild( sprite );
}

void GameStageSelectLayer::drawStageSelectLogo(){
    
    //Logo
    Sprite* stageimage = Sprite::create( "Texture/Debug/StageSelect.png" );
    stageimage->setPosition( Vec2( SCREEN_SIZE.width / 2.0f, SCREEN_SIZE.height / 1.1f ) );
    stageimage->setScale( 2.0f, 2.0f );
    addChild( stageimage );
}