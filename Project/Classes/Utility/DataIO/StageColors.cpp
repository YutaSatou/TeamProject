//
//  StageColors.cpp
//  TeamProject
//
//  Created by Satou yuta on 2016/01/10.
//
//

#include "StageColors.h"
#include "StageNumber.h"

using namespace cocos2d;

namespace
{
	const std::string ROOL = "Plist/StageData/";
	const std::string STAGE_KEY = "StageNumber";
	const std::string STAGE_CREATE_DIRECTORY = "StageData_";
	const std::string EXTENSION = ".plist";
}

void StageColors::saveColor( int colorR, int colorG, int colorB )
{
    std::string path = FileUtils::getInstance()->getWritablePath();
	StageNumber stageNumber;
    std::string file = path + "Stage" + StringUtils::toString( stageNumber.loadStageNumber() ) + "ColorData.plist";
    ValueMap data;
	data["name"] = ROOL + STAGE_CREATE_DIRECTORY + StringUtils::toString( stageNumber.loadStageNumber() ) + EXTENSION;
    data["ColorR"] = colorR;
    data["ColorG"] = colorG;
    data["ColorB"] = colorB;
    if ( FileUtils::getInstance()->writeToFile( data, file ) )
    {
        //CCLOG( "データを%sに書き出しました。", file.c_str() );
    }
    else
    {
        //CCLOG("Ops!");
    }
}

int StageColors::loadColorR( int stageNum )
{
    std::string path = FileUtils::getInstance()->getWritablePath();
	StageNumber stageNumber;
	std::string file = path + "Stage" + StringUtils::toString( stageNumber.loadStageNumber() ) + "ColorData.plist";
    ValueMap player = FileUtils::getInstance()->getValueMapFromFile( file.c_str() );
    
    int colorR = player["ColorR"].asInt();
    
    return colorR;
}

int StageColors::loadColorG( int stageNum )
{
    std::string path = FileUtils::getInstance()->getWritablePath();
	StageNumber stageNumber;
	std::string file = path + "Stage" + StringUtils::toString( stageNumber.loadStageNumber() ) + "ColorData.plist";
    ValueMap player = FileUtils::getInstance()->getValueMapFromFile( file.c_str() );
    
    int colorG = player["ColorG"].asInt();
    
    return colorG;
}

int StageColors::loadColorB( int stageNum )
{
    std::string path = FileUtils::getInstance()->getWritablePath();
	StageNumber stageNumber;
	std::string file = path + "Stage" + StringUtils::toString( stageNumber.loadStageNumber() ) + "ColorData.plist";
    ValueMap player = FileUtils::getInstance()->getValueMapFromFile( file.c_str() );
    
    int colorB = player["ColorB"].asInt();
    
    return colorB;
}

std::string StageColors::loadCreateStageNumber() const
{
	std::string path = FileUtils::getInstance()->getWritablePath();
	StageNumber stageNumber;
	std::string file = path + "Stage" + StringUtils::toString( stageNumber.loadStageNumber() ) + "ColorData.plist";
	ValueMap player = FileUtils::getInstance()->getValueMapFromFile( file.c_str() );
	
	std::string stageNum = player["name"].asString();
	
	return stageNum;
}