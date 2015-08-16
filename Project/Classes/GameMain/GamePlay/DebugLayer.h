#ifndef _DEBUG_LAYER_H_
#define _DEBUG_LAYER_H_

#include "cocos2d.h"

class DebugLayer : public cocos2d::LayerColor
{
	
protected:
	
	DebugLayer() = default;
	
	~DebugLayer() = default;
	
	virtual bool init() override;
	
	virtual void update( float deltaTime ) override;
	
public:
	
	static DebugLayer* create();
};

#endif