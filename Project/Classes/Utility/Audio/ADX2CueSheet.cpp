//
//  ADX2CueSheet.cpp
//  TeamProject
//
//  Created by Satou yuta on 2015/08/22.
//
//

#include "ADX2CueSheet.h"
#include "ADX2FileConverter.h"

using namespace cocos2d;

//コンストラクタ
ADX2CueSheet::ADX2CueSheet()
: mAcbHandle( nullptr )
{
    
}

// デストラクタ
ADX2CueSheet::~ADX2CueSheet()
{
    
    //ACBハンドルの開放
    criAtomExAcb_Release( mAcbHandle );
}

// インスタンスの生成
ADX2CueSheet* ADX2CueSheet::create( const std::string& acb, const std::string& awb )
{
    
    ADX2CueSheet* inst = new ADX2CueSheet();
    
    if ( inst && inst->loadAcb( acb, awb ) )
    {
        inst->autorelease();
        return inst;
    }
    
    CC_SAFE_DELETE( inst );
    return nullptr;
}

// ACBハンドルの取得
CriAtomExAcbHn ADX2CueSheet::getAcbHandle()
{
    
    return mAcbHandle;
}

// ACBファイルの読み込み
bool ADX2CueSheet::loadAcb( const std::string& acb, const std::string& awb )
{
    
	std::string acbPath	= ADX2FlieConverter::convertFilePath( acb );
	std::string awbPath	= ADX2FlieConverter::convertFilePath( awb );
    
    if ( awb == "" )
	{
        
        //AWBファイルなしの読み込み
        mAcbHandle = criAtomExAcb_LoadAcbFile( nullptr, acbPath.c_str(), nullptr, nullptr, nullptr, 0 );
    }
	else
	{
        
         //AWBファイルなしの読み込み
        mAcbHandle = criAtomExAcb_LoadAcbFile( nullptr, acbPath.c_str(), nullptr, awbPath.c_str(), nullptr, 0 );
    }
    
    if ( mAcbHandle == nullptr )
    {
        return false;
    }
    
    return true;
}
