//
//  StageColors.hpp
//  TeamProject
//
//  Created by Satou yuta on 2016/01/10.
//
//

#ifndef RESULTDATA_H_
#define RESULTDATA_H_

#include "cocos2d.h"

class ResultData
{
    
protected:
    
public:
    
    ResultData() = default;
    
    ~ResultData() = default;
	
	static void initColor();
    
    static void saveColor( cocos2d::Color3B color3b, bool isClear );
    
	int readColorR( int stageNum );
    
	int readColorG( int stageNum );
    
    int readColorB( int stageNum );
	
private:
	
	std::string readColorDataPlist() const;
    
};

#endif
