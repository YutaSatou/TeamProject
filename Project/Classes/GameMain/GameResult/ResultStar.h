//
//  ResultStar.hpp
//  TeamProject
//
//  Created by Satou yuta on 2015/11/27.
//
//

#ifndef _RESULTSTAR_H_
#define _RESULTSTAR_H_

#include <cocos2d.h>
#include "ResultAnimation.h"

class ResultStar : public cocos2d::Node ,public ResultAnimation{
    
protected:
    
    ResultStar() = default;
    
    ~ResultStar() = default;
    
    virtual bool init() override;
    
public:
    
    static ResultStar* create();
    
    virtual void playAnimation() override;
    
    virtual void skipAnimation() override;
    
private:
    
    void drawStar( int StarNum, float delay );
    
    int mStarNum;
    
};


#endif
