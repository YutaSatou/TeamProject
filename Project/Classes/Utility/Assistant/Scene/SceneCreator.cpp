#include "SceneCreator.h"

using namespace cocos2d;

// シーンの生成
Scene* SceneCreator::createScene( Layer* childLayer )
{
	Scene* scene { Scene::create() };
	scene->addChild( childLayer );
	
	return scene;
}

// 物理空間を含めたシーンの生成
Scene* SceneCreator::createPhysicsScene( Layer* childLayer, const Vect& gravity, bool isDebug, float speed )
{
	Scene*			scene	{ Scene::createWithPhysics() };
	PhysicsWorld*	world	{ scene->getPhysicsWorld() };
	
	world->setGravity( gravity );
	world->setSpeed( speed );
	
	if ( isDebug )
	{
		world->setDebugDrawMask( PhysicsWorld::DEBUGDRAW_ALL );
	}
	
	scene->addChild( childLayer );
	
	return scene;
}