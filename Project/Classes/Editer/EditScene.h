//
//  EditScene.h
//  PSStageCreate
//
//  Created by 星共法 on 2015/10/16.
//
//

#ifndef __EditScene__
#define __EditScene__

#include "System/SystemCore.h"
#include "System/Widget/ButtonTable/ButtonTable.h"

namespace {
    enum class PLAY_TYPE
    {
        EDIT, VIEW, EMP1, EMP2, EMP3, EMP4, NONE, SIZE
    };
    
    static const std::map<PLAY_TYPE, std::string> spriteNameList
    {
        { PLAY_TYPE::EDIT, "res/texture/toStageEdit.png" },
        { PLAY_TYPE::VIEW, "res/texture/toStageView.png" },
        { PLAY_TYPE::EMP1, "HelloWorld.png" },
        { PLAY_TYPE::EMP2, "HelloWorld.png" },
        { PLAY_TYPE::EMP3, "HelloWorld.png" },
        { PLAY_TYPE::EMP4, "HelloWorld.png" },
    };
}

class EditScene : public Layer
{
private:
    //  タイルの並ぶ数
    static const int ALIGNMENT_WIDTH_NUM { 2 };
    static const int ALIGNMENT_HEIGHT_NUM { 3 };
    //  タイルの最大数
    static const int TILE_MAX_NUM { ALIGNMENT_WIDTH_NUM * ALIGNMENT_HEIGHT_NUM };
    
public:
    static Scene* createScene();
    
private:
    EditScene();
    ~EditScene();
    virtual bool init() override;
    
    void onPlay(PLAY_TYPE type);    //  作業を開始する
    void tableActivate();           //  テーブルを有効にする
    void playObjectDestroy();       //  作業オブジェクトの破棄
    
private:
    System::Widget::ButtonTable* mPlayTable { nullptr };
    Node* mPlayObject { nullptr };       //  作業オブジェクト
};

#endif /* defined(_EditScene__) */
