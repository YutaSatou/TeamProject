//
//  PageCurSor.h
//  TeamProject
//
//  Created by Satou yuta on 2015/10/23.
//
//

#ifndef _PAGECURSOR_H_
#define _PAGECURSOR_H_

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class PageCursor : public cocos2d::Layer{
    
    enum class Direction
    {
        LEFT,
        RIGHT
    };

protected:
    
    PageCursor() = default;
    
    ~PageCursor() = default;
    
    virtual bool init() override;
    
    virtual void update( float deltaTime ) override;
    
public:
    
    static PageCursor* create();
    
    static cocos2d::ui::ImageView* baseTex( const std::string& baseTex, const cocos2d::Vec2& pos );
    
    static cocos2d::MenuItemImage* sliderTex( const std::string& sliderTex, const cocos2d::Vec2& pos );
    
private:
    
private:
    
    Direction mDirection;
    cocos2d::Vec2 mlocal;
    cocos2d::Vec2 mPos;
};

#endif
