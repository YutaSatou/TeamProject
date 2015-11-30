//
//  UIPageView.cpp
//  TeamProject
//
//  Created by Satou yuta on 2015/11/04.
//
//

#include "UIPageView.h"

using namespace cocos2d;

#define CALL_FUNC_N_START CallFuncN::create([this](Node *p)\
{
#define CALL_FUNC_N_END })

UIPageView* UIPageView::creae( Size pageSize )
{
    auto ref = new( std::nothrow )UIPageView();
    
    if ( ref && ref->init( pageSize ) )
    {
        ref->autorelease();
        return ref;
    }
    
    CC_SAFE_DELETE( ref );
    return nullptr;
}

UIPageView::UIPageView()
:pageCount( 0 )
,totalLength( 0, 0 )
,currentPageNumber( 0 )
,_tef( nullptr )
{}

UIPageView::~UIPageView(){
}

bool UIPageView::init( Size pageSize ){
    
    if ( !Layer::init() ){
        return false;
    }
    
    width = pageSize.width;
    hight = pageSize.height;
    
    mAutoMove = false;
    
    add();
    
    return true;
}

void UIPageView::add(){
    
    auto l = EventListenerTouchOneByOne::create();
    l->onTouchBegan = CC_CALLBACK_2(UIPageView::onTouchBegan, this);
    l->onTouchMoved = CC_CALLBACK_2(UIPageView::onTouchMoved, this);
    l->onTouchEnded = CC_CALLBACK_2(UIPageView::onTouchEnded, this);
    l->onTouchCancelled = CC_CALLBACK_2(UIPageView::onTouchCancelled, this);
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(l, this);
}

void UIPageView::insertPage( cocos2d::Layer* page ){
    
    page->setPosition(Vec2(pageCount*width, hight));
    addChild(page,1,pageCount);
    
    pages.push_back(page);
    
    pageCount++;
    totalLength = Vec2( pageCount * width, hight );
}

Layer* UIPageView::getPageAt( int pageNumber ){
    return pages.at( pageNumber );
}

void UIPageView::update( float deltaTime ){
}

void UIPageView::move( Vec2 offset ){
    Vec2 pos = this->getPosition();
    setPosition( Vec2(  ( pos + offset ).x , getPositionY() ) );
}

void UIPageView::automovelef(){
    float screenWidth = width;
    runAction(Sequence::create(
                               MoveTo::create( 0.2, Vec2( -( screenWidth ), getPositionY() ) ),
                               CALL_FUNC_N_START
                               if( _tef ) _tef ( this, currentScrollDirection == ScrollDirection::LEFT, currentPageNumber );
                               CALL_FUNC_N_END,
                               nullptr ) );
    currentPageNumber += 1;

}
void UIPageView::automoverig(){
    float screenWidth = width;
    runAction(Sequence::create(
                               MoveTo::create( 0.2, Vec2( screenWidth , getPositionY() ) ),
                               CALL_FUNC_N_START
                               if( _tef ) _tef ( this, currentScrollDirection == ScrollDirection::RIGHT, currentPageNumber );
                               CALL_FUNC_N_END,
                               nullptr ) );
    currentPageNumber -= 1;
    
}

bool UIPageView::onTouchBegan( Touch* touch, Event* event ){
    
    currentPosition = getPosition();
    mPosition = getPosition();
    return true;
}

void UIPageView::onTouchMoved( Touch* touch, Event* event ){
    if (onTouchListener){
        onTouchListener(this);
    }
    auto t = touch->getLocation();
    
    Vec2 offset = t - touch->getStartLocation();
    Vec2 pos = getPosition();
    
    if ( currentPageNumber == 0 && offset.x >= 0 ){
        return;
    }
    
    if ( currentPageNumber == pageCount-1 && offset.x <= 0 ){
        return;
    }
    
    setPosition( Vec2( ( currentPosition + offset ).x, getPositionY() ) );
    
    //CCLOG( "動き : %f", offset.x );
    if ( offset.x >= 0 ){
        currentScrollDirection = ScrollDirection::LEFT;
    }
    /*if( offset.x <= 0 ){
        currentScrollDirection = ScrollDirection::RIGHT;
    }*/
}

void UIPageView::onTouchEnded( Touch* touch, Event* event ){
    if (onTouchListener){
        onTouchListener(this);
    }
    for ( int i = 0; i < pageCount; i++ ){
        float endPoint = width *( i + 1 );
        float absPosition = fabs( getPositionX() );
        float screenWidth = width;
        
        if ( endPoint - screenWidth < absPosition && absPosition <= endPoint ){
            
            if ( (endPoint - screenWidth < absPosition && absPosition <= endPoint - ( screenWidth / 2 )) ){
                currentPageNumber = i;
                runAction(Sequence::create(
                                           MoveTo::create( 0.2, Vec2( -( endPoint - screenWidth ), getPositionY() ) ),
                                           CALL_FUNC_N_START
                                           if( _tef ) _tef ( this, currentScrollDirection == ScrollDirection::LEFT, currentPageNumber );
                                           CALL_FUNC_N_END,
                                           nullptr ) );
            }
            else if ( (endPoint - ( screenWidth / 2 ) < absPosition && absPosition <= endPoint) ){
                currentPageNumber = i+1;
                runAction( Sequence::create(
                                           MoveTo::create( 0.2, Vec2( -endPoint, getPositionY() ) ),
                                           CALL_FUNC_N_START
                                           if( _tef ) _tef ( this, currentScrollDirection == ScrollDirection::RIGHT, currentPageNumber );
                                           CALL_FUNC_N_END,
                                           nullptr ) );
            }
            
            return;
        }
    }
}

void UIPageView::onTouchCancelled( Touch* touch, Event* event ){
    onTouchEnded(touch, event);
}