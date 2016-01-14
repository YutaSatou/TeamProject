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
    const std::string STAGE_CREATE_DIRECTORY = "StageData_";
    const std::string EXTENSION = ".plist";
}

void StageNumber::saveStageNumber( int stageNumber ){

    DataIO::saveString( STAGE_KEY.c_str(), STAGE_CREATE_DIRECTORY + StringUtils::toString( stageNumber ) + EXTENSION );
}

std::string StageNumber::loadStageNumber(){
    
    std::string loadstring = DataIO::loadString( STAGE_KEY.c_str() );
    
    return loadstring;
}


