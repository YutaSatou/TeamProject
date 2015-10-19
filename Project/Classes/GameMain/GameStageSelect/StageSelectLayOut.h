//
//  StageSelectLayOut.h
//  TeamProject
//
//  Created by Satou yuta on 2015/09/14.
//
//

#ifndef _STAGESELECTLAYOUT_H_
#define _STAGESELECTLAYOUT_H_

#include <cocos2d.h>
#include "ui/CocosGUI.h"
#include "../../Utility/Audio/ADX2Player.h"

class StageSelectLayOut : public cocos2d::Layer{
    
private:
    
    ADX2Player* mPlayer;
    
protected:
    
    StageSelectLayOut();
    
    ~StageSelectLayOut();
    
    void update( float deltaTime );
    
    bool init();
    
private:
    
    /**
     *	@brief	ボタン作成
     *	@param	offButton   ボタンのテクスチャ
     *	@param	onButton    ボタンが押された時のテクスチャ
     *	@param  stageTag    ステージの番号
     */
    cocos2d::ui::Button* createButton( const std::string& offButton, const std::string& onButton, const std::string& disButton, int stageTag);
    
    cocos2d::Label* createLabel( std::string number, const std::string& font, float fontSize, const cocos2d::Vec2& fontPos );
    
    void PageListener( Ref* sender, cocos2d::ui::PageViewEventType type );
    
public:
    
    static StageSelectLayOut* create();
    
    /**
     *	@brief	ページ作成
     *	@param	pageNum   作成するページ数
     */
    void createPage(cocos2d::Node* node, int pageNum );
    
};

#endif /* defined(__TeamProject__StageSelectLayOut__) */
