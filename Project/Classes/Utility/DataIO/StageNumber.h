//
//  StageNumber.hpp
//  TeamProject
//
//  Created by Satou yuta on 2015/12/11.
//
//

#ifndef _STAGENUMBER_H_
#define _STAGENUMBER_H_

#include "cocos2d.h"

class StageNumber{
    
protected:
    
public:
    
    StageNumber() = default;
    
    ~StageNumber() = default;
    
    static void saveStageNumber( int stageNumber );
    
    static int loadStageNumber();
	
	std::string loadPlistName() const;
};

#endif
