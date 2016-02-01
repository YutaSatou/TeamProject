//
//  ADX2CueSheet.h
//  TeamProject
//
//  Created by Satou yuta on 2015/08/22.
//
//

#ifndef _ADX2CUESHEET_H_
#define _ADX2CUESHEET_H_

#include "cocos2d.h"
#include "cri_adx2le.h"

class ADX2CueSheet : public cocos2d::Ref
{
    
protected:
    
    //コンストラクタ
    ADX2CueSheet();
    
    //デストラクタ
    ~ADX2CueSheet();
    
public:
    
    //インスタンスの生成
    static ADX2CueSheet* create( const std::string& acb, const std::string& awb );
    
    //ACBハンドルの取得
    CriAtomExAcbHn getAcbHandle();
    
private:
    
    //ACBファイルの読み込み
    bool loadAcb( const std::string& acb, const std::string& awb );

private:
    
    //ACBハンドル
    CriAtomExAcbHn mAcbHandle;
};

#endif
