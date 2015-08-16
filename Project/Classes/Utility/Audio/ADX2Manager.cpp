#include "ADX2Manager.h"
#include "ADX2Converter.h"

#if ( CC_TARGET_PLATFORM == CC_PLATFORM_IOS )
#include <AudioToolbox/AudioSession.h>
#elif ( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
#include "platform/android/jni/JniHelper.h"
#endif

using namespace cocos2d;

// コンストラクタ
ADX2Manager::ADX2Manager()
	: mDbasID( 0 )
{
	
}

// デストラクタ
ADX2Manager::~ADX2Manager()
{
	criAtomEx_UnregisterAcf();
	criAtomEx_DetachDspBusSetting();
	criAtomDbas_Destroy( mDbasID );
	
#if ( CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 )
	
	criAtomEx_Finalize_PC();
	
#elif ( CC_TARGET_PLATFORM == CC_PLATFORM_MAC )
	
	criAtomEx_Finalize_MACOSX();
	
#elif ( CC_TARGET_PLATFORM == CC_PLATFORM_IOS )
	
	criAtomEx_Finalize_IOS();
	
#elif ( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
	
	criAtomEx_Finalize_ANDROID();
	
#endif
}

// 初期化
bool ADX2Manager::init( const std::string& acf )
{
	// エラー検知用ラムダ式を用意する。
	auto errorCallback = []( const CriChar8* errID, CriUint32 p1, CriUint32 p2, CriUint32* parray )
	{
		const CriChar8* errMsg;
		errMsg = criErr_ConvertIdToMessage( errID, p1, p2 );
		CCLOG( "%s\n", errMsg );
	};
	
	// エラー検知用コールバック関数を登録する。
	criErr_SetCallback( errorCallback );
	
	// メモリの確保, 解放ラムダ式を用意する。
	auto userAlloc	= []( void* obj, CriUint32 size )	{ return malloc( size );	};
	auto userFree	= []( void* obj, void* ptr )		{ free( ptr );				};
	
	// 自前のアロケータを用意していないので、上記のラムダ式を登録する。
	criAtomEx_SetUserAllocator( userAlloc, userFree, nullptr );
	
	// プラットフォーム別の初期化を行う。
	initPlatformSetting();
	
	// ACFファイルを登録し、DSPバスをアタッチする。
	criAtomEx_RegisterAcfFile( nullptr, ADX2Converter::convertFilePath( acf ).c_str(), nullptr, 0 );
	criAtomEx_AttachDspBusSetting( "DspBusSetting_0", nullptr, 0 );
	
	// D-BASを生成する。
	mDbasID = criAtomDbas_Create( nullptr, nullptr, 0 );
	
	return true;
}

// 更新
void ADX2Manager::update()
{
	criAtomEx_ExecuteMain();
}

// アプリ中断時のコールバック関数
void ADX2Manager::pauseApp()
{
#if ( CC_TARGET_PLATFORM == CC_PLATFORM_IOS )
	
	criAtomEx_StopSound_IOS();
	
#elif ( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
	
	criAtomEx_StopSound_ANDROID();
	
#endif
}

// アプリ再開時のコールバック関数
void ADX2Manager::resumeApp()
{
#if ( CC_TARGET_PLATFORM == CC_PLATFORM_IOS )
	
	criAtomEx_StartSound_IOS();
	
#elif ( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
	
	criAtomEx_StartSound_ANDROID();
	
#endif
}

// プラットフォーム別の初期化
void ADX2Manager::initPlatformSetting()
{
	// コンフィグをデフォルト値で初期化する。
	CriFsConfig fsConfig;
	criFs_SetDefaultConfig( &fsConfig );
	
#if ( CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 )
	
	// Windows用コンフィグをデフォルト値で初期化する。
	CriAtomExConfig_PC configPC;
	criAtomEx_SetDefaultConfig_PC( &configPC );
	configPC.atom_ex.fs_config				= &fsConfig;
	configPC.hca_mx.output_sampling_rate	= 32000;
	criAtomEx_Initialize_PC( &configPC, nullptr, 0 );
	
#elif ( CC_TARGET_PLATFORM == CC_PLATFORM_MAC )
	
	// Mac用コンフィグをデフォルト値で初期化する。
	CriAtomExConfig_MACOSX configMacOSX;
	criAtomEx_SetDefaultConfig_MACOSX( &configMacOSX );
	configMacOSX.atom_ex.fs_config				= &fsConfig
	configMacOSX.hca_mx.output_sampling_rate	= 32000;
	criAtomEx_Initialize_MACOSX( &configMacOSX, nullptr, 0 );
	
#elif ( CC_TARGET_PLATFORM == CC_PLATFORM_IOS )
	
	// iOS用コンフィグをデフォルト値で初期化する。
	CriAtomExConfig_IOS configIOS;
	criAtomEx_SetDefaultConfig_IOS( &configIOS );
	configIOS.atom_ex.fs_config				= &fsConfig;
	configIOS.hca_mx.output_sampling_rate	= 32000;
	criAtomEx_Initialize_IOS( &configIOS, nullptr, 0 );
	
#elif ( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
	
	// Android用コンフィグをデフォルト値で初期化する。
	CriAtomExConfig_ANDROID configAndroid;
	criAtomEx_SetDefaultConfig_ANDROID( &configAndroid );
	configAndroid.atom_ex.fs_config				= &fsConfig;
	configAndroid.hca_mx.output_sampling_rate	= 32000;
	criAtomEx_Initialize_ANDROID( &configAndroid, nullptr, 0 );
	
#endif
	
#if ( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
	
	// ActivityのContextを取得する。
	JniMethodInfo methodInfo;
	JniHelper::getStaticMethodInfo(	methodInfo, "org/cocos2dx/lib/Cocos2dxActivity", "getContext", "()Landroid/content/Context;" );
	
	// assetsフォルダへのアクセスを可能にする。
	auto androidContextObject = ( jobject )methodInfo.env->CallStaticObjectMethod( methodInfo.classID, methodInfo.methodID );
	criFs_EnableAssetsAccess_ANDROID( JniHelper::getJavaVM(), androidContextObject );
	
#endif
}