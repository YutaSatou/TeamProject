//
//  StageSelectButton.cpp
//  TeamProject
//
//  Created by Satou yuta on 2015/12/07.
//
//

#include "StageSelectButton.h"
#include "ui/CocosGUI.h"
#include "../../Utility/Audio/ADX2Player.h"
#include "../../Utility/Assistant/Scene/SceneChanger.h"
#include "../../Utility/Assistant/Scene/SceneCreator.h"
#include "../GamePlay/GamePlayLayer.h"
#include "../../Utility/DataIO/StageNumber.h"

using namespace cocos2d;
using namespace ui;

bool StageSelectButton::init()
{
    if ( !Node::init() )
    {
        return false;
    }
    
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
    
    for ( int i = 0; i < 27; ++i )
    {
        Button* button = Button::create( "Texture/GameStageSelect/Stage_Numberbox_Notclear.png" );
        button->setTitleText( StringUtils::toString( i + 1 ) );
        button->setTitleFontName( "Font/RiiPopkkR.otf" );
        button->setTitleFontSize( 68 );
        button->setTitleColor( Color3B::BLACK );
        button->setZoomScale( 0.1f );
        
        button->setPosition( poses[ i ] );
        
        button->addTouchEventListener( [ = ]( Ref* sender, Widget::TouchEventType type ){
            
            if ( type == Widget::TouchEventType::BEGAN ){
            }
            if ( type == Widget::TouchEventType::ENDED ){
                ADX2Player::getInstance().play( 6 );
                //StageNumber::saveStageNumber( i + 1 );
                Scene* scene		{ SceneCreator::createScene( GamePlayLayer::create() ) };
                Scene* nextScene	{ TransitionRotoZoom::create( 0.8f, scene ) };
                SceneChanger::switchScene( nextScene );
            }
        });
        
        addChild( button );
    }
    
    return true;
}

StageSelectButton* StageSelectButton::create()
{
    StageSelectButton* inst = new StageSelectButton();
    
    if ( inst && inst->init() )
    {
        inst->autorelease();
        return inst;
    }
    
    CC_SAFE_DELETE( inst );
    return nullptr;
}
