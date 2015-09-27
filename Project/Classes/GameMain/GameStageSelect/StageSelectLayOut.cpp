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

#define VISIBLESIZE Director::getInstance()->getVisibleSize()
#define ORIGINSIZE Director::getInstance()->getVisibleOrigin()

StageSelectLayOut::StageSelectLayOut(){
    
}

StageSelectLayOut::~StageSelectLayOut(){
    
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
    
    button->addTouchEventListener( [=]( Ref* sender, Widget::TouchEventType type ){
        if ( type == Widget::TouchEventType::ENDED ){
            
            CCLOG( "%i", stageTag );
            button->setEnabled( true );
            SceneSwitcher::change( SceneType::PLAY );
        }
    });
    
    button->setPressedActionEnabled( true );
    
    return button;
}

PageView* StageSelectLayOut::createPage( int pageNum ){
    
    PageView* page = PageView::create();
    page->setContentSize( Size( VISIBLESIZE.width / 1.5f , VISIBLESIZE.height ) );
    page->setPosition( ( VISIBLESIZE - page->getContentSize() ) / 2.0f );
    
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
            
            "Texture/Debug/image_menu_normal.png", "Texture/Debug/image_menu_normal.png", "Texture/Debug/image_menu_normal.png",
            "Texture/Debug/image_menu_normal.png", "Texture/Debug/image_menu_normal.png", "Texture/Debug/image_menu_normal.png",
            "Texture/Debug/image_menu_normal.png", "Texture/Debug/image_menu_normal.png", "Texture/Debug/image_menu_normal.png",
        };
        
        std::string pressedFilePath [] = {
            
            "Texture/Debug/image_menu_select.png", "Texture/Debug/image_menu_select.png", "Texture/Debug/image_menu_select.png",
            "Texture/Debug/image_menu_select.png", "Texture/Debug/image_menu_select.png", "Texture/Debug/image_menu_select.png",
            "Texture/Debug/image_menu_select.png", "Texture/Debug/image_menu_select.png", "Texture/Debug/image_menu_select.png",
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