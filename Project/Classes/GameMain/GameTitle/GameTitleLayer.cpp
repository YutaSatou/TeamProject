#include "GameTitleLayer.h"
#include "../GameStageSelect/GameStageSelectLayer.h"
#include "../../Utility/Assistant/SceneSwitcher.h"
#include "TitleSpriteRenderer.h"
#include "../../Utility/Particle/EffectManager.h"
#include "../../Utility/FileO/StageData.h"

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
    
    touchListener();
    
    //背景
    Sprite* backGraund = TitleSpriteRenderer::createSprite( "Texture/Debug/backgraund.png", Vec2( SCREEN_SIZE.width / 2.0f /*+ ORIGIN_SIZE.x*/,
                                                                                                 SCREEN_SIZE.height / 2.0f /*+ ORIGIN_SIZE.y */) );
    
    //タイトルロゴ
    Sprite* titleLogo = TitleSpriteRenderer::createSprite( "Texture/Debug/title.png", Vec2( SCREEN_SIZE.width / 2.0f /*+ ORIGIN_SIZE.x*/,
                                                                                           SCREEN_SIZE.height / 1.2f /*+ ORIGIN_SIZE.y*/ ) );
    
    //TouchStartロゴ
    Sprite* touchLogo = Sprite::create( "Texture/Debug/TocuhStart.png" );
    touchLogo->setPosition( Vec2( SCREEN_SIZE.width / 2.0f, SCREEN_SIZE.height / 4.0f ) );
    
    ScaleTo* startScale = ScaleTo::create( 0.5f, 1.0f );
    ScaleTo* endScale = ScaleTo::create( 0.5f, 0.5f );
    titleLogo->runAction( RepeatForever::create( Sequence::create( startScale, endScale, NULL ) ) );
    
    ScaleTo* startTScale = ScaleTo::create( 1.0f, 1.0f );
    ScaleTo* endTScale = ScaleTo::create( 1.0f, 0.5f );
    touchLogo->runAction( RepeatForever::create( Sequence::create( startTScale, endTScale, NULL ) ) );
    
    addChild(backGraund);
    addChild(titleLogo);
    addChild(touchLogo);
	
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

void GameTitleLayer::touchListener(){
    
    //イベントリスナーを作成
    EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
    
    //タッチ開始
    listener->onTouchBegan = [ = ](Touch* touch, Event* event){
        mPlayer->play( 1, SoundType::SE);
        return true;
    };
    
    //タッチ中
    listener->onTouchMoved = [](Touch* touch, Event* event){
        
    };
    
    //タッチ終了
    listener->onTouchEnded = [ = ](Touch* touch, Event* event){
        
        SceneSwitcher::change( SceneType::STAGE_SELECT );
    };
    
    //イベントリスナーを登録
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority( listener, this );
}