//
//  Score.h
//  TeamProject
//
//  Created by Satou yuta on 2015/11/16.
//
//

#ifndef _SCORE_H_
#define _SCORE_H_

#include "cocos2d.h"

class Score : public cocos2d::Ref{
    
protected:
    
    Score();
    
    ~Score();
    
    bool init();

public:
    
    static Score* create();
    
    int getScore() const;
    
private:
    
    void score();
    
private:
    
    //メンバー変数
    int mScore;
    
    
    
};

#endif
