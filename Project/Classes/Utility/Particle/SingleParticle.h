//
//  SimpleParticle.h
//  TeamProject
//
//  Created by Satou yuta on 2015/11/09.
//
//

#ifndef _SINGLEPARTICLE_H_
#define _SINGLEPARTICLE_H_

#include "cocos2d.h"

class SingleParticle : public cocos2d::ParticleSystemQuad{

protected:
    
    SingleParticle() = default;
    
    ~SingleParticle() = default;
    
public:
    
    static SingleParticle* create( const std::string& fileName );
    
    virtual void update( float deltaTitme ) override;
    
    std::function<void(SingleParticle*)> onFinishListener;
    
};

#endif
