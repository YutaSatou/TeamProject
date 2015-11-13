//
//  StageView.h
//  PSStageCreate
//
//  Created by 星共法 on 2015/10/25.
//
//

#ifndef _StageView__
#define _StageView__

#include "System/SystemCore.h"

class StageView : public Node
{
public:
    using CallBack = std::function<void(Ref*)>;
    
    CREATE_FUNC_PARAM1(StageView, CONST_REF(CallBack))
    
private:
    StageView();
    ~StageView();
    virtual bool init(CONST_REF(CallBack));
};

#endif /* defined(_StageView__) */
