#include "LiquidFunDebugDrawer.h"
#include "GLESDebugDraw.h"
#include "../Core/LiquidFunHelper.h"
#include "../Core/LiquidFunWorldManager.h"

using namespace cocos2d;

// コンストラクタ
LiquidFunDebugDrawer::LiquidFunDebugDrawer()
	: mDebugRenderer( new GLESDebugDraw( LiquidFunHelper::PTM_RATIO ) )
	, mDebugDrawCommand()
	, mModelView()
{
	
}

// デストラクタ
LiquidFunDebugDrawer::~LiquidFunDebugDrawer()
{
	CC_SAFE_DELETE( mDebugRenderer );
}

// 初期化
bool LiquidFunDebugDrawer::init()
{
	if ( !Node::init() )
	{
		return false;
	}
	
	// レイヤを最前面に描画する。
	setGlobalZOrder( 10.0f );
	
	// デバッグ描画フラグの初期化を行う。
	initDebugDrawFlags();
	
	return true;
}

// 描画
void LiquidFunDebugDrawer::draw( Renderer* renderer, const Mat4& transform, uint32_t flags )
{
	Layer::draw( renderer, transform, flags );
	GL::enableVertexAttribs( GL::VERTEX_ATTRIB_FLAG_POSITION );
	
	Director* director { Director::getInstance() };
	
	director->pushMatrix( MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW );
	{
		// モデルビュを取得する。
		mModelView = director->getMatrix( MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW );
		
		// デバッグ描画用のコマンドをレンダラに追加する。
		mDebugDrawCommand.init( getGlobalZOrder() );
		mDebugDrawCommand.func = CC_CALLBACK_0( LiquidFunDebugDrawer::onDraw, this );
		renderer->addCommand( &mDebugDrawCommand );
	}
	director->popMatrix( MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW );
}

// インスタンスの生成
LiquidFunDebugDrawer* LiquidFunDebugDrawer::create()
{
	LiquidFunDebugDrawer* inst { new LiquidFunDebugDrawer() };
	
	if ( inst && inst->init() )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

// デバッグ描画フラグの初期化
void LiquidFunDebugDrawer::initDebugDrawFlags()
{
	using LiquidFunDraw = b2Draw;
	
	// デバッグ描画用レンダラを登録する。
	LiquidFunWorldManager::getInstance().mWorld->SetDebugDraw( mDebugRenderer );
	
	uint32_t flags { 0 };
	flags += LiquidFunDraw::e_shapeBit;
	flags += LiquidFunDraw::e_jointBit;
	flags += LiquidFunDraw::e_aabbBit;
	flags += LiquidFunDraw::e_pairBit;
	flags += LiquidFunDraw::e_centerOfMassBit;
	flags += LiquidFunDraw::e_particleBit;
	
	// デバッグ描画を行うフラグを登録する。
	mDebugRenderer->SetFlags( flags );
}

// 描画のコールバック関数
void LiquidFunDebugDrawer::onDraw()
{
	Director* director { Director::getInstance() };
	
	// モデルビュの状態を保存する。
	const Mat4& prevModelView { director->getMatrix( MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW ) };
	
	// 現在のモデルビュを読み込む。
	director->loadMatrix( MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW, mModelView );
	
	// デバッグ描画を行う。
	LiquidFunWorldManager::getInstance().mWorld->DrawDebugData();
	
	// 保存しておいたモデルビュを読み込む。
	director->loadMatrix( MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW, prevModelView );
	
	// GLのエラーログを表示する。
	CHECK_GL_ERROR_DEBUG();
}