//
//  Button.h
//  PSStageCreate
//
//  Created by 星共法 on 2015/10/19.
//
//

#ifndef _Button__
#define _Button__

#include "System/SystemCore.h"

#include "System/Input/Touch/TouchListener.h"

namespace System{
namespace Widget{
    class Button : public Node
    {
    public:
        using CallBack = std::function<void(Ref*)>;
        
        CREATE_FUNC_PARAM1(Button, CONST_REF(std::string))
        
        // @brief 外部からボタン押下時の挙動について変更できるようにする
        void setCallBackOnTouchBegan(CONST_REF(CallBack) cb);   //  押した時
        void setCallBackOnTouchMoved(CONST_REF(CallBack) cb);   //  移動した時
        void setCallBackOnTouchEnded(CONST_REF(CallBack) cb);   //  離した時
        void setCallBackOnTouchCancel(CONST_REF(CallBack) cb);  //  以上終了時
        
        void setSize(CONST_REF(Vec2) size);     //  リサイズ
        void setScale(CONST_REF(Vec2) scale);   //  スケーリング
        void setTouchEnable(bool enable);       //  タッチに反応するかを設定する
        
    private:
        Button();
        virtual ~Button();
        virtual bool init(CONST_REF(std::string));
        bool isContains(CallBack* callback, Touch* touch, Event* event); // タッチ処理時に矩形内へのタッチか判定する処理を割りこませる
        
    private:
        Sprite* mBackground;
        SingleTouchEventDesc mTouchDesc;
        CallBack mCallbackBegan;
        CallBack mCallbackMoved;
        CallBack mCallbackEnded;
        CallBack mCallbackCancel;
        
        bool mTouchEnable { true };
    };
}
}

#endif /* defined(_Button__) */
