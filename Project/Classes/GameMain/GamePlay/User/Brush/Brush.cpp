#include "Brush.h"
#include "BrushTrail.h"

using namespace cocos2d;

// コンストラクタ
Brush::Brush()
	: mBrushTrail( nullptr )
{
	
}

// 初期化
bool Brush::init()
{
	if ( !Node::init() )
	{
		return false;
	}
	
	// タッチリスナを初期化する。
	initTouchListener();
	
	// 自身の子ノードとして追加する。
	mBrushTrail = BrushTrail::create();
	addChild( mBrushTrail );
	
	return true;
}

// インスタンスの生成
Brush* Brush::create()
{
	Brush* inst = new Brush();
	
	if ( inst && inst->init() )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

// タッチ開始時のコールバック関数
bool Brush::onTouchBegan( Touch* touch, Event* event )
{
	mBrushTrail->writeBegin( touch );
	
	return true;
}

// タッチ移動時のコールバック関数
void Brush::onTouchMoved( Touch* touch, Event* event )
{
	mBrushTrail->writeMove( touch );
}

// タッチ終了時のコールバック関数
void Brush::onTouchEnded( Touch* touch, Event* event )
{
	mBrushTrail->writeEnd( touch, this );
}

// タッチリスナの初期化
void Brush::initTouchListener()
{
	// タッチリスナを生成する。
	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
	
	// 各関数をコールバックとして設定する。
	listener->onTouchBegan		= CC_CALLBACK_2( Brush::onTouchBegan, this );
	listener->onTouchMoved		= CC_CALLBACK_2( Brush::onTouchMoved, this );
	listener->onTouchEnded		= CC_CALLBACK_2( Brush::onTouchEnded, this );
	listener->onTouchCancelled	= CC_CALLBACK_2( Brush::onTouchEnded, this );
	
	// 下位のレイヤまでイベントが貫通しないようにする。
	listener->setSwallowTouches( true );
	
	// リスナを登録する。
	getEventDispatcher()->addEventListenerWithSceneGraphPriority( listener, this );
}