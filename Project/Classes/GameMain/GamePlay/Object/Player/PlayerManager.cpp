#include "PlayerManager.h"
#include "../Data/ObjectData.h"
#include "Player.h"

using namespace cocos2d;

namespace
{
	const std::string PLAYER_TEXTURE_NAME = "Texture/Debug/Player.png";	//=> プレイヤのテクスチャの名前
}

// コンストラクタ
PlayerManager::PlayerManager()
	: mPlayer( nullptr )
	, mIsPlayerCreated( false )
{
	
}

// インスタンスの生成
PlayerManager* PlayerManager::create()
{
	PlayerManager* inst = new PlayerManager();
	
	if ( inst && inst->init() )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

// データ読み込み時のコールバック関数
void PlayerManager::onDataLoaded( SharedPtr< ObjectData > objectData )
{
	if ( mIsPlayerCreated )
	{
		return;
	}
	
	// プレイヤを生成して自身の子ノードとして追加する。
	mPlayer = Player::create( objectData );
	addChild( mPlayer );
	
	// プレイヤ生成終了の合図を出す。
	mIsPlayerCreated = true;
}

// ゲーム開始時のコールバック関数
void PlayerManager::onGameStart()
{
	mPlayer->enableGravity();
}