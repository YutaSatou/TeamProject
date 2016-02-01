//
//  ParticlePool.cpp
//  TeamProject
//
//  Created by Satou yuta on 2015/11/09.
//
//

#include "cocos2d.h"
#include "ParticleManager.h"
#include "SingleParticle.h"

using namespace cocos2d;

namespace
{
    
    static const std::map< ParticleType, std::string> ParticleToPath
	{
        
        { ParticleType::SPLASH,   "Ring" },
        { ParticleType::LINE,     "Star" },
    };
}

ParticleManager::ParticleManager()
: mFileName( ){
}

ParticleManager::~ParticleManager()
{
    //パーティクルプールの開放
    std::for_each( mPool.begin(), mPool.end(),[]( SingleParticle* particle )
	{
        CC_SAFE_RELEASE( particle );
    } );
    mPool.clear();
}

ParticleManager* ParticleManager::createPool( const ParticleType type, const size_t& instanceNum )
{
    
    ParticleManager* inst = new ParticleManager();
    
    if ( inst && inst->init( type, instanceNum ) )
	{
        inst->autorelease();
        return inst;
    }
    
    CC_SAFE_DELETE( inst );
    return nullptr;
}

bool ParticleManager::init( const ParticleType type, const size_t& instanceNum )
{
    
    for ( int i = 0; i < instanceNum; i++ )
	{
        //パーティクルを作成してVectorに格納しておく
        SingleParticle* particle = SingleParticle::create( "Plist/Particle/" + ParticleToPath.at( type ) + ".plist" );
        mFileName= type;
        particle->onFinishListener = [ = ]( SingleParticle* sender)
		{
            //参照カウンタ１で戻す
            this->push( sender );
        };
        particle->retain();
        particle->stopSystem();
        particle->setAutoRemoveOnFinish( true );
        push( particle );
    }
    
    return true;
}

void ParticleManager::push( SingleParticle* particle )
{

    mPool.push_back( particle );
}

void ParticleManager::newParticle()
{

    SingleParticle* particle = SingleParticle::create( "Plist/Particle/" + ParticleToPath.at( mFileName ) + ".plist" );
    particle->onFinishListener = [ = ]( SingleParticle* sender)
	{
        this->push( sender );
    };
    particle->retain();
    particle->stopSystem();
    particle->setAutoRemoveOnFinish( true );
    push( particle );
}

void ParticleManager::playParicle( Node* node, const Vec2& pos )
{

    //プールの中身が空だったら新しくパーティクルを作成して再生する
    if ( mPool.empty() )
	{
		newParticle();
    }
    //プールの中身があった場合プールから借りてパーティクルを再生する
    auto particle = mPool.back();
    mPool.pop_back();
    particle->resetSystem();
    particle->setPosition( pos );
    node->addChild( particle );
}
