#include "Canvas.h"

using namespace cocos2d;

// コンストラクタ
Canvas::Canvas()
	: mRenderTexture( nullptr )
{
	
}

// 初期化
bool Canvas::init()
{
	if ( !Node::init() )
	{
		return false;
	}
	
	// キャンバスをリセットする。
	resetCanvas();
	
	return true;
}

// インスタンスの生成
Canvas* Canvas::create()
{
	Canvas* inst = new Canvas();
	
	if ( inst && inst->init() )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

// キャンバスのリセット
void Canvas::resetCanvas()
{
	// レンダテクスチャを子ノードから削除する。
	removeChild( mRenderTexture, true );
	
	// 画面サイズを取得する。
	const Size	winSize		= Director::getInstance()->getWinSize();
	const Size	halfSize	= winSize / 2;
	
	// レンダテクスチャを子ノードとして追加する。
	mRenderTexture = RenderTexture::create( winSize.width, winSize.height, Texture2D::PixelFormat::RGBA8888 );
	mRenderTexture->setPosition( halfSize );
	addChild( mRenderTexture );
}

// レンダリングの開始
void Canvas::renderingBegin()
{
	mRenderTexture->begin();
}

// レンダリングの終了
void Canvas::renderingEnd()
{
	mRenderTexture->end();
}

// レンダリングターゲットの追加
void Canvas::addRenderingTarget( Node* object )
{
	object->visit();
}

// イメージの生成
Image* Canvas::createImage()
{
	Image* image = mRenderTexture->newImage();
	
	image->autorelease();
	
	return image;
}

// テクスチャの生成
Texture2D* Canvas::createTexture()
{
	Texture2D*	texture	= new Texture2D();
	Image*		image	= createImage();
	
	texture->autorelease();
	texture->initWithImage( image );
	
	return texture;
}