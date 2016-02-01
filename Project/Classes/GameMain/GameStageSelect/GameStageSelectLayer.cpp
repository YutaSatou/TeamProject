#include "GameStageSelectLayer.h"
#include "../../Utility/Audio/ADX2Player.h"
#include "StageSelectPage.h"
#include "PageCursor.h"
#include "ui/CocosGUI.h"
#include "StageSelectButton.h"
#include "StageSelectScrollView.h"
#include "UIPageView.h"

#include "../../Utility/Particle/ParticleManager.h"

using namespace cocos2d;

namespace
{    
    Size SCREEN_SIZE;
    Vec2 ORIGIN_SIZE;
}

bool GameStageSelectLayer::init()
{
    if ( !LayerColor::initWithColor( Color4B::BLACK ) )
    {
        return false;
    }
    
    SCREEN_SIZE = Director::getInstance()->getVisibleSize();
    ORIGIN_SIZE = Director::getInstance()->getVisibleOrigin();
    
    //背景の描画
    drawBackGraund();
    
    //ページビューの追加
	//StageSelectButton* button = StageSelectButton::create();
    StageSelectPage* page = StageSelectPage::create( 3 );

	//page->addChild( button );
    addChild( page );
    
    scheduleUpdate();
    
    return true;
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

void GameStageSelectLayer::drawBackGraund()
{
    //背景
    Sprite* sprite = Sprite::create( "Texture/GameStageSelect/StageSelect_Background.png" );
    sprite->setPosition( Vec2( SCREEN_SIZE.width / 2.0f, SCREEN_SIZE.height / 2.0f ) );
    addChild( sprite );
}