//
//  StageColors.hpp
//  TeamProject
//
//  Created by Satou yuta on 2016/01/10.
//
//

#ifndef StageColors_h
#define StageColors_h

#include "cocos2d.h"

class StageColorInfo
{
    
protected:
    
public:
    
    StageColorInfo() = default;
    
    ~StageColorInfo() = default;
	
	std::string loadCreateStageNumber() const;
	
	static void initColor();
    
    static void saveColor( cocos2d::Color3B color3b, bool isClear );
    
	int loadColorR( int stageNum );
    
	int loadColorG( int stageNum );
    
    int loadColorB( int stageNum );
	
private:
	
	std::string readColorDataPlist() const;
    
};

#endif
