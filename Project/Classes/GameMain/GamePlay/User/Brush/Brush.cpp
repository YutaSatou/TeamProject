#include "Brush.h"
#include "BrushTrail.h"
#include "../../Control/GameControlMediator.h"

using namespace cocos2d;

namespace
{
	bool isFirstWrite = true;	//=> 初めて書くか否か
}

// コンストラクタ
Brush::Brush( GameControlMediator& mediator )
	: mBrushTrail( nullptr )
	, mMediator( mediator )
	, mIsWrite( false )
{
	isFirstWrite = true;
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
Brush* Brush::create( GameControlMediator& mediator )
{
	Brush* inst = new Brush( mediator );
	
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
	if ( mIsWrite )
	{
		// 書いている時はこれ以上書かせない。
		return false;
	}
	
	mBrushTrail->writeBegin( touch );
	mIsWrite = true;
	
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
	mIsWrite = false;
	
	if ( mBrushTrail->writeEnd( touch, this ) )
	{
		if ( !isFirstWrite )
		{
			return;
		}
		
		// 初めて書いた時にゲームを開始する。
		mMediator.gameStart();
		isFirstWrite = false;
	}
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