//
//  StageSelectScrollView.cpp
//  TeamProject
//
//  Created by Satou yuta on 2015/12/09.
//
//

#include "StageSelectScrollView.h"
//#include "cocos2d.h"

using namespace cocos2d;
using namespace ui;

bool StageSelectScrollView::init( const std::string& backTexture, const std::string& barTexture, const Vec2& pos )
{
    
    if ( !Node::init() )
    {
        return false;
    }
    
    scrollBackGraund( backTexture );
    scrollbar( barTexture );
    
    addChild( button );
    
    //座標
    setPosition( pos );
    
    return true;
}

StageSelectScrollView* StageSelectScrollView::create( const std::string& backTexture, const std::string& barTexture, const Vec2& pos )
{
    StageSelectScrollView* inst = new StageSelectScrollView();
    
    if ( inst && inst->init( backTexture, barTexture, pos ) )
    {
        inst->autorelease();
        return inst;
    }
    
    CC_SAFE_DELETE( inst );
    return nullptr;
}

void StageSelectScrollView::scrollBackGraund( const std::string& backTexture ){

    ImageView* backTex = ImageView::create( backTexture );
    addChild( backTex );
}

void StageSelectScrollView::scrollbar( const std::string& barTexture ){

    button = MenuItemImage::create( barTexture, barTexture, [](Ref* ref){} );
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches( true );
    // ラムダを使用して関数内にonTouchBeganとonTouchEndedを実装する。
    listener->onTouchBegan = [ this ]( Touch* touch, Event* event )
    {
        // タッチされたボタンが左かどうか判別している。これがないと複数のイベントリスナーが実行されてしまう。
        Vec2 point = touch->getLocation();                 // タッチしたポイント。
        Rect rectButton1 = button->getBoundingBox();   // ボタン画像の範囲。
        CCLOG( "%f", rectButton1.getMaxX() );
        if ( rectButton1.containsPoint( point ) )
        {
            CCLOG( "aaaaaa" );
            return true;
        }else{
            return false;
        }
    };
    listener->onTouchMoved = [ this ](Touch* touch, Event* event){
        auto location = touch->getLocation();
    };
    
    listener->onTouchEnded = [ this ](Touch* touch, Event* event){
    };
    // listener1, PlayButton1をイベント登録する。
    auto director = Director::getInstance();
    director->getEventDispatcher()->addEventListenerWithSceneGraphPriority( listener, button );

    addChild( button );
}