//
//  ButtonTable.h
//  PSStageCreate
//
//  Created by 星共法 on 2015/10/25.
//
//

#ifndef _ButtonTable__
#define _ButtonTable__

#include "System/SystemCore.h"
#include "System/Widget/Button/Button.h"

namespace System
{
namespace Widget
{
    class ButtonTable : public Node
    {
    public:
        CREATE_FUNC_PARAM2(ButtonTable, CONST_REF(Vec2), CONST_REF(Vec2))
        
        bool pushback(Button* button);      //  テーブルにボタンをプッシュする
        void setTouchEnable(bool enable);   //  タッチに反応するか設定する
        
    private:
        ButtonTable();
        ~ButtonTable();
        virtual bool init(CONST_REF(Vec2) num, CONST_REF(Vec2) margin);
        
    private:
        std::vector<Vec2> mPosList;
        std::vector<Button*> mButtonList;
        Vec2 mTileSize;
    };
}
}
#endif /* defined(_ButtonTable__) */
