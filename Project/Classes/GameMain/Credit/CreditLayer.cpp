#include "CreditLayer.h"
#include "Utility/Assistant/Scene/SceneCreator.h"
#include "Utility/Assistant/Scene/SceneChanger.h"
#include "Utility/Audio/ADX2Player.h"

using namespace cocos2d;

// 初期化
bool CreditLayer::init()
{
	if ( !Layer::init() )
	{
		return false;
	}
	
	initTouchListener();
	addBackground();
	
	return true;
}

// インスタンスの生成
CreditLayer* CreditLayer::create()
{
	CreditLayer* inst { new CreditLayer() };
	
	if ( inst && inst->init() )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

// タッチリスナの初期化
void CreditLayer::initTouchListener()
{
	EventListenerTouchOneByOne* listener { EventListenerTouchOneByOne::create() };
	
	listener->onTouchBegan = []( Touch* touch, Event* event )
	{
		return true;
	};
	
	listener->onTouchEnded = []( Touch* touch, Event* event )
	{
		ADX2Player::getInstance().play( CRI_HUNGRYSLIMESHEET_SE_BUTTON_TAP );
		Scene* scene		{ SceneCreator::createScene( CreditLayer::create() ) };
		Scene* nextScene	{ TransitionRotoZoom::create( 0.8f, scene ) };
		SceneChanger::switchScene( nextScene );
	};
	
	getEventDispatcher()->addEventListenerWithSceneGraphPriority( listener, this );
}

// 背景の追加
void CreditLayer::addBackground()
{
	Sprite* background { Sprite::create( "Texture/Credit/Background.png" ) };
	background->setPosition( Director::getInstance()->getWinSize() / 2.0f );
	addChild( background );
}