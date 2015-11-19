//
//  SimpleParticle.h
//  TeamProject
//
//  Created by Satou yuta on 2015/11/09.
//
//

#ifndef _SIMPLEPARTICLE_H_
#define _SIMPLEPARTICLE_H_

class SimpleParticle : public cocos2d::ParticleSystemQuad{

protected:
    
    SimpleParticle();
    
    ~SimpleParticle();
    
public:
    
    static SimpleParticle* create( const std::string& fileName );
    
    virtual void update( float deltaTitme ) override;
    
    std::function<void(SimpleParticle*)> onFinishListener;
    
};

#endif
