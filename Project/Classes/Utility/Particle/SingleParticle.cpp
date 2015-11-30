//
//  SimpleParticle.cpp
//  TeamProject
//
//  Created by Satou yuta on 2015/11/09.
//
//

#include "SingleParticle.h"

using namespace cocos2d;

SingleParticle* SingleParticle::create( const std::string& fileName ){

    SingleParticle* inst = new SingleParticle();
    
    if ( inst && inst->initWithFile( fileName ) )
    {
        inst->autorelease();
        return inst;
    }
    
    CC_SAFE_DELETE( inst );
    return nullptr;
}

void SingleParticle::update( float deltaTitme ){
    
    CC_PROFILER_START_CATEGORY(kProfilerCategoryParticles , "ParticleSystem - update");
    
    if (_isActive && _emissionRate)
    {
        float rate = 1.0f / _emissionRate;
        //issue #1201, prevent bursts of particles, due to too high emitCounter
        if (_particleCount < _totalParticles)
        {
            _emitCounter += deltaTitme;
        }
        
        while (_particleCount < _totalParticles && _emitCounter > rate)
        {
            this->addParticle();
            _emitCounter -= rate;
        }
        
        _elapsed += deltaTitme;
        if (_duration != -1 && _duration < _elapsed)
        {
            this->stopSystem();
        }
    }
    
    _particleIdx = 0;
    
    Vec2 currentPosition = Vec2::ZERO;
    if (_positionType == PositionType::FREE)
    {
        currentPosition = this->convertToWorldSpace(Vec2::ZERO);
    }
    else if (_positionType == PositionType::RELATIVE)
    {
        currentPosition = _position;
    }
    
    {
        while (_particleIdx < _particleCount)
        {
            tParticle *p = &_particles[_particleIdx];
            
            // life
            p->timeToLive -= deltaTitme;
            
            if (p->timeToLive > 0)
            {
                // Mode A: gravity, direction, tangential accel & radial accel
                if (_emitterMode == Mode::GRAVITY)
                {
                    Vec2 tmp, radial, tangential;
                    
                    radial = Vec2::ZERO;
                    // radial acceleration
                    if (p->pos.x || p->pos.y)
                    {
                        radial = p->pos.getNormalized();
                    }
                    tangential = radial;
                    radial = radial * p->modeA.radialAccel;
                    
                    // tangential acceleration
                    float newy = tangential.x;
                    tangential.x = -tangential.y;
                    tangential.y = newy;
                    tangential = tangential * p->modeA.tangentialAccel;
                    
                    // (gravity + radial + tangential) * dt
                    tmp = radial + tangential + modeA.gravity;
                    tmp = tmp * deltaTitme;
                    p->modeA.dir = p->modeA.dir + tmp;
                    
                    // this is cocos2d-x v3.0
                    //                    if (_configName.length()>0 && _yCoordFlipped != -1)
                    
                    // this is cocos2d-x v3.0
                    tmp = p->modeA.dir * deltaTitme * _yCoordFlipped;
                    p->pos = p->pos + tmp;
                }
                
                // Mode B: radius movement
                else
                {
                    // Update the angle and radius of the particle.
                    p->modeB.angle += p->modeB.degreesPerSecond * deltaTitme;
                    p->modeB.radius += p->modeB.deltaRadius * deltaTitme;
                    
                    p->pos.x = - cosf(p->modeB.angle) * p->modeB.radius;
                    p->pos.y = - sinf(p->modeB.angle) * p->modeB.radius;
                    p->pos.y *= _yCoordFlipped;
                }
                
                // color
                p->color.r += (p->deltaColor.r * deltaTitme);
                p->color.g += (p->deltaColor.g * deltaTitme);
                p->color.b += (p->deltaColor.b * deltaTitme);
                p->color.a += (p->deltaColor.a * deltaTitme);
                
                // size
                p->size += (p->deltaSize * deltaTitme);
                p->size = MAX( 0, p->size );
                
                // angle
                p->rotation += (p->deltaRotation * deltaTitme);
                
                //
                // update values in quad
                //
                
                Vec2    newPos;
                
                if (_positionType == PositionType::FREE || _positionType == PositionType::RELATIVE)
                {
                    Vec2 diff = currentPosition - p->startPos;
                    newPos = p->pos - diff;
                }
                else
                {
                    newPos = p->pos;
                }
                
                // translate newPos to correct position, since matrix transform isn't performed in batchnode
                // don't update the particle with the new position information, it will interfere with the radius and tangential calculations
                if (_batchNode)
                {
                    newPos.x+=_position.x;
                    newPos.y+=_position.y;
                }
                
                updateQuadWithParticle(p, newPos);
                //updateParticleImp(self, updateParticleSel, p, newPos);
                
                // update particle counter
                ++_particleIdx;
            }
            else
            {
                // life < 0
                int currentIndex = p->atlasIndex;
                if( _particleIdx != _particleCount-1 )
                {
                    _particles[_particleIdx] = _particles[_particleCount-1];
                }
                if (_batchNode)
                {
                    //disable the switched particle
                    _batchNode->disableParticle(_atlasIndex+currentIndex);
                    
                    //switch indexes
                    _particles[_particleCount-1].atlasIndex = currentIndex;
                }
                
                
                --_particleCount;
                
                if( _particleCount == 0 && _isAutoRemoveOnFinish )
                {
                    
                    this->unscheduleUpdate();
                    _parent->removeChild(this, true);
                    // 親から remove されるときにコールバック関数を呼ぶ
                    if (onFinishListener) {
                        onFinishListener(this);
                    }
                    return;
                }
            }
        } //while
        _transformSystemDirty = false;
    }
    
    // only update gl buffer when visible
    if (_visible && ! _batchNode)
    {
        postStep();
    }
    
    CC_PROFILER_STOP_CATEGORY(kProfilerCategoryParticles , "ParticleSystem - update");
}