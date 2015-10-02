#ifndef _GAMETITLE_LAYER_
#define _GAMETITLE_LAYER_

#include "cocos2d.h"
#include "../../Utility/Audio/ADX2Player.h"

class GameTitleLayer : public cocos2d::LayerColor
{
	
protected:
	
	GameTitleLayer();
	
	~GameTitleLayer();
	
	virtual bool init() override;
	
	virtual void update( float deltaTime ) override;
	
public:
	
	static GameTitleLayer* create();
    
    //タッチ
    void touchListener();
    
private:
    
    ADX2Player* mPlayer;
    
};

#endif