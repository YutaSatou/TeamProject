//
//  ResultWallManager.cpp
//  TeamProject
//
//  Created by Satou yuta on 2016/01/16.
//
//

#include "ResultWallManager.h"
#include "ResultWall.h"
#include "../../GamePlay/Object/Wall/Wall.h"
#include "ResultSlime.h"

using namespace cocos2d;

// 初期化
bool ResultWallManager::init()
{
	if ( !Node::init() )
	{
		return false;
	}
	
	//スライムを箱に入れるための中間の入れもの
	const Vec2 rightPos { 690, 800 };
	const Vec2 leftPos { 30, 800 };
	
	const auto addWall = [ this ]( const Vec2& firstPosition, int x, int y, float rotate )
	{
		Sprite* wall = Sprite::create( "Texture/GamePlay/Terrain_Triangle_1_1x1.png" );
		wall->setPosition( firstPosition + Vec2( wall->getContentSize().width * x, wall->getContentSize().height * y ) );
		wall->setRotation( rotate );
		addChild( wall );
	};
	
	for ( int i = 0; i < 5; ++i ) {
		
		addWall( rightPos, -i, -i, 0 );
		addWall( leftPos, i, -i, 90 );
	}
	
	//壁
	ResultWall* left { ResultWall::create( { 0, 1280 } , { 0, 820 } ) };
	ResultWall* right { ResultWall::create( { 720, 1280 }, { 720, 820 } ) };
	
	// 自身の子ノードとして追加する。
	addChild( left );
	addChild( right );
	
	ResultWall* leftDown { ResultWall::create( { 0, 830 }, { 345, 485 } ) };
	addChild( leftDown );
	ResultWall* rightDown { ResultWall::create( { 720, 830 }, { 375, 485 } ) };
	addChild( rightDown );
	
	//ばらばらになったスライムを入れる箱を用意する
	Sprite* goal = Sprite::create( "Texture/GameResult/goal_bottle.png" );
	goal->setPosition( { 360, 100 } );
	addChild( goal );
	ResultWall* flaskTopLeft { ResultWall::create( { 300, 180 }, { 325, 160 } ) };
	ResultWall* flaskMouthLeft { ResultWall::create( { 325, 160 }, { 325, 100 } ) };
	ResultWall* flaskLeft { ResultWall::create( { 325, 100 },{ 290, 70 } ) };
	ResultWall* flaskLeftUp { ResultWall::create( { 290, 70 }, { 280, 50 } ) };
	ResultWall* flaskLeftMuddle { ResultWall::create( { 280, 50 }, { 275, 40 } ) };
	ResultWall* flaskLeftDown { ResultWall::create( { 275, 40 }, { 275, 30 } ) };
	
	ResultWall* flaskDownLeft { ResultWall::create( { 275, 30 }, { 280, 20 } ) };
	ResultWall* flaskDownMuddle { ResultWall::create( { 280, 20 }, { 420, 20 } ) };
	ResultWall* flasktDownRight { ResultWall::create( { 420, 20 }, { 445, 30 } ) };
	
	ResultWall* flaskTopRight { ResultWall::create( { 420, 180 }, { 395, 160 } ) };
	ResultWall* flaskMouthRight { ResultWall::create( { 395, 160 }, { 395, 100 } ) };
	ResultWall* flaskRight { ResultWall::create( { 395, 100 }, { 430, 70 } ) };
	ResultWall* flaskRightUp { ResultWall::create( { 430, 70 }, { 440, 50 } ) };
	ResultWall* flaskRightMuddle { ResultWall::create( { 440, 50 }, { 445, 40 } ) };
	ResultWall* flaskRightDown { ResultWall::create( { 445, 40 }, { 445, 30 } ) };
	
	addChild( flaskTopLeft );
	addChild( flaskMouthLeft );
	addChild( flaskLeft );
	addChild( flaskLeftUp );
	addChild( flaskLeftMuddle );
	addChild( flaskLeftDown );
	addChild( flaskDownLeft );
	addChild( flaskDownMuddle );
	addChild( flasktDownRight );
	addChild( flaskRightDown );
	addChild( flaskRightMuddle );
	addChild( flaskRightUp );
	addChild( flaskRight );
	addChild( flaskMouthRight );
	addChild( flaskTopRight );
	
	return true;
}

// インスタンスの生成
ResultWallManager* ResultWallManager::create()
{
	ResultWallManager* inst { new ResultWallManager() };
	
	if ( inst && inst->init() )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}