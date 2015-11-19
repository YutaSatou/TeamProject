#include "AppDelegate.h"
#include "Utility/Assistant/SceneSwitcher.h"
#include "Utility/Assistant/SceneChanger.h"
#include "Utility/Audio/ADX2Manager.h"
#include "Utility/Audio/ADX2Player.h"
#include "GameMain/GamePlay/GamePlayLayer.h"

using namespace cocos2d;

// GLコンテキストの初期化
void AppDelegate::initGLContextAttrs()
{
	GLContextAttrs glContextAttrs = { 8, 8, 8, 8, 24, 8 };
	
	GLView::setGLContextAttrs( glContextAttrs );
}

// アプリケーションの起動準備が整った時に呼ばれるコールバック関数
bool AppDelegate::applicationDidFinishLaunching()
{
	Director*	director	= Director::getInstance();
	GLView*		glView		= director->getOpenGLView();
	
	if ( !glView )
	{
		glView = GLViewImpl::create( "TeamProject" );
		director->setOpenGLView( glView );
	}
	
	director->setDisplayStats( true );
	director->setAnimationInterval( 1.0f / 60.0f );
	
	glView->setDesignResolutionSize( 720.0f, 1280.0f, ResolutionPolicy::SHOW_ALL );
	
	ADX2Manager::getInstance().init( "Audio/Demo.acf" );
    ADX2Player::getInstance().init( "Audio/Demo.acb" );
	
// iOS Simulator.
#ifdef DEBUG_HOSHI
	SceneSwitcher::change( SceneType::PLAY );
#elif DEBUG_TOSHIKAWA
	SceneChanger::switchScene( GamePlayLayer::create() );
#elif DEBUG_SATOU
	SceneSwitcher::change( SceneType::TITLE );
	
// Release.
#else
	SceneSwitcher::change( SceneType::TITLE );
#endif
	
// Android.
#if ( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
	SceneSwitcher::change( SceneType::TITLE );
#endif
	
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