#ifndef _DEBUG_TESTAREA_H_
#define _DEBUG_TESTAREA_H_

#include "cocos2d.h"

class TestArea : public cocos2d::LayerColor
{
	
protected:
	
	TestArea() = default;
	
	~TestArea() = default;
	
	virtual bool init() override;
	
public:
	
	static TestArea* create();
};

#endif