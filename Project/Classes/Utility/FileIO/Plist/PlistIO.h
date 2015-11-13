//
//  PlistIO.h
//  PSStageCreate
//
//  Created by 星共法 on 2015/10/26.
//
//

#ifndef _PlistIO__
#define _PlistIO__

#include "cocos2d.h"

namespace Utility
{
namespace FileIO
{
    class PlistIO
    {
    public:
        PlistIO();
        ~PlistIO();
        
        void onRead(const std::string& path);   //  plist読み込み
        void onWrite(const std::string& path);  //  plist書き込み
        
    public:
        cocos2d::ValueMap data;
    };
}
}
    
#endif /* defined(_PlistIO__) */
