//
//  ADX2Manager.h
//  TeamProject
//
//  Created by Satou yuta on 2015/08/22.
//
//

#ifndef _ADX2MANAGER_H_
#define _ADX2MANAGER_H_

#include "cocos2d.h"
#include "cri_adx2le.h"
#include "../Template/Singleton.h"

#if ( CC_TARGET_PLATFORM == CC_PLATFORM_IOS )
#include <AudioToolbox/AudioSession.h>
#elif ( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
#include "platform/android/jni/JniHelper.h"
#endif

class ADX2Manager : public Singleton< ADX2Manager >{
    
public:
    
    //デストラクタ
    ~ADX2Manager();
    
    //初期化
    bool init( const std::string& acf );
    
    //更新
    static void update();
    
    //アプリがバックグランドになった時のコールバック関数
    void pauseApp();
    
    //アプリがバックグラウンドから戻った時のコールバック関数
    void resumeApp();
    
private:
    
    //コンストラクタ
    ADX2Manager();
	
	//プラットフォームごとの初期化
	void PlattformSetting();
    
private:
    
    friend class Singleton< ADX2Manager >;
    
    //D-BASのID
    CriAtomDbasId mDbasID;
};

#endif /* defined(__TeamProject__ADX2Manager__) */
