//
//  StageSelectLayOut.cpp
//  TeamProject
//
//  Created by Satou yuta on 2015/09/14.
//
//

#include "StageSelectLayOut.h"
#include "../GamePlay/DebugLayer.h"
#include "../../Utility/Assistant/SceneSwitcher.h"

using namespace cocos2d;
using namespace ui;

namespace  {
    
    Size SCREEN_SIZE;
    Vec2 ORIGIN_SIZE;
    
    //ADX2Player* mPlayer;
}

StageSelectLayOut::StageSelectLayOut(){
    
}

StageSelectLayOut::~StageSelectLayOut(){
    
    //mPlayer->release();
}

bool StageSelectLayOut::init(){
    return true;
}

StageSelectLayOut* StageSelectLayOut::create(){
    
    StageSelectLayOut* inst = new StageSelectLayOut();
    
    if ( inst && inst->init() ){
        
        inst->autorelease();
        return inst;
    }
    
    CC_SAFE_DELETE( inst );
    return nullptr;

}

void StageSelectLayOut::update(float deltaTime){
    
}

//スイッチ作成用の関数//
Button* StageSelectLayOut::createButton( const std::string& offButton, const std::string& onButton, int stageTag  ){
    
    Button* button = nullptr;
    
    button = Button::create();
    button->loadTextureNormal( offButton );
    button->loadTexturePressed( onButton );
    button->loadTextureDisabled( onButton );
    
    button->setPosition( Vec2::ZERO );
    
    button->addTouchEventListener( [ & ]( Ref* sender, Widget::TouchEventType type ){
        if ( type == Widget::TouchEventType::ENDED ){
            //CCLOG( "%i", stageTag );
            //button->setEnabled( true );
            /*mPlayer = ADX2Player::create( "Basic.acb", "Basic.awb" );
            mPlayer->play( 4, SoundType::BGM);
            mPlayer->retain();*/
            SceneSwitcher::change( SceneType::PLAY );
        }
    });
    
    button->setPressedActionEnabled( true );
    
    return button;
}

PageView* StageSelectLayOut::createPage( int pageNum ){
    
    SCREEN_SIZE = Director::getInstance()->getVisibleSize();
    ORIGIN_SIZE = Director::getInstance()->getVisibleOrigin();
    
    PageView* page = PageView::create();
    page->setContentSize( Size( SCREEN_SIZE.width / 1.5f , SCREEN_SIZE.height ) );
    page->setPosition( ( SCREEN_SIZE - page->getContentSize() ) / 2.0f );
    
    Layout* layout = nullptr;
    
    for ( int i = 0; i < pageNum; ++i ){
        
        //レイアウト作成
        layout = Layout::create();
        layout->setContentSize( page->getContentSize() );
        
        //レイアウトに表示するコンテンツを作成
        ImageView* image = ImageView::create();
        image->setPosition( layout->getContentSize() / 2 );
        layout->addChild( image );
        page->insertPage( layout, i );
        
        std::string nomalFilePath[] = {
            
            "Texture/Debug/button.png", "Texture/Debug/button.png", "Texture/Debug/button.png",
            "Texture/Debug/button.png", "Texture/Debug/button.png", "Texture/Debug/button.png",
            "Texture/Debug/button.png", "Texture/Debug/button.png", "Texture/Debug/button.png",
        };
        
        std::string pressedFilePath [] = {
            
            "Texture/Debug/button.png", "Texture/Debug/button.png", "Texture/Debug/button.png",
            "Texture/Debug/button.png", "Texture/Debug/button.png", "Texture/Debug/button.png",
            "Texture/Debug/button.png", "Texture/Debug/button.png", "Texture/Debug/button.png",
        };
        
        Vec2 poses[] = {
            Vec2( 100, 950 ), Vec2( 250, 950 ), Vec2( 400, 950 ),
            Vec2( 100, 800 ), Vec2( 250, 800 ), Vec2( 400, 800 ),
            Vec2( 100, 650 ), Vec2( 250, 650 ), Vec2( 400, 650 ),
            
        };
        
        for (int i = 0; i < 9; ++i){
            
            Button* button = createButton( nomalFilePath[i] , pressedFilePath[i], i);
            button->setPosition( poses[i] );
            //button->setEnabled( false );
            layout->addChild( button );
        }

    }
    
    
    
    return page;
}