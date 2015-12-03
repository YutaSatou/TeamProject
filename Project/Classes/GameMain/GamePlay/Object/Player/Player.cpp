#include "Player.h"
#include "../Data/ObjectData.h"
#include "PlayerBody.h"
#include "../Color/ColorMixer.h"

using namespace cocos2d;

// コンストラクタ
Player::Player()
	: mObjectData( nullptr )
	, mPlayerBody( makeShared< PlayerBody >() )
	, mColorMixer( makeShared< ColorMixer >() )
{
	
}

// 初期化
bool Player::init( SharedPtr< ObjectData > objectData )
{
	if ( !Node::init() )
	{
		return false;
	}
	
	// スケジュール登録を行う。
	scheduleUpdate();
	
	// オブジェクトデータを登録する。
	mObjectData = objectData;
	setUserData( &mObjectData->blendColor );
	
	// 各パラメータを設定する。
	setName( "Player" );
	setColor( mObjectData->textureColor );
	setContentSize( Size( 64.0f, 64.0f ) );
	setAnchorPoint( Vec2::ANCHOR_MIDDLE );
	setPosition( Vec2::ZERO );
	
	// ボディの初期化を行う。
	mPlayerBody->init( this, objectData->textureName, objectData->position );
	
	return true;
}

// 更新
void Player::update( float deltaTime )
{
	Node::update( deltaTime );
	
	mPlayerBody->update();
}

// インスタンスの生成
Player* Player::create( SharedPtr< ObjectData > objectData )
{
	Player* inst = new Player();
	
	if ( inst && inst->init( objectData ) )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

// 重力の有効化
void Player::enableGravity()
{
	mPlayerBody->enableGravity();
}

// 色の更新
void Player::updateColor( const ColorCMY& blendColor )
{
	// 色情報を更新する。
	mObjectData->blendColor		= blendColor;
	mObjectData->textureColor	= ColorCMY::convertToRGB( blendColor );
	
	// ノードの色を変更する。
	setColor( mObjectData->textureColor );
}