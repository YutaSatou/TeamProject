#include "GameTitleLayer.h"
#include "ui/CocosGUI.h"
#include "../../Utility/Audio/ADX2Player.h"
#include "../../GameMain/GameStageSelect/GameStageSelectLayer.h"
#include "Utility/Assistant/Scene/SceneCreator.h"
#include "Utility/Assistant/Scene/SceneChanger.h"

using namespace cocos2d;
using namespace ui;

namespace
{
    
    Size SCREEN_SIZE;
    Vec2 ORIGIN_SIZE;
}

bool GameTitleLayer::init()
{
	if ( !LayerColor::initWithColor( Color4B::BLACK ) )
	{
		return false;
	}
    
    SCREEN_SIZE = Director::getInstance()->getWinSize();
    ORIGIN_SIZE = Director::getInstance()->getVisibleOrigin();
    
    //背景描画
    drawSprite( "Texture/GameTitle/Title_Background.png", Vec2( SCREEN_SIZE.width / 2, SCREEN_SIZE.height / 2 ), false);
    
    //タイトルロゴ描画
    drawSprite( "Texture/GameTitle/Title.png", Vec2( SCREEN_SIZE.width / 2.0f, 915 ), false );
    
    //タッチロゴ表示
    drawSprite( "Texture/GameTitle/Title_Button.png", Vec2( 359, 307 ), true );
    
    //BGM再生（垂れ流し）
    ADX2Player::getInstance().play( 0 );
    
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

void GameTitleLayer::drawSprite( const std::string& fileName, const Vec2& pos, bool isAnimation )
{
    //フェードを入れた場合
    if ( isAnimation )
    {
        //フェードさせるためボタンを作成
        Button* touchLogo = Button::create( fileName );
        touchLogo->setTitleText( "タップスタート" );
        touchLogo->setTitleFontName( "Font/RiiPopkkR.otf" );
        touchLogo->setTitleFontSize( 68 );
        touchLogo->setTitleColor( Color3B::BLACK );
        touchLogo->setEnabled( false );
        touchLogo->setPosition( pos );
        
        //TouchStartアニメーション
        FadeIn* startTScale = FadeIn::create( 1.0f );
        FadeOut* endTScale = FadeOut::create( 1.0f );
        touchLogo->runAction( RepeatForever::create( Sequence::create( endTScale, startTScale, NULL ) ) );
        this->addChild( touchLogo );
        
        return;
    }
    
    //単純スプライトを表示させる
    Sprite* sprite = Sprite::create( fileName );
    sprite->setPosition( pos );
    this->addChild( sprite );
}

void GameTitleLayer::touchListener()
{
    
    //イベントリスナーを作成
    EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
    
    //タッチ開始
    listener->onTouchBegan = [ = ](Touch* touch, Event* event)
    {
        return true;
    };
    
    //タッチ終了
    listener->onTouchEnded = [ = ](Touch* touch, Event* event)
    {
        //タッチされた時の音再生
        ADX2Player::getInstance().play( 6 );
        //シーン遷移
        Scene* scene		{ SceneCreator::createScene( GameStageSelectLayer::create() ) };
        Scene* nextScene	{ TransitionRotoZoom::create( 0.8f, scene ) };
        SceneChanger::switchScene( nextScene );
    };
    
    //イベントリスナーを登録
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority( listener, this );
}