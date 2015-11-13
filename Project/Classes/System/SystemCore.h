//
//  SystemCore.h
//  PSStageCreate
//
//  Created by 星共法 on 2015/11/08.
//
//

#ifndef __SystemCore__
#define __SystemCore__

#include "cocos2d.h"

using namespace cocos2d;

#define ETOI(target) (static_cast<int>(target))
#define ITOE(target, TYPE) (static_cast<TYPE>(target))
#define CONST_REF(TYPE) const TYPE&

#define CREATE_FUNC_PARAM1(__TYPE__, __PARAM__) \
static __TYPE__* create(__PARAM__ param) \
{ \
    __TYPE__* ret = new __TYPE__(); \
    if (ret && ret->init(param)) \
    { \
        ret->autorelease(); \
        return ret; \
    } \
    else \
    { \
        delete ret; \
        ret = nullptr; \
    } \
    return ret; \
}

#define CREATE_FUNC_PARAM2(__TYPE__, __PARAM1__, __PARAM2__) \
static __TYPE__* create(__PARAM1__ param1, __PARAM2__ param2) \
{ \
    __TYPE__* ret = new __TYPE__(); \
    if (ret && ret->init(param1, param2)) \
    { \
        ret->autorelease(); \
        return ret; \
    } \
    else \
    { \
        delete ret; \
        ret = nullptr; \
    } \
    return nullptr; \
}

#ifdef COCOS2D_DEBUG
#define LOG(...) cocos2d::log(__VA_ARGS__);
#define LOG_FUNC cocos2d::log("%s : %i",  __FILE__, __LINE__);
#define LOG_FUNC_MSG(message) cocos2d::log("%s : %i ... %s",  __FILE__, __LINE__, message);
#else
#define LOG
#define FUNC_LOG
#define FUNC_LOG_MSG
#endif

#endif /* defined(_SystemCore__) */
