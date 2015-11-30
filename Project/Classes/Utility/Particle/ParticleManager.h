//
//  ParticlePool.h
//  TeamProject
//
//  Created by Satou yuta on 2015/11/09.
//
//

#ifndef _PARTICLEMANAGER_H_
#define _PARTICLEMANAGER_H_

#include <vector>
//#include <string.h>
//#include <cstddef>
#include "ParticleType.h"

namespace cocos2d {
 
    class Node;
    class Vec2;
}

class SingleParticle;

class ParticleManager : public cocos2d::Node{

protected:
    
    ParticleManager();
    
    ~ParticleManager();
    
    bool init( const ParticleType type, const size_t& instanceNum  );
    
public:
    
    /**
     *	@brief	パーティクルプール作成
     *	@param	fileName    生成するパーティクル名
     *	@return	instanceNum 生成するパーティクルの数
     *  @MEMO   FileNameはフォルダー＆拡張子なしで大丈夫です
     */
    static ParticleManager* createPool( const ParticleType type, const size_t& instanceNum );
    
    /**
     *	@brief	パーティクル再生
     *	@param	node    親にするノード
     *	@return	pos     パーティクルの座標
     *  @MEMO   パーティクルプール
     */
    void playParicle( cocos2d::Node* node, const cocos2d::Vec2& pos );
    
private:
    
    void newParticle();
    
    void push( SingleParticle* particle );

    using mParticlePool = std::vector< SingleParticle* >;
    mParticlePool mPool;
    
    ParticleType mFileName;
};

#endif
