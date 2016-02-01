//
//  Score.cpp
//  TeamProject
//
//  Created by Satou yuta on 2015/11/16.
//
//

#include "Score.h"
#include "ui/CocosGUI.h"
#include "../../Utility/DataIO/StageColorInfo.h"
#include "../../Utility/DataIO/StageNumber.h"
#include "../../Utility/DataIO/TargetColor.h"

using namespace cocos2d;
using namespace ui;

Score::Score()
: mScore( 0 ){

}

Score::~Score(){
    
}

bool Score::init(){
    
    score();
    
    return true;
}

Score* Score::create(){
    
    Score* inst = new Score();

    if ( inst && inst->init() ){
        inst->autorelease();
        return inst;
    }
    
    CC_SAFE_DELETE( inst );
    return nullptr;
}

void Score::score(){
    
	StageNumber stageNumber;
	StageColorInfo stageColor;
	//ゲームメインでプレイヤーが作った色
	int stageNum = stageNumber.loadStageNumber();
	int playerR = stageColor.loadColorR( stageNum );
	int playerG = stageColor.loadColorG( stageNum );
	int playerB = stageColor.loadColorB( stageNum );
	
	//CCLOG( "Player : %i, %i, %i", playerR, playerG, playerB );
	
	//ゲームメインでプレイヤーが書いた線の長さ
	//int lineLength = 1;
	
	//選んだステージの目標の色
	TargetColor clearColor;
	Color3B color = clearColor.ColorTargetRead();
	int stageR = color.r;
	int stageG = color.g;
	int stageB = color.b;
	
    mScore = ( MAX( playerR, stageR ) - MIN( playerR, stageR ) )
           + ( MAX( playerG, stageG ) - MIN( playerG, stageG ) )
           + ( MAX( playerB, stageB ) - MIN( playerB, stageB ) )
           /*+ lineLength*/;
    
    //CCLOG( "%i", mScore );
}

int Score::getScore() const{

    return mScore;
}