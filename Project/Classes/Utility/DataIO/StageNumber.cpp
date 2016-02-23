//
//  StageNumber.cpp
//  TeamProject
//
//  Created by Satou yuta on 2015/12/11.
//
//

#include "StageNumber.h"
#include "../../Utility/DataIO/SaveData.h"

using namespace cocos2d;

namespace
{
    const std::string STAGE_KEY = "StageNumber";
	const std::string PLISTKEY = "Stage";
	const std::string EXTENSION = "ColorTargetData.plist";
}

void StageNumber::saveStageNumber( int stageNumber )
{

	SaveData::saveInt( STAGE_KEY.c_str(), stageNumber );
}

int StageNumber::loadStageNumber()
{
    
    int loadInt = SaveData::loadInt( STAGE_KEY.c_str() );
    
    return loadInt;
}

std::string StageNumber::readStagePlistName() const
{
	std::string path = FileUtils::getInstance()->getWritablePath();
	std::string fullPath = path + "Stage" + StringUtils::toString( loadStageNumber() ) + "ColorData.plist";
	ValueMap player = FileUtils::getInstance()->getValueMapFromFile( fullPath.c_str() );
	
	std::string stageNum = player["name"].asString();
	
	return stageNum;
}

