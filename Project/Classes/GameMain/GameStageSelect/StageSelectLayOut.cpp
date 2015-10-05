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
Button* StageSelectLayOut::createButton( const std::string& offButton, const std::string& onButton, const std::string& disButton, int stageTag  ){
    
    Button* button = nullptr;
    
    button = Button::create();
    button->loadTextureNormal( offButton );
    button->loadTexturePressed( onButton );
    button->loadTextureDisabled( disButton );
    
    button->setPosition( Vec2::ZERO );
    
    button->addTouchEventListener( [ = ]( Ref* sender, Widget::TouchEventType type ){
        if ( type == Widget::TouchEventType::ENDED ){
            CCLOG( "%i", stageTag );
            //button->setEnabled( false );
            button->setTouchEnabled( false );
            button->setBright( false );
            /*mPlayer = ADX2Player::create( "Basic.acb", "Basic.awb" );
            mPlayer->play( 4, SoundType::BGM);
            mPlayer->retain();*/
            //SceneSwitcher::change( SceneType::PLAY );
        }
    });
    
    button->setPressedActionEnabled( true );
    
    return button;
}

//ラベル
Label* StageSelectLayOut::createLabel( std::string number, const std::string& font, float fontSize, const Vec2& fontPos ){
    
    Label* numLabel = Label::createWithSystemFont( number, font, fontSize );
    numLabel->setPosition( fontPos );
    
    return numLabel;
}

PageView* StageSelectLayOut::createPage( int pageNum ){
    
    SCREEN_SIZE = Director::getInstance()->getVisibleSize();
    ORIGIN_SIZE = Director::getInstance()->getVisibleOrigin();
    
    PageView* page = PageView::create();
    page->setContentSize( Size( SCREEN_SIZE.width / 1.5f , SCREEN_SIZE.height ) );
    page->setPosition( ( SCREEN_SIZE - page->getContentSize() ) / 2.0f );
    //スクロールをできなくする
    //page->setEnabled( false );
    
    Layout* layout = nullptr;
    std::string nomalFilePath[] = {
        
        "Texture/Debug/button.png", "Texture/Debug/button.png", "Texture/Debug/button.png",
        "Texture/Debug/button.png", "Texture/Debug/button.png", "Texture/Debug/button.png",
        "Texture/Debug/button.png", "Texture/Debug/button.png", "Texture/Debug/button.png",
    };
    
    std::string pressedFilePath [] = {
        
        "Texture/Debug/Circle_Purple.png", "Texture/Debug/Circle_Purple.png", "Texture/Debug/Circle_Purple.png",
        "Texture/Debug/Circle_Purple.png", "Texture/Debug/Circle_Purple.png", "Texture/Debug/Circle_Purple.png",
        "Texture/Debug/Circle_Purple.png", "Texture/Debug/Circle_Purple.png", "Texture/Debug/Circle_Purple.png",
    };
    
    std::string disFilePath [] = {
        
        "Texture/Debug/Circle_Blue.png", "Texture/Debug/Circle_Blue.png", "Texture/Debug/Circle_Blue.png",
        "Texture/Debug/Circle_Blue.png", "Texture/Debug/Circle_Blue.png", "Texture/Debug/Circle_Blue.png",
        "Texture/Debug/Circle_Blue.png", "Texture/Debug/Circle_Blue.png", "Texture/Debug/Circle_Blue.png",
    };
    
    Vec2 poses[] = {
        Vec2( 100, 950 ), Vec2( 250, 950 ), Vec2( 400, 950 ),
        Vec2( 100, 800 ), Vec2( 250, 800 ), Vec2( 400, 800 ),
        Vec2( 100, 650 ), Vec2( 250, 650 ), Vec2( 400, 650 ),
        
    };
    
    int stageNum = 1;
    
    for ( int i = 0; i < pageNum; ++i ){
        //レイアウト作成
        layout = Layout::create();
        layout->setContentSize( page->getContentSize() );
        
        //レイアウトに表示するコンテンツを作成
        ImageView* image = ImageView::create();
        image->setPosition( layout->getContentSize() / 2 );
        layout->addChild( image );
        page->insertPage( layout, i );
        
        for ( int j = 0; j < 9; ++j ){
            
            Button* button = createButton( nomalFilePath[j] , pressedFilePath[j], disFilePath[j],stageNum );
            Label* label = createLabel( StringUtils::toString( stageNum ), "Font/arial.ttf", 32, button->getPosition() + ( button->getContentSize() / 2 ) );
            stageNum++;
            button->setPosition( poses[j] );
            button->addChild( label );
            layout->addChild( button );
            
        }
    }
    
    return page;
}