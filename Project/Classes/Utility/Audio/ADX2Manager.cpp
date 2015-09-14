//
//  ADX2Manager.cpp
//  TeamProject
//
//  Created by Satou yuta on 2015/08/06.
//
//

#include "ADX2Manager.h"
#include "PlatformSetting.h"
#include "ADX2FlieConverer.h"

using namespace cocos2d;

ADX2Manager::ADX2Manager(){
}

ADX2Manager::~ADX2Manager(){
}

ADX2Manager* ADX2Manager::create(){
    
    ADX2Manager* inst = new ADX2Manager();
    
    if ( inst )
    {
        inst->autorelease();
        return inst;
    }
    
    CC_SAFE_DELETE( inst );
    return nullptr;
}

void ADX2Manager::init(const std::string &acf){
    
    // エラー検知用のコールバック関数
    auto errorCallback = []( const CriChar8* errID, CriUint32 p1, CriUint32 p2, CriUint32* parray )
    {
        const CriChar8* errMsg;
        errMsg = criErr_ConvertIdToMessage( errID, p1, p2 );
        CCLOG( "%s\n", errMsg );
    };
    
    // メモリ確保, 解放関数
    auto userAlloc	= []( void* obj, CriUint32 size )	{ return malloc( size );	};
    auto userFree	= []( void* obj, void* ptr )		{ free( ptr );				};
    
    criErr_SetCallback( errorCallback );
    criAtomEx_SetUserAllocator( userAlloc, userFree, NULL );
    
    PlatformSetting::Platforminit();
    std::string acfPath = ADX2FlieConverter::convertFilePath( acf.c_str() );
    
    criAtomEx_RegisterAcfFile( NULL, acfPath.c_str(), NULL, 0 );
    criAtomEx_AttachDspBusSetting( "DspBusSetting_0", NULL, 0 );
}

void ADX2Manager::update(){
    
    criAtomEx_ExecuteMain();
}

void ADX2Manager::pauseApp(){
    
#if ( CC_TARGET_PLATFORM == CC_PLATFORM_IOS )
    criAtomEx_StopSound_IOS();
    
#elif ( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
    criAtomEx_StopSound_ANDROID();
    
#endif
}

void ADX2Manager::resumeApp(){
    
#if ( CC_TARGET_PLATFORM == CC_PLATFORM_IOS )
    criAtomEx_StartSound_IOS();
    
#elif ( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
    criAtomEx_StartSound_ANDROID();
    
#endif
}