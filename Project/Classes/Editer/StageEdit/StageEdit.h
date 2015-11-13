//
//  StageEdit.h
//  PSStageCreate
//
//  Created by 星共法 on 2015/10/25.
//
//

#ifndef _StageEdit__
#define _StageEdit__

#include "Utility/FileIO/Plist/PlistIO.h"

#include "System/SystemCore.h"
#include "System/Widget/ButtonTable/ButtonTable.h"

namespace  {
    const float ANIMATION_TIME { 0.2f };
}

class StageEdit : public Node
{
public:
    using CallBack = std::function<void(Ref*)>;
    
    CREATE_FUNC_PARAM1(StageEdit, CONST_REF(CallBack))
    
private:
    StageEdit();
    ~StageEdit();
    virtual bool init(CONST_REF(CallBack) cb);
    
    void enterIn(); //  エディターから返ってくる時の処理
    void exitOut(); //  エディターへ以降する時の処理
    void setStageListEnable(bool enable);   //  ステージリストの有効状態を設定
    void enableStagelist(); //  ステージリストを有効にする
    
private:
    Utility::FileIO::PlistIO mPlist;
    System::Widget::ButtonTable* mStageList { nullptr };
    CallBack mReturnScene { nullptr };    // EditSceneに戻るためのコールバックをメンバで保持
    bool mIsEnable { true };
};

#endif /* defined(_StageEdit__) */
