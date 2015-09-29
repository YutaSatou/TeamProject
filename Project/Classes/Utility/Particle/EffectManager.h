//
//  EffectManager.h
//  TeamProject
//
//  Created by Satou yuta on 2015/09/28.
//
//

#ifndef _EFFECTMANAGER_H_
#define _EFFECTMANAGER_H_

#include "cocos2d.h"

class EffectManagaer : public cocos2d::ParticleBatchNode{
    
protected:
    
    EffectManagaer() = default;
    
    ~EffectManagaer() = default;
    
public:
    
    /**
     *	@brief	インスタンス作成
     *	@param	effectTex	パーティクルのテクスチャの名前
     *	@param	plist       パーティクルのプロパティーリストの名前
     *	@param	direction   パーティクルの生存時間
     *	@param	effectPos   パーティクルを生成する座標
     */
    static cocos2d::ParticleBatchNode* createParticle( const std::string effectTex, const std::string plist, float direction, cocos2d::Vec2 effectPos );

};

#endif /* defined(__TeamProject__EffectManager__) */
