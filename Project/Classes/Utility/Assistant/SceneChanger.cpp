#include "SceneChanger.h"
#include "cocos2d.h"
#include "SceneCreator.h"

using namespace cocos2d;

// シーンの変更
void SceneChanger::switchScene( Layer* nextLayer )
{
	Scene* nextScene = SceneCreator::createScene( nextLayer );
	
	switchScene( nextScene );
}

// シーンの変更
void SceneChanger::switchScene( Scene* nextScene )
{
	Director::getInstance()->replaceScene( nextScene );
}