//
//  ResultAnimation.hpp
//  TeamProject
//
//  Created by Satou yuta on 2015/11/27.
//
//

#ifndef _RESULTANIMATON_H_
#define _RESULTANIMATON_H_

#include <cocos2d.h>

class ResultAnimation{

protected:
    
    ~ResultAnimation() = default;
    
public:
    
    virtual void playAnimation() = 0;
    
    virtual void skipAnimation() = 0;

    bool isAnimation() const;
    
protected:
    
    bool mIsAnimation;

    ResultAnimation()
    : mIsAnimation( false ){
    }
    
};

inline bool ResultAnimation::isAnimation() const{
    return mIsAnimation;
}

#endif
