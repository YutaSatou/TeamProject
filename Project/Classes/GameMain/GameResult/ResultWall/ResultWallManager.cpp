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
	
	// 画面サイズを取得する。
	//const Vec2&	screenMin	{ Vec2::ZERO };
	//const Vec2&	screenMax	{ Director::getInstance()->getWinSize() };
	
	//スライムを箱に入れるための中間の入れ物
	Vec2 poses[] = {
		{ 690, 800 },{ 625, 735 },{ 560, 670 },{ 495, 605 },
		{ 30, 800 },{ 95, 735 },{ 160, 670 },{ 225, 605 },
	};
	
	for ( int i = 0; i < 4; ++i ) {
		Sprite* wall = Sprite::create( "Texture/GamePlay/Terrain_Triangle_3_1x1.png" );
		wall->setPosition( { poses[ i ] } );
		addChild( wall );
	}
	
	for ( int i = 4; i < 8; ++i ) {
		Sprite* wall = Sprite::create( "Texture/GamePlay/Terrain_Triangle_3_1x1.png" );
		wall->setPosition( { poses[ i ] } );
		wall->setRotation( 90 );
		addChild( wall );
	}
	
	Vec2 blockPos[] = {
		{ 430, 535 },{ 290, 535 },
	};
	for ( int i = 0; i < 2; ++i ) {
		Sprite* block = Sprite::create( "Texture/GamePlay/Terrain_Box_3_1x1.png" );
		block->setPosition( blockPos[ i ] );
		addChild( block );
	}
	
	ResultWall* left { ResultWall::create( { 0, 1280 } , { 0, 820 } ) };
	ResultWall* right { ResultWall::create( { 720, 1280 }, { 720, 820 } ) };
	
	// 自身の子ノードとして追加する。
	addChild( left );
	addChild( right );
	
	ResultWall* leftDown { ResultWall::create( { 0, 830 }, { 260, 570 } ) };
	ResultWall* leftMiddle { ResultWall::create( { 260, 570 }, { 320, 570 } ) };
	addChild( leftDown );
	addChild( leftMiddle );
	ResultWall* rightDown { ResultWall::create( { 720, 830 }, { 460, 570 } ) };
	ResultWall* rightMiddle { ResultWall::create( { 460, 570 }, { 400, 570 } ) };
	addChild( rightDown );
	addChild( rightMiddle );
	
	//スライムを箱に入れるための透明な壁
	ResultWall* leftWall { ResultWall::create( { 300, 440 }, { 300, 280 } ) };
	ResultWall* rightWall { ResultWall::create( { 420, 440 }, { 420, 280 } ) };
	addChild( leftWall );
	addChild( rightWall );
	
	//ばらばらになったスライムを入れる箱を用意する
	ResultWall* flaskLeft { ResultWall::create( { 300, 230 },{ 300, 150 } ) };
	ResultWall* flaskLeftUp { ResultWall::create( { 300, 150 }, { 280, 130 } ) };
	ResultWall* flaskLeftMuddle { ResultWall::create( { 280, 130 }, { 280, 100 } ) };
	ResultWall* flaskLeftDown { ResultWall::create( { 280, 100 }, { 300, 80 } ) };
	ResultWall* flaskDownLeft { ResultWall::create( { 300, 80 }, { 420, 80 } ) };
	ResultWall* flasktDownRight { ResultWall::create( { 420, 80 }, { 440, 100 } ) };
	ResultWall* flaskRightDown { ResultWall::create( { 420, 80 }, { 440, 100 } ) };
	ResultWall* flaskRightMuddle { ResultWall::create( { 440, 100 }, { 440, 130 } ) };
	ResultWall* flaskRightUp { ResultWall::create( { 440, 130 }, { 420, 150 } ) };
	ResultWall* flaskRight { ResultWall::create( { 420, 150 }, { 420, 230 } ) };
	
	addChild( flaskLeft );
	addChild( flaskLeftUp );
	addChild( flaskLeftMuddle );
	addChild( flaskLeftDown );
	addChild( flaskDownLeft );
	addChild( flasktDownRight );
	addChild( flaskRightDown );
	addChild( flaskRightMuddle );
	addChild( flaskRightUp );
	addChild( flaskRight );
	
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