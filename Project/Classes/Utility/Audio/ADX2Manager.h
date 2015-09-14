//
//  ADX2Manager.h
//  TeamProject
//
//  Created by Satou yuta on 2015/08/06.
//
//

#ifndef __TeamProject__ADX2Manager__
#define __TeamProject__ADX2Manager__

#include "cocos2d.h"
#include "cri_adx2le.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#include <AudioToolbox/AudioSession.h>
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "platform/android/jni/JniHelper.h"
#endif

class ADX2Manager : public cocos2d::Ref
{
    
protected:
    
    /**
     *	@brief	コンストラクタ
     */
    ADX2Manager();
    
    /**
     *	@brief	デストラクタ
     */
    ~ADX2Manager();
    
public:
    
    /**
     *	@brief	インスタンスの生成
     */
    static ADX2Manager* create();
    
    /**
     *	@brief	更新
     */
    static void update();
    
    /**
     *	@brief	初期化
     */
    void init( const std::string& acf );
    
    /**
     *	@brief	アプリ中断
     */
    void pauseApp();
    
    /**
     *	@brief	アプリ再開
     */
    void resumeApp();
    
};

#endif /* defined(__TeamProject__ADX2Manager__) */
