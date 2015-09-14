//
//  PlatformSetting.h
//  TeamProject
//
//  Created by Satou yuta on 2015/08/06.
//
//

#ifndef __TeamProject__PlatformSetting__
#define __TeamProject__PlatformSetting__

#include "cocos2d.h"
#include "cri_adx2le.h"

#if ( CC_TARGET_PLATFORM == CC_PLATFORM_IOS )
#include <AudioToolbox/AudioSession.h>
#elif ( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
#include "platform/android/jni/JniHelper.h"
#endif

class PlatformSetting : public cocos2d::Ref{
    
public:
    
    /**
     *	@brief	プラットフォーム別の初期化
     */
    static void Platforminit();
};

#endif /* defined(__TeamProject__PlatformSetting__) */
