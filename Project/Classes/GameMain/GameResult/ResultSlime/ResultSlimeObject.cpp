//
//  ResultSlimeObject.cpp
//  TeamProject
//
//  Created by Satou yuta on 2016/01/15.
//
//

#include "ResultSlimeObject.h"
#include "../../../Utility/DataIO/StageNumber.h"
#include "../../../Utility/DataIO/StageColors.h"

using namespace cocos2d;

namespace
{
    const uint16_t PARTICLE_TYPE
    {
        LiquidFunParticleType::b2_reactiveParticle |
		LiquidFunParticleType::b2_viscousParticle |
		LiquidFunParticleType::b2_barrierParticle
    };
}

// コンストラクタ
ResultSlimeObject::ResultSlimeObject()
{
    
}

// 初期化
bool ResultSlimeObject::init()
{
    if ( !Node::init() )
    {
        return false;
    }
    
    // スケジュール登録を行う。
    scheduleUpdate();
    
    // 各パラメータを設定する。
    setName( "AAAAAAA" );
    setContentSize( { 64.0f, 64.0f } );
    setAnchorPoint( Vec2::ANCHOR_MIDDLE );
    setPosition( Vec2::ZERO );
    
    // 液体関係の初期化を行う。
    initParticle();
    registerTexture( "Texture/GameResult/Particle_20x20.png" );
    setupContactCallback();
    
    return true;
}

// 更新
void ResultSlimeObject::update( float deltaTime )
{
    // 基底クラスの更新を行う。
    LiquidObject::update( deltaTime );
    
    // パーティクルの更新を行う。
    updateParticle();
}

// インスタンスの生成
ResultSlimeObject* ResultSlimeObject::create()
{
    ResultSlimeObject* inst { new ResultSlimeObject() };
    
    if ( inst && inst->init() )
    {
        inst->autorelease();
        return inst;
    }
    
    CC_SAFE_DELETE( inst );
    return nullptr;
}

// パーティクルの初期化
void ResultSlimeObject::initParticle()
{
	//メインで作った色を取得
	StageNumber stageNumber;
	StageColors stageColor;
	int stageNum = stageNumber.loadStageNumber();
	int colorR = stageColor.loadColorR( stageNum );
	int colorG = stageColor.loadColorG( stageNum );
	int colorB = stageColor.loadColorB( stageNum );
    // パーティクルの生成に必要な設定記述子を生成する。
    LiquidFunParticleDescCreator	creator;
    LiquidFunParticleDesc			particleDesc	{ creator.createParticleDesc( 10.0f ) };
	LiquidFunParticleGroupDesc		groupDesc		{ creator.createParticleGroupDesc( Color3B( colorR, colorG, colorB ), { 360, 1280 }, PARTICLE_TYPE, 150, 120 ) };
    
    // パーティクルを装着する。
    mParticle		= LiquidFunParticleSettlor::attachParticle( particleDesc );
    mParticleGroup	= LiquidFunParticleSettlor::attachParticleGroup( mParticle, groupDesc );
    
    // 液体挙動を無効化する。
    //disableLiquidBehavior();
}