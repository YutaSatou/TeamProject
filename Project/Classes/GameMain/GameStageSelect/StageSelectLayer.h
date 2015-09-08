#ifndef _STAGE_SELECT_LAYER_H_
#define _STAGE_SELECT_LAYER_H_

#include "cocos2d.h"

class StageSelectLayer : public cocos2d::LayerColor
{
	
protected:
	
	StageSelectLayer() = default;
	
	~StageSelectLayer() = default;
	
	virtual bool init() override;
	
	virtual void update( float deltaTime ) override;
	
public:
	
	static StageSelectLayer* create();
};

#endif