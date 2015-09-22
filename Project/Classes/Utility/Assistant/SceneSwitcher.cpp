#include "SceneSwitcher.h"
#include "cocos2d.h"
#include "SceneCreator.h"
#include "GameMain/GameTitle/GameTitleLayer.h"
#include "GameMain/GameStageSelect/GameStageSelectLayer.h"
#include "GameMain/GamePlay/DebugLayer.h"
#include "GameMain/GameResult/GameResultLayer.h"

using namespace cocos2d;

// 通常のシーン変更
void SceneSwitcher::change( SceneType type )
{
	using CreateFunction	= std::function< Scene*() >;
	using CreateFunctionMap	= std::unordered_map< int, CreateFunction >;
	
	static CreateFunctionMap convertMap =
	{
		{ SceneType::TITLE,			[ & ]()
			{ return SceneCreator::createScene( GameTitleLayer::create() ); } },
		{ SceneType::STAGE_SELECT,	[ & ]()
			{ return SceneCreator::createScene( GameStageSelectLayer::create() ); } },
		{ SceneType::PLAY,			[ & ]()
			{ return SceneCreator::createPhysicsScene( DebugLayer::create(), Vec2( 0.0f, -9.8f ), true, 6.0f ); } },
		{ SceneType::RESULT,		[ & ]()
			{ return SceneCreator::createScene( GameResultLayer::create() ); } },
	};
	
	Scene* scene = convertMap.at( type )();
	
	Director::getInstance()->replaceScene( scene );
}