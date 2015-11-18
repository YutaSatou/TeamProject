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

namespace cocos2d {
 
    class Node;
    class Vec2;
}

class SimpleParticle;

class ParticleManager{

protected:
    
    ParticleManager() = default;
    
    ~ParticleManager() = default;
    
    bool init( const std::string& fileName, const size_t& instanceNum  );
    
public:
    
    /**
     *	@brief	パーティクルプール作成
     *	@param	fileName    生成するパーティクル名
     *	@return	instanceNum 生成するパーティクルの数
     *  @MEMO   FileNameはフォルダー＆拡張子なしで大丈夫です
     */
    static ParticleManager* createPool( const std::string& fileName, const size_t& instanceNum );
    
    /**
     *	@brief	パーティクル再生
     *	@param	node    親にするノード
     *	@return	pos     パーティクルの座標
     *  @MEMO   パーティクルプール
     */
    SimpleParticle* playParicle( cocos2d::Node* node, const cocos2d::Vec2& pos );
    
private:
    
    void push( SimpleParticle* particle );
    
    void newCreateParticle();
    
    using ParticlePool = std::vector< SimpleParticle* >;
    ParticlePool pool;
    
    std::string mFileName;
    
    SimpleParticle* mParticle;
};

#endif