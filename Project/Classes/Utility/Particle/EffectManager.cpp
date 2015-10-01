//
//  EffectManager.cpp
//  TeamProject
//
//  Created by Satou yuta on 2015/09/28.
//
//

#include "EffectManager.h"

using namespace cocos2d;

ParticleBatchNode* EffectManagaer::createParticle(const std::string effectTex, const std::string plist, float directon, cocos2d::Vec2 effectPos){
    
    ParticleBatchNode* effectNode = ParticleBatchNode::create( effectTex );
    
    ParticleSystemQuad* particle = ParticleSystemQuad::create( plist );
    
    particle->setDuration( directon );
    
    particle->setAutoRemoveOnFinish( true );
    
    particle->setPosition( effectPos );
    
    effectNode->addChild( particle );
    
    return effectNode;
}



