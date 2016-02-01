//
//  PlayerData.h
//  TeamProject
//
//  Created by Satou yuta on 2015/11/16.
//
//

#ifndef _SAVEDATA_H_
#define _SAVEDATA_H_

#include "cocos2d.h"

class SaveData : public cocos2d::Node{

protected:
    
    SaveData() = default;
    
    ~SaveData() = default;
    
    virtual bool init() override;
    
public:
    
    static void saveInt( const std::string& key, int value );
    static void saveString( const std::string& key, const std::string& string );
    static void saveBool( const std::string& key, bool flg );
    
    static int loadInt( const std::string& key );
    static std::string loadString( const std::string& key );
    static bool loadBool( const std::string& key );
    
};

#endif
