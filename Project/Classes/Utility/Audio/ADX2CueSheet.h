//
//  ADX2CueSheet.h
//  TeamProject
//
//  Created by Satou yuta on 2015/08/14.
//
//

#ifndef __TeamProject__ADX2CueSheet__
#define __TeamProject__ADX2CueSheet__

#include "cocos2d.h"
#include "cri_adx2le.h"

class ADX2CueSheet : public cocos2d::Ref{
    
protected:
    
    /**
     *	@brief	コンストラクタ
     */
    ADX2CueSheet();
    
    /**
     *	@brief	デストラクタ
     */
    ~ADX2CueSheet();
    
public:
    
    /**
     *	@brief	インスタンスの生成
     */
    static ADX2CueSheet* create( const std::string& acb, const std::string& awb );
    
    /**
     *	@brief	キューシート情報を管理するハンドルの取得
     */
    CriAtomExAcbHn getAcbHandle();
    
private:
    
    /**
     *	@brief	ACBファイルの読み込み
     */
    bool loadAcb( const std::string& acb, const std::string& awb );
    
private:
    
    // メンバ変数の宣言
    CriAtomExAcbHn	mAcbHandle;
};

#endif /* defined(__TeamProject__ADX2CueSheet__) */
