//
//  StageSelectLayOut.cpp
//  TeamProject
//
//  Created by Satou yuta on 2015/09/14.
//
//

#include "StageSelectLayOut.h"
#include "../../Utility/Assistant/SceneSwitcher.h"
#include "../../Utility/FileO/StageData.h"

using namespace cocos2d;
using namespace ui;

namespace  {
    
    Size SCREEN_SIZE;
    Vec2 ORIGIN_SIZE;
}

StageSelectLayOut::StageSelectLayOut(){
}

StageSelectLayOut::~StageSelectLayOut(){
    
    CC_SAFE_RELEASE( mPlayer );
}

bool StageSelectLayOut::init(){
    
    if ( !Layer::init() ){
        
        return false;
    }
    
    //画面サイズの定義
    SCREEN_SIZE = Director::getInstance()->getVisibleSize();
    ORIGIN_SIZE = Director::getInstance()->getVisibleOrigin();
    
    //ボタンをした時の音
    auto a  =CallFunc::create( [this](){
        
        mPlayer = ADX2Player::create("Audio/Title.acb");
        CC_SAFE_RETAIN( mPlayer );

    } );
    
    auto b = DelayTime::create( 1.0f );
    auto s = Sequence::create( b, a, nullptr );
    
    runAction( s );

    createPage( this, 3 );
    
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

void StageSelectLayOut::update( float deltaTime ){
    
}

//スイッチ作成用の関数//
Button* StageSelectLayOut::createButton( const std::string& offButton, const std::string& onButton, const std::string& disButton, int stageTag  ){
    
    Button* button = Button::create();
    
    //通常時のボタンテクスチャ
    button->loadTextureNormal( offButton );
    //選択時のボタンテクスチャ
    button->loadTexturePressed( onButton );
    //選択不可の時のボタンテクスチャ
    button->loadTextureDisabled( disButton );
    
    button->setPosition( Vec2::ZERO );
    button->setSwallowTouches( false );
    //button->setPressedActionEnabled( true );
    
    return button;
}

//ラベル
Label* StageSelectLayOut::createLabel( std::string number, const std::string& font, float fontSize, const Vec2& fontPos ){
    
    Label* numLabel = Label::createWithSystemFont( number, font, fontSize );
    numLabel->setPosition( fontPos );
    
    return numLabel;
}

//ページビュー作成
void StageSelectLayOut::createPage( Node* node, int pageNum ){
    
    //ページビュー作成
    PageView* page = PageView::create();
    page->setContentSize( Size( SCREEN_SIZE.width , SCREEN_SIZE.height ) );
    page->setPosition( ( SCREEN_SIZE - page->getContentSize() ) / 2.0f );
    
    //通常時のボタンテクスチャのパス
    std::string nomalFilePath[] = {
        
        "Texture/Debug/button.png", "Texture/Debug/button.png", "Texture/Debug/button.png",
        "Texture/Debug/button.png", "Texture/Debug/button.png", "Texture/Debug/button.png",
        "Texture/Debug/button.png", "Texture/Debug/button.png", "Texture/Debug/button.png",
    };
    //選択時のボタンテクスチャのパス
    std::string pressedFilePath [] = {
        
        "Texture/Debug/button.png", "Texture/Debug/button.png", "Texture/Debug/button.png",
        "Texture/Debug/button.png", "Texture/Debug/button.png", "Texture/Debug/button.png",
        "Texture/Debug/button.png", "Texture/Debug/button.png", "Texture/Debug/button.png",
    };
    //選択不可時のボタンテクスチャのパス
    std::string disFilePath [] = {
        
        "Texture/Debug/button.png", "Texture/Debug/button.png", "Texture/Debug/button.png",
        "Texture/Debug/button.png", "Texture/Debug/button.png", "Texture/Debug/button.png",
        "Texture/Debug/button.png", "Texture/Debug/button.png", "Texture/Debug/button.png",
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
                    
                    if ( pageType == Widget::TouchEventType::MOVED ){
                        
                        isMoved = true;
                        
                    }
                    
                    //ページが動いていなかったら処理する
                    if ( buttonType == Widget::TouchEventType::ENDED && !isMoved ){
                        StageData sd;
                        auto a = sd.read( "Stage" + StringUtils::toString( stageNum ) + ".plist" );
                        CCLOG( "Stage : %i", stageNum );
                        //button->setEnabled( false );
                        //button->setTouchEnabled( false );
                        //button->setBright( false );
                        mPlayer->play( 1, SoundType::SE );
                        SceneSwitcher::change( SceneType::PLAY );
                    }
                });
            });
        }
        page->addPage(layout);
    }
    
    //カーソル
    ImageView* RightCursor = ImageView::create( "Texture/Debug/RightCursor.png" );
    RightCursor->setPosition( Vec2( 650, 800 ) );
    ScaleTo* startRScale = ScaleTo::create( 1.0f, 1.0f );
    ScaleTo* endRScale = ScaleTo::create( 1.0f, 0.5f );
    RightCursor->runAction( RepeatForever::create( Sequence::create( startRScale, endRScale, NULL ) ) );
    page->addChild( RightCursor );
    
    //カーソル
    ImageView* LeftCursor = ImageView::create( "Texture/Debug/LeftCursor.png" );
    LeftCursor->setPosition( Vec2( 50, 800 ) );
    ScaleTo* startLScale = ScaleTo::create( 1.0f, 1.0f );
    ScaleTo* endLScale = ScaleTo::create( 1.0f, 0.5f );
    LeftCursor->runAction( RepeatForever::create( Sequence::create( startLScale, endLScale, NULL ) ) );
    page->addChild( LeftCursor );

    node->addChild( page );
}