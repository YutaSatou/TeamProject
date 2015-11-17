//
//  StageSelectLayOut.cpp
//  TeamProject
//
//  Created by Satou yuta on 2015/09/14.
//
//

#include "StageSelectLayOut.h"
#include "../../Utility/Assistant/SceneSwitcher.h"

using namespace cocos2d;
using namespace ui;

namespace  {
    
    Size SCREEN_SIZE;
    Vec2 ORIGIN_SIZE;
}

StageSelectLayout::StageSelectLayout(){
}

StageSelectLayout::~StageSelectLayout(){
    
}

bool StageSelectLayout::init(){
    
    if ( !Layer::init() ){
        
        return false;
    }
    
    //画面サイズの定義
    SCREEN_SIZE = Director::getInstance()->getVisibleSize();
    ORIGIN_SIZE = Director::getInstance()->getVisibleOrigin();

    createPage( this, 3 );
    
    return true;
}

StageSelectLayout* StageSelectLayout::create(){
    
    StageSelectLayout* inst = new StageSelectLayout();
    
    if ( inst && inst->init() ){
        
        inst->autorelease();
        return inst;
    }
    
    CC_SAFE_DELETE( inst );
    return nullptr;
}

void StageSelectLayout::update( float deltaTime ){
    
}

//スイッチ作成用の関数//
Button* StageSelectLayout::createButton( const std::string& offButton, const std::string& onButton, const std::string& disButton, int stageTag  ){
    
    Button* button = Button::create();
    
    //通常時のボタンテクスチャ
    button->loadTextureNormal( offButton );
    //選択時のボタンテクスチャ
    button->loadTexturePressed( onButton );
    //選択不可の時のボタンテクスチャ
    button->loadTextureDisabled( disButton );
    
    button->setPosition( Vec2::ZERO );
    button->setSwallowTouches( false );
    
    return button;
}

//ラベル
Label* StageSelectLayout::createLabel( std::string number, const std::string& font, float fontSize, const Vec2& fontPos ){
    
    Label* numLabel = Label::createWithSystemFont( number, font, fontSize );
    numLabel->setPosition( fontPos );
    
    return numLabel;
}

//ページビュー作成
void StageSelectLayout::createPage( Node* node, int pageNum ){
    
    //ページビュー作成
    PageView* page = PageView::create();
    page->setContentSize( Size( SCREEN_SIZE.width , SCREEN_SIZE.height ) );
    page->setPosition( ( SCREEN_SIZE - page->getContentSize() ) / 2.0f );
    page->setCustomScrollThreshold( 0.5f );
    
    //通常時のボタンテクスチャのパス
    std::string nomalFilePath[] = {
        
        "Texture/Debug/Button.png", "Texture/Debug/Button.png", "Texture/Debug/Button.png",
        "Texture/Debug/Button.png", "Texture/Debug/Button.png", "Texture/Debug/Button.png",
        "Texture/Debug/Button.png", "Texture/Debug/Button.png", "Texture/Debug/Button.png",
    };
    //選択時のボタンテクスチャのパス
    std::string pressedFilePath [] = {
        
        "Texture/Debug/Button.png", "Texture/Debug/Button.png", "Texture/Debug/Button.png",
        "Texture/Debug/Button.png", "Texture/Debug/Button.png", "Texture/Debug/Button.png",
        "Texture/Debug/Button.png", "Texture/Debug/Button.png", "Texture/Debug/Button.png",
    };
    //選択不可時のボタンテクスチャのパス
    std::string disFilePath [] = {
        
        "Texture/Debug/Button.png", "Texture/Debug/Button.png", "Texture/Debug/Button.png",
        "Texture/Debug/Button.png", "Texture/Debug/Button.png", "Texture/Debug/Button.png",
        "Texture/Debug/Button.png", "Texture/Debug/Button.png", "Texture/Debug/Button.png",
    };
    //ボタンの座標
    Vec2 poses[] = {
        
        Vec2( 200, 950 ), Vec2( 350, 950 ), Vec2( 500, 950 ),
        Vec2( 200, 800 ), Vec2( 350, 800 ), Vec2( 500, 800 ),
        Vec2( 200, 650 ), Vec2( 350, 650 ), Vec2( 500, 650 ),
    };
    
    //ステージの番号
    int stageNum = 0;
    
    //ページ数作成
    for ( int i = 0; i < pageNum; ++i ){
        //レイアウト作成
        Layout* layout = Layout::create();
        layout->setContentSize( page->getContentSize() );
        
        page->insertPage( layout, i );
        
        //レイアウトに表示するコンテンツを作成
        for ( int j = 0; j < 9; ++j ){
            
            //ボタン作成
            Button* button = createButton( nomalFilePath[j] , pressedFilePath[j], disFilePath[j],stageNum );
            
            //ラベル作成
            Label* label = createLabel( StringUtils::toString( stageNum + 1 ), "Font/arial.ttf", 32, button->getPosition() + ( button->getContentSize() / 2 ) );
            
            //ステージの番号を足す
            stageNum++;
            
            //ボタンの座標を入れる
            button->setPosition( poses[j] );
            
            button->addChild( label );
            layout->addChild( button );
            
            //タッチ
            button->addTouchEventListener( [ = ]( Ref* sender, Widget::TouchEventType buttonType ){
                
                page->addTouchEventListener( [ = ]( Ref* sender, Widget::TouchEventType pageType ){
                    
                    //ページが動いているかの判定
                    bool isMoved = false;
                    
                    if ( buttonType == Widget::TouchEventType::BEGAN ){
                    }
                    
                    if ( pageType == Widget::TouchEventType::MOVED ){
                        isMoved = true;
                    }
                    
                    //ページが動いていなかったら処理する
                    if ( buttonType == Widget::TouchEventType::ENDED && !isMoved ){
                        //StageData sd;
                        //auto a = sd.read( "Stage" + StringUtils::toString( stageNum ) + ".plist" );
                        //CCLOG( "Stage : %i", stageNum );
                        SceneSwitcher::change( SceneType::PLAY );
                    }
                });
            });
        }
        page->addPage(layout);
    }
    node->addChild( page );
}