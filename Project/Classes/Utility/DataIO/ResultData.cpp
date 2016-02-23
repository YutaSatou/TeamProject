//
//  StageColors.cpp
//  TeamProject
//
//  Created by Satou yuta on 2016/01/10.
//
//

#include "ResultData.h"
#include "StageNumber.h"

using namespace cocos2d;

namespace
{
	const std::string ROOL = "Plist/StageData/";
	const std::string STAGE_KEY = "StageNumber";
	const std::string STAGE_CREATE_DIRECTORY = "StageData_";
	const std::string EXTENSION = ".plist";
}

std::string ResultData::readColorDataPlist() const
{
	std::string path = FileUtils::getInstance()->getWritablePath();
	StageNumber stageNumber;
	std::string fullPath = path + "Stage" + StringUtils::toString( stageNumber.loadStageNumber() ) + "ColorData.plist";
	
	return fullPath;
}

void ResultData::initColor()
{
	std::string path = FileUtils::getInstance()->getWritablePath();
	StageNumber stageNumber;
	std::string file = path + "Stage" + StringUtils::toString( stageNumber.loadStageNumber() ) + "ColorData.plist";
	ValueMap data;
	data["name"] = ROOL + STAGE_CREATE_DIRECTORY + StringUtils::toString( stageNumber.loadStageNumber() ) + EXTENSION;
	ValueMap player = FileUtils::getInstance()->getValueMapFromFile( file.c_str() );
	if ( !player["Clear"].isNull() )
	{
		std::string path = FileUtils::getInstance()->getWritablePath();
		StageNumber stageNumber;
		std::string fullPath = path + "Stage" + StringUtils::toString( stageNumber.loadStageNumber() ) + "ColorData.plist";
		data["ColorR"] = player["ColorR"];
		data["ColorG"] = player["ColorG"];
		data["ColorB"] = player["ColorB"];
		data["Clear"] = player["Clear"];
		CCLOG( "ISIS" );
	}
	if ( FileUtils::getInstance()->writeToFile( data, file ) )
	{
	}
}

void ResultData::saveColor( Color3B color3b, bool isClear )
{
    std::string path = FileUtils::getInstance()->getWritablePath();
	StageNumber stageNumber;
    std::string file = path + "Stage" + StringUtils::toString( stageNumber.loadStageNumber() ) + "ColorData.plist";
    ValueMap data;
	data["name"] = ROOL + STAGE_CREATE_DIRECTORY + StringUtils::toString( stageNumber.loadStageNumber() ) + EXTENSION;
    data["ColorR"] = (int)color3b.r;
    data["ColorG"] = (int)color3b.g;
    data["ColorB"] = (int)color3b.b;
	data["Clear"] = isClear;
    if ( FileUtils::getInstance()->writeToFile( data, file ) )
    {
		//CCLOG( "%s", file.c_str() );
    }
}

int ResultData::readColorR( int stageNum )
{
	std::string fullPath = readColorDataPlist();
    ValueMap player = FileUtils::getInstance()->getValueMapFromFile( fullPath.c_str() );
    
    int colorR = player["ColorR"].asInt();
    
    return colorR;
}

int ResultData::readColorG( int stageNum )
{
	std::string fullPath = readColorDataPlist();
    ValueMap player = FileUtils::getInstance()->getValueMapFromFile( fullPath.c_str() );
    
    int colorG = player["ColorG"].asInt();
    
    return colorG;
}

int ResultData::readColorB( int stageNum )
{
	std::string fullPath = readColorDataPlist();
    ValueMap player = FileUtils::getInstance()->getValueMapFromFile( fullPath.c_str() );
    
    int colorB = player["ColorB"].asInt();
    
    return colorB;
}