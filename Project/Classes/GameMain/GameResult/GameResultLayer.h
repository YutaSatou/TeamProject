#ifndef _GAMERESULT_LAYER_H_
#define _GAMERESULT_LAYER_H_

#include "cocos2d.h"

class ResultManager;

class GameResultLayer : public cocos2d::LayerColor
{
	
protected:
	
	GameResultLayer() = default;
	
	~GameResultLayer() = default;
	
	virtual bool init() override;
	
	virtual void update( float deltaTime ) override;
	
public:
	
	static GameResultLayer* create();
    
private:
    
    //タッチ
    void touchListener();
    
    ResultManager* mResultManager;
};

#endif