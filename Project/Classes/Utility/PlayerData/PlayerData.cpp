//
//  PlayerData.cpp
//  TeamProject
//
//  Created by Satou yuta on 2015/11/16.
//
//

#include "PlayerData.h"

using namespace cocos2d;

bool PlayerData::init(){

    if ( !Node::init() ){
        
        return false;
    }
    
    return true;
}

void PlayerData::saveInt( const char* key, int value ){

    UserDefault* userDefault = UserDefault::getInstance();
    
    userDefault->setIntegerForKey( key, value );
    
    userDefault->flush();
}

void PlayerData::saveString(const char* key, const std::string& string ){

    UserDefault* userDefault = UserDefault::getInstance();
    
    userDefault->setStringForKey( key, string );
    
    userDefault->flush();
}

void PlayerData::saveBool( const char* key, bool flg ){

    UserDefault* userDefault = UserDefault::getInstance();
    
    userDefault->setBoolForKey( key, flg );
    
    userDefault->flush();
}

int PlayerData::loadInt( const char* key ){

    UserDefault* userDefault = UserDefault::getInstance();
    
    int value = userDefault->getIntegerForKey( key );
    
    return value;
}

std::string PlayerData::loadString( const char* key ){

    UserDefault* userDefault = UserDefault::getInstance();
    
    std::string string = userDefault->getStringForKey( key );
    
    return string;
}

bool PlayerData::loadBool( const char* key ){

    UserDefault* userDefault = UserDefault::getInstance();
    
    bool flg = userDefault->getBoolForKey( key );
    
    return flg;
}

