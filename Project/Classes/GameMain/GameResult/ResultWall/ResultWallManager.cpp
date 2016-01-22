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
	
	ResultWall* left { ResultWall::create( { 0, 1280 } , { 0, 820 } ) };
	ResultWall* right { ResultWall::create( { 720, 1280 }, { 720, 820 } ) };
	
	// 自身の子ノードとして追加する。
	addChild( left );
	addChild( right );
	
	ResultWall* leftDown { ResultWall::create( { 0, 830 }, { 340, 490 } ) };
	addChild( leftDown );
	ResultWall* rightDown { ResultWall::create( { 720, 830 }, { 380, 490 } ) };
	addChild( rightDown );
	
	//スライムを箱に入れるための透明な壁
	//ResultWall* leftWall { ResultWall::create( { 250, 440 }, { 250, 280 } ) };
	//ResultWall* rightWall { ResultWall::create( { 470, 440 }, { 470, 280 } ) };
	//addChild( leftWall );
	//addChild( rightWall );
	
	//ばらばらになったスライムを入れる箱を用意する
	ResultWall* flaskMouthLeft { ResultWall::create( { 250, 280 }, { 300, 230 } ) };
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
	ResultWall* flaskMouthRight { ResultWall::create( { 470, 280 }, { 420, 230 } ) };
	
	addChild( flaskMouthLeft );
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
	addChild( flaskMouthRight );
	
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