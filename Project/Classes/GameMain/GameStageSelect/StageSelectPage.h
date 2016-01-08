//
//  StageSelectPage.h
//  TeamProject
//
//  Created by Satou yuta on 2015/11/12.
//
//

#ifndef _STAGESELECTPAGE_H_
#define _STAGESELECTPAGE_H_

#include "cocos2d.h"
#include "UIPageView.h"

class StageSelectPage : public cocos2d::Layer{

protected:
    
    StageSelectPage() = default;
    
    ~StageSelectPage() = default;
    
    bool init( const int pageNum );

public:
    
    static StageSelectPage* create( const int pageNum );
    
private:
    
    void pageScrollingEvent( UIPageView* pageview );
    void pageTurnedEvent( UIPageView* pageview, bool isTurned, int turnnedPageNumber );
    
private:
    
    UIPageView* mPage;
    cocos2d::MenuItemImage* slider;
    cocos2d::Vec2 mlocal;
    cocos2d::Vec2 mScreenPos;
    cocos2d::Vec2 mPos;

};

#endif
