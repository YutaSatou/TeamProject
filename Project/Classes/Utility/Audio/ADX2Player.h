//
//  ADX2Player.h
//  TeamProject
//
//  Created by Satou yuta on 2015/08/15.
//
//

#ifndef __TeamProject__ADX2Player__
#define __TeamProject__ADX2Player__

#include "cocos2d.h"
#include "cri_adx2le.h"

class ADX2CueSheet;

class ADX2Player : public cocos2d::Node
{
    
protected:
    
    /**
     *	@brief	コンストラクタ
     */
    ADX2Player();
    
    /**
     *	@brief	デストラクタ
     */
    ~ADX2Player();
    
public:
    
    /**
     *	@brief	インスタンスの生成
     */
    static ADX2Player* create( const std::string& acb );
    
    /**
     *	@brief	インスタンスの生成
     */
    static ADX2Player* create( const std::string& acb, const std::string& awb );
    
    /**
     *	@brief	初期化
     */
    bool init( const std::string& acb, const std::string& awb );
    
    /**
     *	@brief	音の再生
     */
    CriAtomExPlaybackId play( CriAtomExCueId cueID );
    
    /**
     *	@brief	音の停止
     */
    void stop( CriAtomExPlaybackId playbackID );
    
    /**
     *	@brief	プレーヤの停止
     */
    void stopPlayer();
    
    /**
     *	@brief	キューの数の取得
     */
    CriSint32 getNumCues() const;
    
    /**
     *	@brief	再生開始後の経過時間の取得
     */
    CriSint64 getTime( CriAtomExPlaybackId playbackID ) const;
    
    /**
     *	@brief	キューの名前の取得
     */
    std::string getCueName( CriAtomExCueId cueID ) const;
    
    /**
     *	@brief　音のボリューム設定
     */
    void setVolumeAll( float volume );
    
    
private:
    
    /**
     *	@brief	ハンドルの解放
     */
    void releaseHandle();
    
private:
    
    // メンバ変数の宣言
    ADX2CueSheet*			mCueSheet;
    CriAtomExPlayerHn		mPlayerHandle;
    CriAtomExVoicePoolHn	mVoicePoolHandle;
    CriAtomExVoicePoolHn	mHcaMxVoicePoolHandle;
};

#endif /* defined(__TeamProject__ADX2Player__) */
