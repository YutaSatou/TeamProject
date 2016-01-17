//
//  ResultManager.hpp
//  TeamProject
//
//  Created by Satou yuta on 2015/11/28.
//
//

#ifndef _RESULTMANAGER_H_
#define _RESULTMANAGER_H_

#include <cocos2d.h>

class ResultEvaluation;
class ResultSlime;
class ResultStar;

namespace{
    enum TouchAnimationTag{
        SKIP_SPRITE = 0,
        SKIP_SLIME,
        SKIP_STAR,
        SCENE_CHANGE,
        LENGTH,
    };
}

class ResultManager : public cocos2d::Node{
    
protected:
    
    ResultManager();
    
    ~ResultManager();

    virtual bool init() override;
    
public:
    
    static ResultManager* create();
    
    void touchAction();
    
    int mTouchCount;
    
    bool mIsAnimationEnd;
    
    void initFunc();
    
private:
    
    ResultEvaluation* mEvaluation;
    ResultSlime* mSlime;
    ResultStar* mStar;
    std::function< void() >	mTouch[ TouchAnimationTag::LENGTH ];
    TouchAnimationTag mTouchAnimationTag;
};

#endif
