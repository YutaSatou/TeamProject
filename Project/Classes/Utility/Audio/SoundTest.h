//
//  SoundTest.h
//  TeamProject
//
//  Created by Satou yuta on 2015/07/29.
//
//

#ifndef _SOUNDTEST_H_
#define _SOUNDTEST_H_

#include <stdio.h>
#include "cocos2d.h"
#include "Utility/Audio/ADX2Player.h"

class SoundTest : public cocos2d::Layer{
    
protected:
    
    SoundTest();
    
    ~SoundTest();
    
    virtual bool init() override;
    
    virtual void update( float deltaTime ) override;

    
public:
    
    static SoundTest* createScene();
    
    ADX2Player* ply;
    
    CREATE_FUNC(SoundTest);
};

#endif /* defined(__TeamProject__SoundTest__) */
