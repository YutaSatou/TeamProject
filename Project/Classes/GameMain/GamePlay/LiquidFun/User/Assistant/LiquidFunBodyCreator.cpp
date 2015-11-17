#include "LiquidFunBodyCreator.h"
#include "cocos2d.h"
#include "LiquidFunMaterial.h"
#include "../../LiquidFunCoreAPI.h"

using namespace cocos2d;

// ボディの生成
LiquidFunBody* LiquidFunBodyCreator::createBody( const LiquidFunBodyDef& bodyDef, const LiquidFunFixtureDef& fixtureDef )
{
	// ボディをワールドに追加して取得する。
	LiquidFunBody* body = LiquidFunWorldManager::getInstance().addBody( &bodyDef );
	
	// ボディにフィクスチャを追加する。
	body->CreateFixture( &fixtureDef );
	
	return body;
}

// ボディの生成
LiquidFunBody* LiquidFunBodyCreator::createBody( Node* registerNode, const LiquidFunBodyType& bodyType, const LiquidFunShape& shape, const LiquidFunMaterial& material )
{
	// ボディの情報、フィクスチャの情報を生成する。
	LiquidFunBodyDef	bodyDef		= createBodyDef( registerNode, bodyType );
	LiquidFunFixtureDef	fixtureDef	= createFixtureDef( shape, material );
	
	// ボディをワールドに追加して取得する。
	LiquidFunBody* body = LiquidFunWorldManager::getInstance().addBody( &bodyDef );
	
	// ボディにフィクスチャを追加する。
	body->CreateFixture( &fixtureDef );
	
	return body;
}

// ボディの情報の生成
LiquidFunBodyDef LiquidFunBodyCreator::createBodyDef( Node* registerNode, const LiquidFunBodyType& bodyType )
{
	// ボディの情報を定義する。
	LiquidFunBodyDef bodyDef;
	
	// ユーザデータ、ボディの種類、ボディの座標を設定する。
	bodyDef.userData	= registerNode;
	bodyDef.type		= bodyType;
	bodyDef.position	= LiquidFunHelper::toMeter( registerNode->getPosition() );
	
	return bodyDef;
}

// フィクスチャの情報の生成
LiquidFunFixtureDef LiquidFunBodyCreator::createFixtureDef( const LiquidFunShape& shape, const LiquidFunMaterial& material )
{
	// フィクスチャの情報を定義する。
	LiquidFunFixtureDef fixtureDef;
	
	// シェイプ、マテリアルを設定する。
	fixtureDef.shape		= &shape;
	fixtureDef.density		= material.density;
	fixtureDef.restitution	= material.restitution;
	fixtureDef.friction		= material.friction;
	
	return fixtureDef;
}