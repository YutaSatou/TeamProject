#include "ADX2CueSheet.h"
#include "ADX2Converter.h"

using namespace cocos2d;

// コンストラクタ
ADX2CueSheet::ADX2CueSheet()
	: mAcbHandle( nullptr )
{
	
}

// デストラクタ
ADX2CueSheet::~ADX2CueSheet()
{
	criAtomExAcb_Release( mAcbHandle );
}

// インスタンスの生成
ADX2CueSheet* ADX2CueSheet::create( const std::string& acb, const std::string& awb )
{
	auto inst = new ADX2CueSheet();
	
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
	auto acbPath	= ADX2Converter::convertFilePath( acb ).c_str();
	auto awbPath	= ADX2Converter::convertFilePath( awb ).c_str();
	
	if ( awb == "" )
	{
		mAcbHandle = criAtomExAcb_LoadAcbFile( nullptr, acbPath, nullptr, nullptr, nullptr, 0 );
	}
	
	else
	{
		mAcbHandle = criAtomExAcb_LoadAcbFile( nullptr, acbPath, nullptr, awbPath, nullptr, 0 );
	}
	
	if ( mAcbHandle == nullptr )
	{
		return false;
	}
	
	return true;
}