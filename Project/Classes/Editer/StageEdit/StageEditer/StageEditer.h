//
//  StageEditer.h
//  PSStageCreate
//
//  Created by 星共法 on 2015/10/26.
//
//

#ifndef _StageEditer__
#define _StageEditer__

#include "Utility/FileIO/Plist/PlistIO.h"

#include "System/SystemCore.h"

class StageEditer : public Node
{
public:
    using CallBack = std::function<void(Ref*)>;
    
    CREATE_FUNC_PARAM2(StageEditer, CONST_REF(Utility::FileIO::PlistIO), CONST_REF(CallBack))
    
private:
    StageEditer();
    ~StageEditer();
    virtual bool init(CONST_REF(Utility::FileIO::PlistIO) plist, CONST_REF(CallBack) cb);
    
private:
    CallBack mReturnStageSelect { nullptr };
};

#endif /* defined(_StageEditer__) */
