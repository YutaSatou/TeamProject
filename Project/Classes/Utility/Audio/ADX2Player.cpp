//
//  ADX2Player.cpp
//  TeamProject
//
//  Created by Satou yuta on 2015/08/22.
//
//

#include "ADX2Player.h"
#include "ADX2CueSheet.h"

//コンストラクタ
ADX2Player::ADX2Player()
: mCueSheet( nullptr )
, mPlayerHandle( nullptr )
, mVoicePoolHandle( nullptr )
, mHcaMxVoicePoolHandle( nullptr )
{
    
}

// デストラクタ
ADX2Player::~ADX2Player()
{
    
    releaseHandle();
    
    CC_SAFE_RELEASE_NULL( mCueSheet );
}

// 初期化
bool ADX2Player::init( const std::string& acb, const std::string& awb )
{
    
    mCueSheet = ADX2CueSheet::create( acb, awb );
    CC_SAFE_RETAIN( mCueSheet );
    
    // 各コンフィグを用意する。
    CriAtomExPlayerConfig				playerConfig;
    CriAtomExStandardVoicePoolConfig	voicePoolConfig;
    CriAtomExHcaMxVoicePoolConfig		hcaMxVoicePoolConfig;
    
    // デフォルト値で初期化する。
    criAtomExPlayer_SetDefaultConfig( &playerConfig );
    criAtomExVoicePool_SetDefaultConfigForStandardVoicePool( &voicePoolConfig );
    criAtomExVoicePool_SetDefaultConfigForHcaMxVoicePool( &hcaMxVoicePoolConfig );
    
    // 各パラメータを設定する。
    voicePoolConfig.player_config.streaming_flag			= true;
    voicePoolConfig.player_config.max_sampling_rate			= 96000;
    hcaMxVoicePoolConfig.player_config.streaming_flag		= true;
    hcaMxVoicePoolConfig.player_config.max_sampling_rate	= 96000;
    
    // 各インスタンスを生成する。
    mPlayerHandle			= criAtomExPlayer_Create( &playerConfig, nullptr, 0 );
    mVoicePoolHandle		= criAtomExVoicePool_AllocateStandardVoicePool( &voicePoolConfig, nullptr, 0 );
    mHcaMxVoicePoolHandle	= criAtomExVoicePool_AllocateHcaMxVoicePool( &hcaMxVoicePoolConfig, nullptr, 0 );
    
    return true;
}

// 初期化
bool ADX2Player::init( const std::string& acb )
{
    
    mCueSheet = ADX2CueSheet::create( acb, "" );
    CC_SAFE_RETAIN( mCueSheet );
    
    // 各コンフィグを用意する。
    CriAtomExPlayerConfig				playerConfig;
    CriAtomExStandardVoicePoolConfig	voicePoolConfig;
    CriAtomExHcaMxVoicePoolConfig		hcaMxVoicePoolConfig;
    
    // デフォルト値で初期化する。
    criAtomExPlayer_SetDefaultConfig( &playerConfig );
    criAtomExVoicePool_SetDefaultConfigForStandardVoicePool( &voicePoolConfig );
    criAtomExVoicePool_SetDefaultConfigForHcaMxVoicePool( &hcaMxVoicePoolConfig );
    
    // 各パラメータを設定する。
    voicePoolConfig.player_config.streaming_flag			= true;
    voicePoolConfig.player_config.max_sampling_rate			= 96000;
    hcaMxVoicePoolConfig.player_config.streaming_flag		= true;
    hcaMxVoicePoolConfig.player_config.max_sampling_rate	= 96000;
    
    // 各インスタンスを生成する。
    mPlayerHandle			= criAtomExPlayer_Create( &playerConfig, nullptr, 0 );
    mVoicePoolHandle		= criAtomExVoicePool_AllocateStandardVoicePool( &voicePoolConfig, nullptr, 0 );
    mHcaMxVoicePoolHandle	= criAtomExVoicePool_AllocateHcaMxVoicePool( &hcaMxVoicePoolConfig, nullptr, 0 );
    
    return true;
}

//音の再生
CriAtomExPlaybackId ADX2Player::play( CriAtomExCueId cueID )
{
	
    criAtomExPlayer_SetCueId( mPlayerHandle, mCueSheet->getAcbHandle(), cueID );
    auto playbackID = criAtomExPlayer_Start( mPlayerHandle );
    return playbackID;
}

//音の停止
void ADX2Player::stop( CriAtomExPlaybackId playbackID )
{
    
    criAtomExPlayback_Stop( playbackID );
}

//プレーヤの停止
void ADX2Player::stopPlayer()
{
    
    criAtomExPlayer_Stop( mPlayerHandle );
}

//再生してからの経過時間の取得
CriSint64 ADX2Player::getTime( CriAtomExPlaybackId playbackID ) const
{
    
    return criAtomExPlayback_GetTime( playbackID );
}

// キューの数の取得
CriSint32 ADX2Player::getNumCues() const
{
    
    return criAtomExAcb_GetNumCues( mCueSheet->getAcbHandle() );
}

// キューの名前の取得
std::string ADX2Player::getCueName( CriAtomExCueId cueID ) const
{
    
    return criAtomExAcb_GetCueNameById( mCueSheet->getAcbHandle(), cueID );
}

//ハンドルの解放
void ADX2Player::releaseHandle()
{
    
    stopPlayer();
    
    criAtomExPlayer_Destroy( mPlayerHandle );
    criAtomExVoicePool_Free( mVoicePoolHandle );
    criAtomExVoicePool_Free( mHcaMxVoicePoolHandle );
}