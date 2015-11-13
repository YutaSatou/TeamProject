#include "SceneSwitcher.h"
#include "cocos2d.h"
#include "SceneCreator.h"
#include "GameMain/GameTitle/GameTitleLayer.h"
#include "GameMain/GameStageSelect/GameStageSelectLayer.h"
#include "GameMain/GamePlay/GamePlayLayer.h"
#include "GameMain/GameResult/GameResultLayer.h"
#include "Editer/EditScene.h"

using namespace cocos2d;

// 通常のシーン変更
void SceneSwitcher::change( SceneType type )
{
	using CreateFunction	= std::function< Scene*() >;
	using CreateFunctionMap	= std::unordered_map< int, CreateFunction >;
	
	static CreateFunctionMap createFunctionMap =
	{
		{ SceneType::TITLE,			[ & ]()
			{ return SceneCreator::createScene( GameTitleLayer::create() ); } },
		{ SceneType::STAGE_SELECT,	[ & ]()
			{ return SceneCreator::createScene( GameStageSelectLayer::create() ); } },
		{ SceneType::PLAY,			[ & ]()
			{ return SceneCreator::createPhysicsScene( GamePlayLayer::create(), Vec2( 0.0f, -6.0f ), false, 6.0f ); } },
		{ SceneType::RESULT,		[ & ]()
			{ return SceneCreator::createScene( GameResultLayer::create() ); } },
        { SceneType::STAGE_EDITER,		[ & ]()
            { return EditScene::createScene(); } },
	};
	
	Scene* scene = createFunctionMap.at( type )();
	
	Director::getInstance()->replaceScene( scene );
}