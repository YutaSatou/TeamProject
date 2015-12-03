//
//  ResultEvaluation.hpp
//  TeamProject
//
//  Created by Satou yuta on 2015/11/28.
//
//

#ifndef _RESULTEVALUATION_H_
#define _RESULTEVALUATION_H_

#include <cocos2d.h>
#include "ResultAnimation.h"

class ResultEvaluation : public cocos2d::Node, public ResultAnimation{

protected:
    
    ResultEvaluation() = default;
    
    ~ResultEvaluation() = default;
    
    virtual bool init() override;
    
public:
    
    static ResultEvaluation* create();
    
    virtual void playAnimation() override;
    
    virtual void skipAnimation() override;
    
    std::function<void(ResultEvaluation*)> m_callback;
    
private:
    
};

#endif
