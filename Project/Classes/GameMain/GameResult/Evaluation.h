//
//  Evaluation.h
//  TeamProject
//
//  Created by Satou yuta on 2015/11/16.
//
//

#ifndef _EVALUATION_H_
#define _EVALUATION_H_

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "EvaluationTag.h"

class Score;

class Evaluation : public cocos2d::Node{
    
protected:
    Evaluation();
    
    ~Evaluation();
    
    virtual bool init() override;
    
public:
    
    static Evaluation* create();
    
    EvaluationTag getTag();
    
private:
    
    void evaluativeJudgment( EvaluationTag );
    
    void evaluation( int score );
        
private:
    
    EvaluationTag evaTag;
    
    Score* mScore;
    
        
};

#endif
