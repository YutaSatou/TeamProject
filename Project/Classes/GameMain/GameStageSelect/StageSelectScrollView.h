//
//  StageSelectScrollView.hpp
//  TeamProject
//
//  Created by Satou yuta on 2015/12/09.
//
//

#ifndef _STAGESELECTSCROLLVIEW_H_
#define _STAGESELECTSCROLLVIEW_H_

#include "ui/CocosGUI.h"
#include "cocos2d.h"

class StageSelectScrollView : public cocos2d::Node{

protected:
    
    StageSelectScrollView() = default;
    
    ~StageSelectScrollView() = default;
    
    bool init( const std::string& backTexture, const std::string& barTexture, const cocos2d::Vec2& pos );
    
public:
    
    static StageSelectScrollView* create( const std::string& backTexture, const std::string& barTexture, const cocos2d::Vec2& pos );
    
private:
    
    void scrollBackGraund( const std::string& backTexture );
    
    void scrollbar( const std::string& barTexture );
    
    cocos2d::MenuItemImage* button;
};

#endif
