#include "GamePlayLayer.h"
#include "LiquidFun/LiquidFunCoreAPI.h"
#include "Object/Contact/ContactListener.h"
#include "Control/GameLayer.h"
#include "User/UI/UILayer.h"
#include "Utility/DataIO/StageNumber.h"

using namespace cocos2d;

// 初期化
bool GamePlayLayer::init()
{
	if ( !Layer::init() )
	{
		return false;
	}
	
	scheduleUpdate();
	addBackground();
	
	StageNumber			stageNumber;
	const std::string&	stageFileName { stageNumber.readStagePlistName() };
	
	addChild( ContactListener::create() );
	addChild( GameLayer::create( stageFileName ) );
	addChild( UILayer::create() );
	
	return true;
}

// 更新
void GamePlayLayer::update( float deltaTime )
{
	Layer::update( deltaTime );
	
	LiquidFunWorldManager::getInstance().update();
}

// インスタンスの生成
GamePlayLayer* GamePlayLayer::create()
{
	GamePlayLayer* inst { new GamePlayLayer() };
	
	if ( inst && inst->init() )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

// 背景の追加
void GamePlayLayer::addBackground()
{
	std::random_device						random;
	std::mt19937							mt { random() };
	std::uniform_int_distribution< int >	number { 1, 3 };
	std::string								numberStr { StringUtils::toString( number( mt ) ) };
	
	Sprite* background { Sprite::create( "Texture/GamePlay/Background_" + numberStr + ".png" ) };
	background->setPosition( Director::getInstance()->getWinSize() / 2.0f );
	addChild( background );
}