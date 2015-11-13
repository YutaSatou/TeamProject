//
//  PlistIO.cpp
//  PSStageCreate
//
//  Created by 星共法 on 2015/10/26.
//
//

#include "Utility/FileIO/Plist/PlistIO.h"

using namespace cocos2d;

namespace Utility
{
namespace FileIO
{
    PlistIO::PlistIO()
    {
        
    }

    PlistIO::~PlistIO()
    {
        
    }
    
    //  plist読み込み
    void PlistIO::onRead(const std::string& filePath)
    {
        data = FileUtils::getInstance()->getValueMapFromFile(filePath);
    }
    
    //  plist書き込み
    void PlistIO::onWrite(const std::string& filePath)
    {
        FileUtils::getInstance()->writeToFile(data, filePath);
    }
}
}