//
//  PlatformSetting.cpp
//  TeamProject
//
//  Created by Satou yuta on 2015/08/06.
//
//

#include "PlatformSetting.h"

void PlatformSetting::Platforminit(){
    
    /* MEMO: HCA-MXでもストリーミング再生できるようにファイル読み込み最大数を増やす */
    CriFsConfig fsConfig;
    criFs_SetDefaultConfig(&fsConfig);
    fsConfig.num_loaders = 32;		/* ざっくり多め。ストリーミング最大数＋ACB等の読み込みが使用 */
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
    /* Windows用 */
    CriAtomExConfig_PC configPC;
    criAtomEx_SetDefaultConfig_PC(&pcConfig);
    configPC.atom_ex.fs_config = &fsConfig;
    configPC.hca_mx.output_sampling_rate = 32000;
    criAtomEx_Initialize_PC(&configPC, NULL, 0);
    
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
    /* Mac用 */
    CriAtomExConfig_MACOSX configMacOSX;
    criAtomEx_SetDefaultConfig_MACOSX(&configMacOSX);
    configMacOSX.atom_ex.fs_config = &fsConfig;
    configMacOSX.hca_mx.output_sampling_rate = 32000;
    criAtomEx_Initialize_MACOSX(&configMacOSX, NULL, 0);
    //デバッグ用のメッセージ
    //CCLOG("Macで起動中");
    
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    /* iOS用 */
    CriAtomExConfig_IOS configIOS;
    criAtomEx_SetDefaultConfig_IOS(&configIOS);
    configIOS.atom_ex.fs_config = &fsConfig;
    configIOS.hca_mx.output_sampling_rate = 32000;
    criAtomEx_Initialize_IOS(&configIOS, NULL, 0);
    //デバッグ用のメッセージ
    //CCLOG("IOSで起動中");
    
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    /* Android用 */
    CriAtomExConfig_ANDROID configAndroid;
    criAtomEx_SetDefaultConfig_ANDROID(&configAndroid);
    configAndroid.atom_ex.fs_config = &fsConfig;
    configAndroid.hca_mx.output_sampling_rate = 32000;
    criAtomEx_Initialize_ANDROID(&configAndroid, NULL, 0);
    //デバック用メッセージ
    //CCLOG("Androidで起動中");
    
#endif
    
#if ( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
    /* まずはJniHelperでActivityのContextを取得 */
    JniMethodInfo methodInfo;
    JniHelper::getStaticMethodInfo(	methodInfo, "org/cocos2dx/lib/Cocos2dxActivity", "getContext", "()Landroid/content/Context;" );
    
    // assetsフォルダへのアクセスを可能にします。
    auto androidContextObject = ( jobject )methodInfo.env->CallStaticObjectMethod( methodInfo.classID, methodInfo.methodID );
    criFs_EnableAssetsAccess_ANDROID( JniHelper::getJavaVM(), androidContextObject );
    
#endif
}
