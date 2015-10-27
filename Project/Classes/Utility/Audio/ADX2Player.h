//
//  ADX2Player.h
//  TeamProject
//
//  Created by Satou yuta on 2015/08/22.
//
//

#ifndef _ADX2PLAYER_H_
#define _ADX2PLAYER_H_

#include "cocos2d.h"
#include "../Template/Singleton.h"
#include "cri_adx2le.h"

class ADX2CueSheet;

enum class SoundType;

class ADX2Player : public Singleton< ADX2Player >{
    
protected:
    
    //コンストラクタ
    ADX2Player();
    
public:
    
    //デストラクタ
    ~ADX2Player();
    
    //初期化
    bool init( const std::string& acb, const std::string& awb );
    
    //初期化
    bool init( const std::string& acb );
    
    /**
     *	@brief	音の再生
     *	@param	cueID				キューID
     *	@return	CriAtomExPlaybackId	プレイバックID
     */
    CriAtomExPlaybackId play( CriAtomExCueId cueID );
    
    /**
     *	@brief	音の再生
     *	@param	cueID				キューID
      *	@param	volume				音量
     *	@return	CriAtomExPlaybackId	プレイバックID
     */
    CriAtomExPlaybackId play( CriAtomExCueId cueID, float volume );
	
    /**
     *	@brief	音の停止
     *	@param	playbackID	プレイバックID
     */
    void stop( CriAtomExPlaybackId playbackID );
    
    //プレーヤの停止
    void stopPlayer();
    
    //再生してからの経過時間の取得
    CriSint64 getTime( CriAtomExPlaybackId playbackID ) const;
    
    //キューの数の取得
    CriSint32 getNumCues() const;
    
    //キューの名前の取得
    std::string getCueName( CriAtomExCueId cueID ) const;
    
private:
    
    //ハンドルの解放
    void releaseHandle();

private:
    
private:
    
    friend class Singleton< ADX2Player >;
    
    //キューシート
    ADX2CueSheet*			mCueSheet;
    
    //プレーヤハンドル
    CriAtomExPlayerHn		mPlayerHandle;
    
    //ボイスプールハンドル
    CriAtomExVoicePoolHn	mVoicePoolHandle;
    
    //ボイスプールハンドル
    CriAtomExVoicePoolHn	mHcaMxVoicePoolHandle;
};

#endif /* defined(__TeamProject__ADX2Player__) */
