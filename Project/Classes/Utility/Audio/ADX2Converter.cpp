#include "ADX2Converter.h"
#include "cocos2d.h"

using namespace cocos2d;

// ファイルパスの変換
std::string ADX2Converter::convertFilePath( const std::string& filePath )
{
#if ( CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC )
	
	// iOS, Macの場合はフルパスで返却する。
	return FileUtils::getInstance()->fullPathForFilename( filePath );
	
#elif ( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID ) || ( CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 )
	
	// Android, Windowsの場合はそのままの値を返却する。
	return std::string( filePath.c_str() );
	
#endif
}