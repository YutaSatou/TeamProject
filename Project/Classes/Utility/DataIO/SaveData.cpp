//
//  PlayerData.cpp
//  TeamProject
//
//  Created by Satou yuta on 2015/11/16.
//
//

#include "SaveData.h"

using namespace cocos2d;

bool SaveData::init()
{

    if ( !Node::init() )
	{
        
        return false;
    }
    
    return true;
}

void SaveData::saveInt( const std::string& key, int value )
{

    UserDefault* userDefault = UserDefault::getInstance();
    
    userDefault->setIntegerForKey( key.c_str(), value );
    
    userDefault->flush();
}

void SaveData::saveString( const std::string& key, const std::string& string )
{

    UserDefault* userDefault = UserDefault::getInstance();
    
    userDefault->setStringForKey( key.c_str(), string );
    
    userDefault->flush();
}

void SaveData::saveBool( const std::string& key, bool flg )
{

    UserDefault* userDefault = UserDefault::getInstance();
    
    userDefault->setBoolForKey( key.c_str(), flg );
    
    userDefault->flush();
}

int SaveData::loadInt( const std::string& key )
{

    UserDefault* userDefault = UserDefault::getInstance();
    
    int value = userDefault->getIntegerForKey( key.c_str() );
    
    return value;
}

std::string SaveData::loadString( const std::string& key )
{

    UserDefault* userDefault = UserDefault::getInstance();
    
    std::string string = userDefault->getStringForKey( key.c_str() );
    
    return string;
}

bool SaveData::loadBool( const std::string& key )
{

    UserDefault* userDefault = UserDefault::getInstance();
    
    bool flg = userDefault->getBoolForKey( key.c_str() );
    
    return flg;
}

