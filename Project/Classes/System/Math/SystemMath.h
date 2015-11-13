//
//  GameSystemMath.h
//  PSStageCreate
//
//  Created by 星共法 on 2015/10/16.
//
//

#ifndef GameSystemMath_h
#define GameSystemMath_h

#include "System/SystemCore.h"

namespace System
{
namespace Math
{
    //  toに対するfromのサイズについて倍率を算出する
    static Vec2 toScale(Vec2 from, Vec2 to)
    {
        return Vec2(from.x / to.x, from.y / to.y);
    }
}
}
#endif /* GameSystemMath_h */
