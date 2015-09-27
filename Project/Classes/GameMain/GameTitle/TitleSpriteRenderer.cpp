//
//  TitleSpriteRenderer.cpp
//  TeamProject
//
//  Created by Satou yuta on 2015/09/13.
//
//

#include "TitleSpriteRenderer.h"

using namespace cocos2d;

Sprite* TitleSpriteRenderer::createSprite(const std::string spriteName, const Vec2 spritePos ){
    
    Sprite* sprite = Sprite::create( spriteName );
    
    sprite->setPosition( spritePos );
    
    return sprite;
}