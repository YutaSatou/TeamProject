#include "AppDelegate.h"
#include "Utility/Audio/ADX2Manager.h"
#include "Utility/Audio/ADX2Player.h"
#include "Utility/Assistant/Scene/SceneChanger.h"
#include "GameMain/GameTitle/GameTitleLayer.h"
#include "GameMain/GameStageSelect/GameStageSelectLayer.h"
#include "GameMain/GamePlay/GamePlayLayer.h"
#include "GameMain/GameResult/GameResultLayer.h"

using namespace cocos2d;

// GLコンテキストの初期化
void AppDelegate::initGLContextAttrs()
{
	GLContextAttrs glContextAttrs { 8, 8, 8, 8, 24, 8 };
	
	GLView::setGLContextAttrs( glContextAttrs );
}

// アプリケーションの起動準備が整った時に呼ばれるコールバック関数
bool AppDelegate::applicationDidFinishLaunching()
{
	Director*	director	{ Director::getInstance() };
	GLView*		glView		{ director->getOpenGLView() };
	
	if ( !glView )
	{
		glView = GLViewImpl::create( "HungrySlime" );
		director->setOpenGLView( glView );
	}
	
	director->setDisplayStats( true );
	director->setAnimationInterval( 1.0f / 60.0f );
	
	glView->setDesignResolutionSize( 720.0f, 1280.0f, ResolutionPolicy::SHOW_ALL );
	
	ADX2Manager::getInstance().init( "Audio/HungrySlimeSounds.acf" );
	ADX2Player::getInstance().init( "Audio/HungrySlimeSheet.acb" );
	
	SceneChanger::switchScene( GameTitleLayer::create() );
	
	return true;
}

// アプリケーションが非アクティブ状態になった時に呼ばれるコールバック関数
void AppDelegate::applicationDidEnterBackground()
{
	Director::getInstance()->stopAnimation();
	
	ADX2Manager::getInstance().pauseApp();
}

// アプリケーションがアクティブ状態になった時に呼ばれるコールバック関数
void AppDelegate::applicationWillEnterForeground()
{
	Director::getInstance()->startAnimation();
	
	ADX2Manager::getInstance().resumeApp();
}