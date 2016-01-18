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

class StageColors{
    
protected:
    
public:
    
    StageColors() = default;
    
    ~StageColors() = default;
    
    static void saveColor( int colorR, int colorG, int colorB );
    
	int loadColorR( int stageNum );
    
	int loadColorG( int stageNum );
    
    int loadColorB( int stageNum );
	
	std::string loadCreateStageNumber() const;
	
private:
    
};

#endif
