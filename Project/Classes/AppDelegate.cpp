#include "AppDelegate.h"
#include "Utility/Assistant/SceneCreator.h"
#include "GameMain/GamePlay/DebugLayer.h"
#include "Debug/TestArea.h"

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
	
	glView->setDesignResolutionSize( 1280.0f, 720.0f, ResolutionPolicy::SHOW_ALL );
	
	Scene* scene = nullptr;
	
#ifdef DEBUG_HOSHI
	scene = SceneCreator::createPhysicsScene( TestArea::create(), Vect( 0, -9.8f ), true, 3.0f );
#elif DEBUG_TOSHIKAWA
	scene = SceneCreator::createPhysicsScene( DebugLayer::create(), Vect( 0, -6.0f ), false, 6.0f );
#elif DEBUG_SATOU
	// 佐藤はここに自分のシーンの生成を記述する。
#else
	// ReleaseMode
#endif
	
	director->runWithScene( scene );
	
	return true;
}

// アプリケーションが非アクティブ状態になった時に呼ばれるコールバック関数
void AppDelegate::applicationDidEnterBackground()
{
	Director::getInstance()->stopAnimation();
}

// アプリケーションがアクティブ状態になった時に呼ばれるコールバック関数
void AppDelegate::applicationWillEnterForeground()
{
	Director::getInstance()->startAnimation();
}