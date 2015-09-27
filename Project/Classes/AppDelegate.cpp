#include "AppDelegate.h"
#include "Utility/Audio/ADX2Manager.h"
#include "Utility/Assistant/SceneCreator.h"
#include "Debug/TestArea.h"
#include "GameMain/GamePlay/DebugLayer.h"
#include "GameMain/GameTitle/GameTitleLayer.h"

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
	
	Scene* scene = nullptr;
	
// iOS Simulator.
#ifdef DEBUG_HOSHI
	scene = SceneCreator::createScene( TestArea::create() );
#elif DEBUG_TOSHIKAWA
	scene = SceneCreator::createPhysicsScene( DebugLayer::create(), Vect( 0, -6.0f ), false, 6.0f );
#elif DEBUG_SATOU
	scene = SceneCreator::createScene( GameTitleLayer::create() );
#endif
	
// Android.
#if ( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
	scene = SceneCreator::createScene( GameTitleLayer::create() );
#endif
	
	director->runWithScene( scene );
	
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