#ifndef _GAMETITLE_LAYER_
#define _GAMETITLE_LAYER_

#include "cocos2d.h"

class GameTitleLayer : public cocos2d::LayerColor
{
	
protected:
	
	GameTitleLayer() = default;
	
	~GameTitleLayer() = default;
	
	virtual bool init() override;
	
	virtual void update( float deltaTime ) override;
	
public:
	
	static GameTitleLayer* create();
    
    //タッチ
    void touchListener();
    
};

#endif