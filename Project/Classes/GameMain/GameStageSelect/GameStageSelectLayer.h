#ifndef _GAMESTAGE_SELECT_LAYER_H_
#define _GAMESTAGE_SELECT_LAYER_H_

#include "cocos2d.h"

class GameStageSelectLayer : public cocos2d::LayerColor
{
    
protected:
    
    GameStageSelectLayer();
    
    ~GameStageSelectLayer();
    
    virtual bool init() override;
    
    virtual void update( float deltaTime ) override;
    
public:
    
    static GameStageSelectLayer* create();
    
private:
    
    void drawBackGraund();
    
    void drawStageSelectLogo();
};

#endif