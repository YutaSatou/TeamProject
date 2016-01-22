//
//  ClearColor.cpp
//  TeamProject
//
//  Created by Satou yuta on 2016/01/17.
//
//

#include "ClearColor.h"
#include "StageNumber.h"

using namespace cocos2d;

namespace{
	
	const std::string STAGE_KEY = "Stage";
	const std::string EXTENSION = "ColorTargetData.plist";
}

Color3B ClearColor::ColorTargetRead()
{
	StageNumber stageNumber;
	std::string root = "Plist/StageClearTarget/";
	std::string path = FileUtils::getInstance()->fullPathForFilename( root + STAGE_KEY.c_str() + StringUtils::toString( stageNumber.loadStageNumber() ) + EXTENSION.c_str() );
	ValueMap player = FileUtils::getInstance()->getValueMapFromFile( path.c_str() );
	
	Color3B Color = Color3B( player["ColorR"].asInt(), player["ColorG"].asInt(), player["ColorB"].asInt() );
	
	return Color;
}