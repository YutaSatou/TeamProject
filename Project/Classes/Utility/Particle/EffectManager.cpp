//
//  EffectManager.cpp
//  TeamProject
//
//  Created by Satou yuta on 2015/09/28.
//
//

#include "EffectManager.h"

using namespace cocos2d;

void EffectManagaer::createParticle( Node* particleNode, const std::string& plist, const cocos2d::Vec2& effectPos ){
    
    ParticleSystemQuad* particle = ParticleSystemQuad::create( "Effect/" + plist + ".plist" );
    
    particle->setAutoRemoveOnFinish( true );
    
    particle->setPosition( effectPos );
    
    particleNode->addChild( particle );
}



