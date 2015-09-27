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

class StageSelectLayOut : public cocos2d::Layer{
    
protected:
    
    StageSelectLayOut();
    
    ~StageSelectLayOut();
    
    void update( float deltaTime );
    
    bool init();
    
public:
    
    static StageSelectLayOut* create();
    
    /**
     *	@brief	ボタン作成
     *	@param	offButton   ボタンのテクスチャ
     *	@param	onButton    ボタンが押された時のテクスチャ
      *	@param  stageTag    ステージの番号
     */
    static cocos2d::ui::Button* createButton( const std::string& offButton, const std::string& onButton, int stageTag);
    
    /**
     *	@brief	ページ作成
     *	@param	pageNum   作成するページ数
     */
    static cocos2d::ui::PageView* createPage( int pageNum );
};

#endif /* defined(__TeamProject__StageSelectLayOut__) */
