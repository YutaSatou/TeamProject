//
//  ButtonTable.cpp
//  PSStageCreate
//
//  Created by 星共法 on 2015/10/25.
//
//

#include "System/Widget/ButtonTable/ButtonTable.h"

#include "System/Math/SystemMath.h"

using namespace System::Math;

namespace System
{
namespace Widget
{
    ButtonTable::ButtonTable()
    {
        
    }

    ButtonTable::~ButtonTable()
    {
        
    }

    bool ButtonTable::init(CONST_REF(Vec2) num, CONST_REF(Vec2) margin)
    {
        if(!Node::init()) return false;
        
        const Vec2 scrSize { Director::getInstance()->getVisibleSize() };
        const Vec2 oneTileArea { scrSize.x / num.x, scrSize.y / num.y};
        
        //  ボタンの配置される座標を予め全て算出しておく
        mPosList.clear();
        for(int x = 0; x < num.x; x++)
        {
            const float horizontal = (oneTileArea.x * x) + oneTileArea.x  / 2;
            for(int y = 0; y < num.y; y++)
            {
                const float vertical = (oneTileArea.y * y) + oneTileArea.y  / 2;
                mPosList.push_back(Vec2(horizontal, vertical));
            }
        }
        
        //  配置に合わせてボタンの大きさを決める
        mTileSize = Vec2(oneTileArea.x - margin.x, oneTileArea.y - margin.y);
        mButtonList.resize(mPosList.size());
        
        return true;
    }
    
    //  テーブルにボタンをプッシュする
    bool ButtonTable::pushback(Button* button)
    {
        for(int i = 0; i < mPosList.size(); i++)
        {
            if(!mButtonList.at(i))
            {
                const Vec2 scale { toScale(mTileSize, button->getContentSize()) };
                button->setScale(scale);
                button->setContentSize(Size(mTileSize.x, mTileSize.y));
                button->setPosition(Vec2(mPosList.at(i).x, mPosList.at(i).y));
                this->addChild(button);
                mButtonList.at(i) = button;
                return true;
            }
        }
        return false;
    }
    
    //  タッチに反応するか設定する
    void ButtonTable::setTouchEnable(bool enable)
    {
        for(Button* button : mButtonList)
        {
            if(!button) continue;
            button->setTouchEnable(enable);
        }
    }
}
}