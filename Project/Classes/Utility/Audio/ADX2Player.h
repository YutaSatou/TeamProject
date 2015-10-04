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
#include "cri_adx2le.h"
#include "SoundType.h"

class ADX2CueSheet;

enum class SoundType;

class ADX2Player : public cocos2d::Node{
    
protected:
    
    //コンストラクタ
    ADX2Player();
    
    //デストラクタ
    ~ADX2Player();
    
    //初期化
    bool init( const std::string& acb, const std::string& awb );
    
public:
    
    /**
     *	@brief	インスタンスの生成
     *	@param	acb				ACBファイルのパス
     *	@return	ADX2Player		インスタンス
     */
    static ADX2Player* create( const std::string& acb );
    
    /**
     *	@brief	インスタンスの生成
     *	@param	acb				ACBファイルのパス
     *	@param	awb				AWBファイルのパス
     *	@return	ADX2Player		インスタンス
     */
    static ADX2Player* create( const std::string& acb, const std::string& awb );
    
    /**
     *	@brief	音の再生
     *	@param	cueID				キューID
     *	@return	CriAtomExPlaybackId	プレイバックID
     */
    CriAtomExPlaybackId play( CriAtomExCueId cueID, SoundType type );
    
    /**
     *	@brief	音の再生
     *	@param	cueID				キューID
      *	@param	volume				音量
     *	@return	CriAtomExPlaybackId	プレイバックID
     */
    CriAtomExPlaybackId play( CriAtomExCueId cueID, SoundType type, float volume );
	
	CriAtomExPlaybackId BGMPlay( CriAtomExCueId cueID, SoundType type, float fade);
    
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
