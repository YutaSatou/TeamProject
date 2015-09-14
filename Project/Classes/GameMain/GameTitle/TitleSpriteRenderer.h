//
//  TitleSpriteRenderer.h
//  TeamProject
//
//  Created by Satou yuta on 2015/09/13.
//
//

#ifndef __TeamProject__TitleSpriteRenderer__
#define __TeamProject__TitleSpriteRenderer__

#include <cocos2d.h>

class TitleSpriteRenderer{
    
public:
    
    /**
     *	@brief	スプライト作成
     *	@param	spriteName	画像の名前
     *	@param	spritePos   画像の座標
     */
    static cocos2d::Sprite* createSprite( std::string spriteName, const cocos2d::Vec2& spritePos );
};

#endif /* defined(__TeamProject__TitleSpriteRenderer__) */
