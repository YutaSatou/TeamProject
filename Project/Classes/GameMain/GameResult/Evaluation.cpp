//
//  Evaluation.cpp
//  TeamProject
//
//  Created by Satou yuta on 2015/11/16.
//
//

#include "Evaluation.h"
#include "Score.h"


using namespace cocos2d;
using namespace ui;

Evaluation::Evaluation(){

}

Evaluation::~Evaluation(){
}

bool Evaluation::init(){
	
	Score* score = Score::create();
	addChild( score );
    evaluation( score->getScore() );
	//CCLOG( "Score : %i", score->getScore() );
    return true;
}

Evaluation* Evaluation::create(){
    
    Evaluation* inst = new Evaluation();
    
    if ( inst && inst->init() ){
        inst->autorelease();
        return inst;
    }
    
    CC_SAFE_DELETE( inst );
    return nullptr;
}

EvaluationTag Evaluation::getTag(){

    return evaTag;
}

void Evaluation::evaluativeJudgment( EvaluationTag tag ){
    
    switch ( tag ) {
        case EvaluationTag::BAD:
            //CCLOG( "BAD" );
            break;
            
        case EvaluationTag::GOOD:
            //CCLOG( "GOOD" );
            break;
            
        case EvaluationTag::EXCELLENT:
            //CCLOG( "EXCELLENT" );
            break;
        case EvaluationTag::PERFECT:
            //CCLOG( "PERFECT" );
            break;
    }
    
    evaTag = tag;
}

void Evaluation::evaluation( int score ){
    
    if ( score <= 10 ){
        evaluativeJudgment( EvaluationTag::PERFECT );
    }
    if ( score <= 30 && score > 10 ){
        evaluativeJudgment( EvaluationTag::EXCELLENT );
    }
    if ( score <= 50 && score > 30 ){
        evaluativeJudgment( EvaluationTag::GOOD );
    }
    if ( score > 50 ){
        evaluativeJudgment( EvaluationTag::BAD );
    }
}