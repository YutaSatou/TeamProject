//
//  StageNumber.cpp
//  TeamProject
//
//  Created by Satou yuta on 2015/12/11.
//
//

#include "StageNumber.h"
#include "../../Utility/DataIO/DataIO.h"

using namespace cocos2d;

namespace
{
    const std::string STAGE_KEY = "StageNumber";
	const std::string PLISTKEY = "Stage";
	const std::string EXTENSION = "ColorTargetData.plist";
}

void StageNumber::saveStageNumber( int stageNumber ){

	DataIO::saveInt( STAGE_KEY.c_str(), stageNumber );
}

int StageNumber::loadStageNumber(){
    
    int loadInt = DataIO::loadInt( STAGE_KEY.c_str() );
    
    return loadInt;
}

std::string StageNumber::loadPlistName() const
{
	StageNumber stageNumber;
	std::string root = "Plist/StageClearTarget/";
	std::string path = FileUtils::getInstance()->fullPathForFilename( root + PLISTKEY.c_str() + StringUtils::toString( stageNumber.loadStageNumber() ) + EXTENSION.c_str() );
	ValueMap player = FileUtils::getInstance()->getValueMapFromFile( path.c_str() );
	
	std::string plistName = player["Name"].asString();
	
	return plistName;

}

