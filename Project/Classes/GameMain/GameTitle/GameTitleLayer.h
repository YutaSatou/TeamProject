#ifndef _GAMETITLE_LAYER_
#define _GAMETITLE_LAYER_

#include "cocos2d.h"

class GameTitleLayer : public cocos2d::LayerColor
{
	
protected:
	
	GameTitleLayer() = default;
	
	~GameTitleLayer() = default;
	
	virtual bool init() override;
	
public:
	
	static GameTitleLayer* create();
    
private:
    
    void drawSprite( const std::string& fileName, const cocos2d::Vec2& pos, bool isAnimation );
    
    //タッチ
    void touchListener();
};

#endif