//
//  ADX2FileConverter.cpp
//  TeamProject
//
//  Created by Satou yuta on 2015/08/22.
//
//

#include "cocos2d.h"
#include "ADX2FileConverter.h"

using namespace cocos2d;

//ファイルパスの変換
std::string ADX2FlieConverter::convertFilePath(const std::string& filePath){
	
#if ( CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC )
	
	// iOS,Macはフルパスで返す
	return FileUtils::getInstance()->fullPathForFilename( filePath );
	
#elif ( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID ) || ( CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 )
	
	// Android,Windowsはそのままの値を返却する。
	return std::string( filePath.c_str() );
#endif
}