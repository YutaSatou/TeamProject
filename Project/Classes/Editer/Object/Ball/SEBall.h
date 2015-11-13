//
//  SEBall.h
//  PSStageCreate
//
//  Created by 星共法 on 2015/11/09.
//
//

#ifndef _SEBall__
#define _SEBall__

#include "System/SystemCore.h"

class SEBall : public Node
{
public:
    CREATE_FUNC(SEBall)
    
private:
    SEBall();
    ~SEBall();
    virtual bool init();
};

#endif /* defined(_SEBall__) */
