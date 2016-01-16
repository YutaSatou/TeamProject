//
//  Score.cpp
//  TeamProject
//
//  Created by Satou yuta on 2015/11/16.
//
//

#include "Score.h"
#include "ui/CocosGUI.h"
// #include "../../Utility/PlayerData/PlayerData.h"

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
    
    /*PlayerData::saveInt( "ColorR", 255 );
    PlayerData::saveInt( "ColorG", 255 );
    PlayerData::saveInt( "ColorB", 255 );*/
    
    //ゲームメインでプレイヤーが作った色
    // int playerR = PlayerData::loadInt( "ColorR" );
    // int playerG = PlayerData::loadInt( "ColorG" );
    // int playerB = PlayerData::loadInt( "ColorB" );
	
	/*
    //ゲームメインでプレイヤーが書いた線の長さ
    int lineLength = 1;
    
    //選んだステージの目標の色
    int stageR = 255;
    int stageG = 255;
    int stageB = 255;
	 */
	
	/*
    mScore = ( MAX( playerR, stageR ) - MIN( playerR, stageR ) )
           + ( MAX( playerG, stageG ) - MIN( playerG, stageG ) )
           + ( MAX( playerB, stageB ) - MIN( playerB, stageB ) )
           + lineLength;
    
    //CCLOG( "%i", mScore );
	 */
}

int Score::getScore() const{

    return mScore;
}