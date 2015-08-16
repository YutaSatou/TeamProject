//
//  SoundTest.h
//  TeamProject
//
//  Created by Satou yuta on 2015/07/29.
//
//

#ifndef __TeamProject__SoundTest__
#define __TeamProject__SoundTest__

#include <stdio.h>
#include "cocos2d.h"
#include "Utility/Audio/ADX2Player.h"

class SoundTest : public cocos2d::Layer{
    
protected:
    
    SoundTest();
    ~SoundTest();
    bool init();
    virtual void update(float dt);
    
public:
    
    static cocos2d::Scene* createScene();
    
    ADX2Player* ply;
    
    CREATE_FUNC(SoundTest);
};

#endif /* defined(__TeamProject__SoundTest__) */
