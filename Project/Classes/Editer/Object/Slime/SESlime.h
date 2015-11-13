//
//  SESlime.h
//  PSStageCreate
//
//  Created by 星共法 on 2015/11/09.
//
//

#ifndef _SESlime__
#define _SESlime__

#include "System/SystemCore.h"

class SESlime : public Node
{
public:
    CREATE_FUNC(SESlime)
    
private:
    SESlime();
    ~SESlime();
    virtual bool init();
};

#endif /* defined(_SESlime__) */
