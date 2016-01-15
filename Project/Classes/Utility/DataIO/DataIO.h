//
//  PlayerData.h
//  TeamProject
//
//  Created by Satou yuta on 2015/11/16.
//
//

#ifndef _DATAIO_H_
#define _DATAIO_H_

#include "cocos2d.h"

class DataIO : public cocos2d::Node{

protected:
    
    DataIO() = default;
    
    ~DataIO() = default;
    
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
