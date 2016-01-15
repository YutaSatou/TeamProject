//
//  StageSelectButton.hpp
//  TeamProject
//
//  Created by Satou yuta on 2015/12/07.
//
//

#ifndef _STAGESELECTBUTTON_H_
#define _STAGESELECTBUTTON_H_

#include "cocos2d.h"

class StageSelectButton : public cocos2d::Node
{
    
protected:
    
    StageSelectButton() = default;
    
    ~StageSelectButton() = default;
    
    bool init();
    
public:
    
    static StageSelectButton* create();
    
};

#endif
