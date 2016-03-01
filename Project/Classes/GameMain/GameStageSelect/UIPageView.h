//
//  UIPageView.h
//  TeamProject
//
//  Created by Satou yuta on 2015/11/04.
//
//

#ifndef _UIPAGEVIEW_H_
#define _UIPAGEVIEW_H_

#include "cocos2d.h"

class UIPageView : public cocos2d::Layer{

public:
    enum ScrollDirection{
        BEGAN,
        MOMED,
        END,
        RIGHT,
        LEFT
    };
    
    typedef std::function<void(UIPageView*,bool,int)> turnedEventFunc;
    std::function<void(UIPageView*)> onTouchListener;
    
    static UIPageView* creae( cocos2d::Size pageSize );
    
    UIPageView();
    ~UIPageView();
    
    bool init(cocos2d::Size pageSize);
    
    void insertPage(cocos2d::Layer* page);
    
    virtual bool onTouchBegan( cocos2d::Touch *touch, cocos2d::Event *event ) override;
    virtual void onTouchMoved( cocos2d::Touch *touch, cocos2d::Event *event ) override;
    virtual void onTouchEnded( cocos2d::Touch *touch, cocos2d::Event *event ) override;
    virtual void onTouchCancelled( cocos2d::Touch *touch, cocos2d::Event *event ) override;
    virtual void update( float deltaTime ) override;
    
    CC_SYNTHESIZE_READONLY( int, pageCount, PageCount );
    
    inline void addTurnedEventListner( turnedEventFunc tef ){ _tef = tef; }
    
    cocos2d::Layer* getPageAt( int pageNumber );
	cocos2d::Vec2 setPage( int pageNumber );
	int getPageNumber() const;
    
    void move( cocos2d::Vec2 offset );
    
    void automoverig();
    void automovelef();
    
private:
    
    cocos2d::Size totalLength;
    float width;
    float hight;
    
	int currentPageNumber;
    
    cocos2d::Vec2 currentPosition;
    cocos2d::Vec2 mPosition;
    
    ScrollDirection currentScrollDirection;

    turnedEventFunc _tef;
    
    std::vector<cocos2d::Layer*> pages;
    
    void add();
    
public:
    
    bool mAutoMove;
};

#endif
