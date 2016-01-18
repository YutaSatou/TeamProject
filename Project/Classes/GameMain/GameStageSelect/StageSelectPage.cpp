//
//  StageSelectPage.cpp
//  TeamProject
//
//  Created by Satou yuta on 2015/11/12.
//
//

#include "StageSelectPage.h"
#include "PageCursor.h"
#include "Utility/Assistant/Scene/SceneChanger.h"
#include "../../Utility/Assistant/Scene/SceneCreator.h"
#include "../GamePlay/GamePlayLayer.h"
#include "ui/CocosGUI.h"
#include "../../Utility/Audio/ADX2Player.h"
#include "../../Utility/DataIO/DataIO.h"
#include "../../Utility/DataIO/StageNumber.h"

#include "../GameResult/GameResultLayer.h"
#include "../../Utility/DataIO/StageColors.h"

using namespace cocos2d;
using namespace ui;

bool StageSelectPage::init( const int pageNum ){
    
    if ( !Layer::init() ){
        return false;
    }
    
    Size screen_size = Director::getInstance()->getWinSize();
    mPage = UIPageView::creae( screen_size );
    mPage->setContentSize( screen_size );
    
    for (int i=0; i < pageNum; ++i){
        auto pageLayer = Layer::create();
        mPage->insertPage( pageLayer );
    }
    
    /*StageNumber* stage = StageNumber::create();
    addChild( stage );*/
	StageNumber stage;
	StageColors stageColor;
    
    Vec2 poses[] = {
        
        Vec2( 168, 1062 ), Vec2( 358, 1062 ), Vec2( 548, 1062 ),
        Vec2( 168, 832 ), Vec2( 358, 832 ), Vec2( 548, 832 ),
        Vec2( 168, 602 ), Vec2( 358, 602 ), Vec2( 548, 602 ),
        
        Vec2( 870, 1062 ), Vec2( 1070, 1062 ), Vec2( 1270, 1062 ),
        Vec2( 870, 832 ), Vec2( 1070, 832 ), Vec2( 1270, 832 ),
        Vec2( 870, 602 ), Vec2( 1070, 602 ), Vec2( 1270, 602 ),
        
        Vec2( 1590, 1062 ), Vec2( 1790, 1062 ), Vec2( 1990, 1062 ),
        Vec2( 1590, 832 ), Vec2( 1790, 832 ), Vec2( 1990, 832 ),
        Vec2( 1590, 602 ), Vec2( 1790, 602 ), Vec2( 1990, 602 ),
    };
	
    for (int j = 0; j < 27; ++j){
        Button* image = Button::create( "Texture/GameStageSelect/Stage_Numberbox_Notclear.png" );
        image->setTitleText( StringUtils::toString( j + 1 ) );
        image->setTitleFontName( "Font/RiiPopkkR.otf" );
        image->setTitleFontSize( 68 );
		image->setTitleColor( Color3B::BLACK );
        image->setZoomScale( 0.1f );
        image->setPosition( poses[j] );
        
        image->addTouchEventListener( [ = ]( Ref* sender, Widget::TouchEventType type ){
            
            if ( type == Widget::TouchEventType::BEGAN ){
            }
            if ( type == Widget::TouchEventType::ENDED ){
                ADX2Player::getInstance().play( 6 );
                stage.saveStageNumber( j + 1 );
				stageColor.saveColor( 0, 0, 0 );
                Scene* scene		{ SceneCreator::createScene( GamePlayLayer::create() ) };
                Scene* nextScene	{ TransitionRotoZoom::create( 0.8f, scene ) };
                SceneChanger::switchScene( nextScene );
            }
        });
        mPage->addChild( image );
    }
    
    ImageView* sliderBack = PageCursor::baseTex( "Texture/GameStageSelect/Select_Box_Stageline.png", Vec2( 358, 163 ) );
    slider = PageCursor::sliderTex( "Texture/GameStageSelect/Select_Box.png", Vec2( 161, 163 ) );
    slider->setTag( 1 );
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches( true );
    // ラムダを使用して関数内にonTouchBeganとonTouchEndedを実装する。
    listener->onTouchBegan = [ this ](Touch* touch, Event* event){
        // タッチされたボタンが左かどうか判別している。これがないと複数のイベントリスナーが実行されてしまう。
        Vec2 point1 = touch->getLocation();                 // タッチしたポイント。
        mlocal = slider->getPosition();
        mScreenPos = mPage->getPosition();
        
        Rect rectButton1 = slider->getBoundingBox();   // ボタン画像の範囲。
        if (rectButton1.containsPoint(point1)) {            // ボタン画像の範囲内をタッチした場合。
            // タッチされた時の処理
            auto location = touch->getLocation();
            auto sprite = this->getChildByTag(1);
            mPos = getPosition();
            if ( sprite->getPositionX() >= 161 && sprite->getPositionX() <= 556 ){
                //sprite->setPosition( Vec2( location.x, 163 ) );
            }
            if ( sprite->getPositionX() <= 161 ){
                sprite->setPosition( Vec2( 161, 163 ) );
            }
            if ( sprite->getPositionX() >= 556 ){
                sprite->setPosition( Vec2( 556, 163 ) );
            }
            return true;
        }else{
            return false;
        }
    };
    listener->onTouchMoved = [ this ](Touch* touch, Event* event){
        auto location = touch->getLocation();
        auto sprite = this->getChildByTag(1);
        if ( sprite->getPositionX() >= 161 ){
            sprite->setPosition( Vec2( location.x, 163 ) );
        }
        if ( sprite->getPositionX() <= 161 ){
            sprite->setPosition( Vec2( 161, 163 ) );
        }
        if ( sprite->getPositionX() >= 556 ){
            sprite->setPosition( Vec2( 556, 163 ) );
        }
        if ( mlocal.x <= sprite->getPositionX() ){
     
            float x = ( mlocal.x - sprite->getPositionX() ) * 3.65f;
            mPage->move( Vec2( x, 0 ) );
            mlocal.x = sprite->getPositionX();
        }
        if ( mlocal.x >= sprite->getPositionX() ){
            float x = ( sprite->getPositionX() - mlocal.x ) * 3.65f;
            mPage->move( Vec2( -x, 0 ) );
            mlocal.x = sprite->getPositionX();
        }
        
    };
     
    listener->onTouchEnded = [ this ](Touch* touch, Event* event){
    };
    // listener1, PlayButton1をイベント登録する。
    auto director = Director::getInstance();
    director->getEventDispatcher()->addEventListenerWithSceneGraphPriority( listener, slider );
    
    addChild( mPage );
    
    mPage->addTurnedEventListner( CC_CALLBACK_3( StageSelectPage::pageTurnedEvent, this  ));
    addChild( sliderBack );
    addChild( slider );
    
    scheduleUpdate();
    
    return true;
}

StageSelectPage* StageSelectPage::create( const int pageNum ){
    
    StageSelectPage* inst = new StageSelectPage();
    
    if ( inst && inst->init( pageNum ) ){
        inst->autorelease();
        return inst;
    }
    
    CC_SAFE_DELETE( inst );
    return nullptr;
}

void StageSelectPage::pageTurnedEvent( UIPageView* pageview, bool isTurned, int turnnedPageNumber ){
    
    switch ( turnnedPageNumber ) {
        case 0:{
            MoveTo* move1 = MoveTo::create( 0.1f, Vec2( 161, slider->getPositionY() ) );
            slider->runAction( move1 );
            break;
        }
        case 1:{
            MoveTo* move2 = MoveTo::create( 0.1f, Vec2( 358, slider->getPositionY() ) );
            slider->runAction( move2 );
            break;
        }
        case 2:{
            MoveTo* move3 = MoveTo::create( 0.1f, Vec2( 556, slider->getPositionY() ) );
            slider->runAction( move3 );
            break;
        }
    }
}