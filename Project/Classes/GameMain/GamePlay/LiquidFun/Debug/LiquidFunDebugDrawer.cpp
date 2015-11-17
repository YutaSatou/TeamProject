#include "LiquidFunDebugDrawer.h"
#include "GLESDebugDraw.h"
#include "../LiquidFunCoreAPI.h"

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
	
	initDebugDrawFlags();
	
	return true;
}

// 描画
void LiquidFunDebugDrawer::draw( Renderer* renderer, const Mat4& transform, uint32_t flags )
{
	Layer::draw( renderer, transform, flags );
	GL::enableVertexAttribs( cocos2d::GL::VERTEX_ATTRIB_FLAG_POSITION );
	
	Director* director = Director::getInstance();
	
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
	LiquidFunDebugDrawer* inst = new LiquidFunDebugDrawer();
	
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
	
	LiquidFunWorldManager::getInstance().mWorld->SetDebugDraw( mDebugRenderer );
	
	unsigned int flags = 0;
	
	flags += LiquidFunDraw::e_shapeBit;
	flags += LiquidFunDraw::e_jointBit;
	flags += LiquidFunDraw::e_aabbBit;
	flags += LiquidFunDraw::e_pairBit;
	flags += LiquidFunDraw::e_centerOfMassBit;
	flags += LiquidFunDraw::e_particleBit;
	
	mDebugRenderer->SetFlags( flags );
}

// 描画のコールバック関数
void LiquidFunDebugDrawer::onDraw()
{
	Director* director = Director::getInstance();
	
	// 現在のモデルビュの状態を保存する。
	Mat4 prevModelView = director->getMatrix( MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW );
	
	// デバッグ描画を行う。
	director->loadMatrix( MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW, mModelView );
	LiquidFunWorldManager::getInstance().mWorld->DrawDebugData();
	director->loadMatrix( MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW, prevModelView );
	
	// GLのエラーログを表示する。
	CHECK_GL_ERROR_DEBUG();
}