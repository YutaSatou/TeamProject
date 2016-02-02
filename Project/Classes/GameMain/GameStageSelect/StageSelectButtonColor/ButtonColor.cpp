//
//  ButtonColor.cpp
//  TeamProject
//
//  Created by Satou yuta on 2016/02/01.
//
//

#include "ButtonColor.h"

using namespace cocos2d;

std::string ButtonColor::loadPlist( int stageNum ) const
{
	std::string path = FileUtils::getInstance()->getWritablePath();
	std::string fullPath = path + "Stage" + StringUtils::toString( stageNum ) + "ColorData.plist";
	
	return fullPath;
}

bool ButtonColor::isStageClear( int stageNum )
{
	std::string path = loadPlist( stageNum );
	ValueMap player = FileUtils::getInstance()->getValueMapFromFile( path.c_str() );
	
	if ( player["Clear"].isNull() )
	{
		return false;
	}
	
	bool isClear = player["Clear"].asBool();
	
	return isClear;
}

Color3B ButtonColor::buttonColor( int stageNum )
{
	std::string path = loadPlist( stageNum );
	ValueMap player = FileUtils::getInstance()->getValueMapFromFile( path.c_str() );
	
	if ( player["Clear"].isNull() )
	{
		return Color3B::WHITE;
	}
	
	Color3B color = Color3B( player["ColorR"].asInt(), player["ColorG"].asInt(), player["ColorB"].asInt() );
	
	return color;
}
