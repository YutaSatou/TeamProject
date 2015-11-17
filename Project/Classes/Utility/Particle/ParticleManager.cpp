//
//  ParticlePool.cpp
//  TeamProject
//
//  Created by Satou yuta on 2015/11/09.
//
//

#include "ParticleManager.h"
#include "SimpleParticle.h"

using namespace cocos2d;

ParticleManager* ParticleManager::createPool( const std::string& fileName, const size_t& instanceNum ){
    
    ParticleManager* inst = new ParticleManager();
    
    if ( inst && inst->init( fileName, instanceNum ) ){
        //inst->autorelease();
        return inst;
    }
    
    CC_SAFE_DELETE( inst );
    return nullptr;
}

bool ParticleManager::init( const std::string& fileName, const size_t& instanceNum  ){
    
    for ( int i = 0; i < instanceNum; i++ ){
        
        SimpleParticle* particle = SimpleParticle::create( fileName );
        mFileName = fileName;
        particle->onFinishListener = [this]( SimpleParticle* sender ){
            //パーティクルの表示が終わったら自動的に戻す
            push( sender );
            sender->release();
        };
        particle->setAutoRemoveOnFinish( true );
        //停止した状態で格納する
        particle->stopSystem();
        push( particle );
    }
    
    return true;
}

void ParticleManager::newCreateParticle(){

    SimpleParticle* particle = SimpleParticle::create( mFileName );
    particle->onFinishListener = [this]( SimpleParticle* sender ){
        //パーティクルの表示が終わったら自動的に戻す
        push( sender );
        sender->release();
    };
    particle->setAutoRemoveOnFinish( true );
    //停止した状態で格納する
    particle->stopSystem();
    push( particle );
}

void ParticleManager::push( SimpleParticle* particle ){

    pool.push_back( particle );
}

SimpleParticle* ParticleManager::playParicle( Node* node, const Vec2& pos ){

    if ( pool.empty() ){
        newCreateParticle();
        SimpleParticle* particle = pool.back();
        particle->retain();
        pool.pop_back();
        particle->resetSystem();
        
        particle->setPosition( pos );
        node->addChild( particle );
        
        return particle;
    }
    
    SimpleParticle* particle = pool.back();
    particle->retain();
    pool.pop_back();
    particle->resetSystem();
    
    particle->setPosition( pos );
    node->addChild( particle );
    
    return particle;
}
