//
//  PlayerData.cpp
//  TeamProject
//
//  Created by Satou yuta on 2015/11/16.
//
//

#include "DataIO.h"

using namespace cocos2d;

bool DataIO::init(){

    if ( !Node::init() ){
        
        return false;
    }
    
    return true;
}

void DataIO::saveInt( const char* key, int value ){

    UserDefault* userDefault = UserDefault::getInstance();
    
    userDefault->setIntegerForKey( key, value );
    
    userDefault->flush();
}

void DataIO::saveString(const char* key, const std::string& string ){

    UserDefault* userDefault = UserDefault::getInstance();
    
    userDefault->setStringForKey( key, string );
    
    userDefault->flush();
}

void DataIO::saveBool( const char* key, bool flg ){

    UserDefault* userDefault = UserDefault::getInstance();
    
    userDefault->setBoolForKey( key, flg );
    
    userDefault->flush();
}

int DataIO::loadInt( const char* key ){

    UserDefault* userDefault = UserDefault::getInstance();
    
    int value = userDefault->getIntegerForKey( key );
    
    return value;
}

std::string DataIO::loadString( const char* key ){

    UserDefault* userDefault = UserDefault::getInstance();
    
    std::string string = userDefault->getStringForKey( key );
    
    return string;
}

bool DataIO::loadBool( const char* key ){

    UserDefault* userDefault = UserDefault::getInstance();
    
    bool flg = userDefault->getBoolForKey( key );
    
    return flg;
}

