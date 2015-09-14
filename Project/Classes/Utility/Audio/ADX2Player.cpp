//
//  ADX2Player.cpp
//  TeamProject
//
//  Created by Satou yuta on 2015/08/15.
//
//

#include "ADX2Player.h"
#include "ADX2CueSheet.h"

ADX2Player::ADX2Player()
: mCueSheet( nullptr )
, mPlayerHandle( nullptr )
, mVoicePoolHandle( nullptr )
, mHcaMxVoicePoolHandle( nullptr ){
    
}

ADX2Player::~ADX2Player(){
    
    releaseHandle();
    
    mCueSheet->release();
}

ADX2Player* ADX2Player::create( const std::string& acb ){
    
    return ADX2Player::create( acb, "" );
}

ADX2Player* ADX2Player::create( const std::string& acb, const std::string& awb ){
    
    ADX2Player* inst = new ADX2Player();
    
    if ( inst && inst->init( acb, awb ) )
    {
        inst->autorelease();
        return inst;
    }
    
    CC_SAFE_DELETE( inst );
    return nullptr;
}

bool ADX2Player::init( const std::string& acb, const std::string& awb ){
    
    mCueSheet = ADX2CueSheet::create( acb, awb );
    mCueSheet->retain();
    
    CriAtomExPlayerConfig playerConfig;
    criAtomExPlayer_SetDefaultConfig( &playerConfig );
    mPlayerHandle = criAtomExPlayer_Create( &playerConfig, NULL, 0 );
    
    CriAtomExStandardVoicePoolConfig voicePoolConfig;
    criAtomExVoicePool_SetDefaultConfigForStandardVoicePool( &voicePoolConfig );
    voicePoolConfig.player_config.streaming_flag	= CRI_TRUE;
    voicePoolConfig.player_config.max_sampling_rate	= 96000;
    mVoicePoolHandle = criAtomExVoicePool_AllocateStandardVoicePool( &voicePoolConfig, NULL, 0 );
    
    CriAtomExHcaMxVoicePoolConfig hcaMxVoicePoolConfig;
    criAtomExVoicePool_SetDefaultConfigForHcaMxVoicePool( &hcaMxVoicePoolConfig );
    hcaMxVoicePoolConfig.player_config.streaming_flag		= CRI_TRUE;
    hcaMxVoicePoolConfig.player_config.max_sampling_rate	= 96000;
    mHcaMxVoicePoolHandle = criAtomExVoicePool_AllocateHcaMxVoicePool( &hcaMxVoicePoolConfig, NULL, 0 );
    
    return true;
}

CriAtomExPlaybackId ADX2Player::play( CriAtomExCueId cueID ){
    
    criAtomExPlayer_SetCueId( mPlayerHandle, mCueSheet->getAcbHandle(), cueID );
    auto playbackID = criAtomExPlayer_Start( mPlayerHandle );
    return playbackID;
}

void ADX2Player::stop( CriAtomExPlaybackId playbackID ){
    
    criAtomExPlayback_Stop( playbackID );
}

void ADX2Player::stopPlayer(){
    
    criAtomExPlayer_Stop( mPlayerHandle );
}

CriSint32 ADX2Player::getNumCues() const{
    
    return criAtomExAcb_GetNumCues( mCueSheet->getAcbHandle() );
}

CriSint64 ADX2Player::getTime( CriAtomExPlaybackId playbackID ) const{
    
    return criAtomExPlayback_GetTime( playbackID );
}

std::string ADX2Player::getCueName( CriAtomExCueId cueID ) const{
    
    return criAtomExAcb_GetCueNameById( mCueSheet->getAcbHandle(), cueID );
}

void ADX2Player::setVolumeAll( float volume ){
    
    criAtomExPlayer_SetVolume( mPlayerHandle, volume);
    criAtomExPlayer_UpdateAll( mPlayerHandle );
}

void ADX2Player::releaseHandle(){
    stopPlayer();
    
    criAtomExPlayer_Destroy( mPlayerHandle );
    criAtomExVoicePool_Free( mVoicePoolHandle );
    criAtomExVoicePool_Free( mHcaMxVoicePoolHandle );
}
