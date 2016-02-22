//
//  ClearColor.cpp
//  TeamProject
//
//  Created by Satou yuta on 2016/01/17.
//
//

#include "TargetColor.h"
#include "StageNumber.h"

using namespace cocos2d;

namespace
{	
	const std::string PLISTROOT = "Plist/ResultData/";
	const std::string STAGE_KEY = "ResultData_";
	const std::string EXTENSION = ".plist";
}

Color3B TargetColor::readColorTarget() const
{
	StageNumber stageNumber;
	std::string path = FileUtils::getInstance()->fullPathForFilename( PLISTROOT + STAGE_KEY + StringUtils::toString( stageNumber.loadStageNumber() ) + EXTENSION );
	ValueMap player = FileUtils::getInstance()->getValueMapFromFile( path.c_str() );
	
	Color3B color = Color3B( player["ColorR"].asInt(), player["ColorG"].asInt(), player["ColorB"].asInt() );
	
	return color;
}