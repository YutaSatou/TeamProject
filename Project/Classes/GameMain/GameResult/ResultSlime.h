//
//  ResultSlime.hpp
//  TeamProject
//
//  Created by Satou yuta on 2015/11/28.
//
//

#ifndef _RESULTSLIME_H_
#define _RESULTSLIME_H_

#include <cocos2d.h>
#include "ResultAnimation.h"
#include "../../Utility/Audio/ADX2Player.h"

class ResultSlime : public cocos2d::Node, public ResultAnimation{

protected:
    
    ResultSlime() = default;
    
    ~ResultSlime();
    
    virtual bool init() override;
    
public:
    
    static ResultSlime* create();
    
    virtual void playAnimation() override;
    
    virtual void skipAnimation() override;
    
private:
    
    int mBGM;
    
};

#endif
