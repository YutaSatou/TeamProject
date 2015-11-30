//
//  PlayerData.h
//  TeamProject
//
//  Created by Satou yuta on 2015/11/16.
//
//

#ifndef _PALYERDATA_H_
#define _PALYERDATA_H_

#include "cocos2d.h"

class PlayerData : public cocos2d::Node{

protected:
    
    PlayerData() = default;
    
    ~PlayerData() = default;
    
    virtual bool init() override;
    
public:
    
    static void saveInt( const char* key, int value );
    static void saveString( const char* key, const std::string& string );
    static void saveBool( const char* key, bool flg );
    
    static int loadInt( const char* key );
    static std::string loadString( const char* key );
    static bool loadBool( const char* key );
    
};

#endif
