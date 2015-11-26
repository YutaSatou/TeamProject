#include "UILayer.h"
#include "GameUIButton.h"
#include "Utility/Assistant/SceneCreator.h"
#include "Utility/Assistant/SceneChanger.h"
#include "GameMain/GameStageSelect/GameStageSelectLayer.h"
#include "GameMain/GamePlay/GamePlayLayer.h"

using namespace cocos2d;

// 初期化
bool UILayer::init()
{
	if ( !Layer::init() )
	{
		return false;
	}
	
	// ステージセレクトシーンに戻るボタンの設定記述子。
	GameUIButtonDesc returnButtonDesc = { "Button_ReturnStageSelect.png", { 100.0f, 1180.0f }, []()
	{
		Scene* scene		= SceneCreator::createScene( GameStageSelectLayer::create() );
		Scene* nextScene	= TransitionFade::create( 1.0f, scene, Color3B::BLACK );
		SceneChanger::switchScene( nextScene );
	} };
	
	// ゲームをやり直すボタンの設定記述子
	GameUIButtonDesc restartButtonDesc = { "Button_RestartGamePlay.png", { 620.0f, 1180.0f }, []()
	{
		SceneChanger::switchScene( GamePlayLayer::create() );
	} };
	
	// ボタンを生成して、自身の子ノードとして追加する。
	addChild( GameUIButton::create( returnButtonDesc ) );
	addChild( GameUIButton::create( restartButtonDesc ) );
	
	return true;
}

// インスタンスの生成
UILayer* UILayer::create()
{
	UILayer* inst = new UILayer();
	
	if ( inst && inst->init() )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}