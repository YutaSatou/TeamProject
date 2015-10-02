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

class EffectManagaer {
    
protected:
    
    EffectManagaer() = default;
    
    ~EffectManagaer() = default;
    
public:
    
    /**
     *	@brief	インスタンス作成
     *	@param	particleNode ノード
     *	@param	effectTex	 パーティクルのテクスチャの名前
     *	@param	plist        パーティクルのプロパティーリストの名前
     *	@param	effectPos    パーティクルを生成する座標
     *  @memo フォルダー参照、.plist無しで再生できます。
     */
    static void createParticle( cocos2d::Node* particleNode, const std::string& plist, const cocos2d::Vec2& effectPos );

};

#endif
