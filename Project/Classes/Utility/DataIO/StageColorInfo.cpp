//
//  StageColors.cpp
//  TeamProject
//
//  Created by Satou yuta on 2016/01/10.
//
//

#include "StageColorInfo.h"
#include "StageNumber.h"

using namespace cocos2d;

namespace
{
	const std::string ROOL = "Plist/StageData/";
	const std::string STAGE_KEY = "StageNumber";
	const std::string STAGE_CREATE_DIRECTORY = "StageData_";
	const std::string EXTENSION = ".plist";
}

void StageColorInfo::initColor( Color3B color3b )
{
	std::string path = FileUtils::getInstance()->getWritablePath();
	StageNumber stageNumber;
	std::string file = path + "Stage" + StringUtils::toString( stageNumber.loadStageNumber() ) + "ColorData.plist";
	ValueMap data;
	data["name"] = ROOL + STAGE_CREATE_DIRECTORY + StringUtils::toString( stageNumber.loadStageNumber() ) + EXTENSION;
	if ( FileUtils::getInstance()->writeToFile( data, file ) )
	{
	}
}

void StageColorInfo::saveColor( Color3B color3b )
{
    std::string path = FileUtils::getInstance()->getWritablePath();
	StageNumber stageNumber;
    std::string file = path + "Stage" + StringUtils::toString( stageNumber.loadStageNumber() ) + "ColorData.plist";
    ValueMap data;
	data["name"] = ROOL + STAGE_CREATE_DIRECTORY + StringUtils::toString( stageNumber.loadStageNumber() ) + EXTENSION;
    data["ColorR"] = (int)color3b.r;
    data["ColorG"] = (int)color3b.g;
    data["ColorB"] = (int)color3b.b;
    if ( FileUtils::getInstance()->writeToFile( data, file ) )
    {
    }
}

std::string StageColorInfo::readColorDataPlist() const
{
	std::string path = FileUtils::getInstance()->getWritablePath();
	StageNumber stageNumber;
	std::string fullPath = path + "Stage" + StringUtils::toString( stageNumber.loadStageNumber() ) + "ColorData.plist";
	
	return fullPath;
}

int StageColorInfo::loadColorR( int stageNum )
{
	std::string fullPath = readColorDataPlist();
    ValueMap player = FileUtils::getInstance()->getValueMapFromFile( fullPath.c_str() );
    
    int colorR = player["ColorR"].asInt();
    
    return colorR;
}

int StageColorInfo::loadColorG( int stageNum )
{
	std::string fullPath = readColorDataPlist();
    ValueMap player = FileUtils::getInstance()->getValueMapFromFile( fullPath.c_str() );
    
    int colorG = player["ColorG"].asInt();
    
    return colorG;
}

int StageColorInfo::loadColorB( int stageNum )
{
	std::string fullPath = readColorDataPlist();
    ValueMap player = FileUtils::getInstance()->getValueMapFromFile( fullPath.c_str() );
    
    int colorB = player["ColorB"].asInt();
    
    return colorB;
}

std::string StageColorInfo::loadCreateStageNumber() const
{
	std::string fullPath = readColorDataPlist();
	ValueMap player = FileUtils::getInstance()->getValueMapFromFile( fullPath.c_str() );
	
	std::string stageNum = player["name"].asString();
	
	return stageNum;
}