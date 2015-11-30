//
//  StageSelectOption.h
//  TeamProject
//
//  Created by Satou yuta on 2015/11/06.
//
//

#ifndef _STAGESELECTPOTION_H_
#define _STAGESELECTPOTION_H_

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class StageSelectOption : public cocos2d::Layer {
    
protected:

    StageSelectOption() = default;
    
    ~StageSelectOption() = default;
    
    virtual bool init() override;
    
    virtual void update( float deltaTime ) override;
    
public:
    
    static StageSelectOption* create();
    
private:
    
    void option( cocos2d::Node* node, const std::string& tex, cocos2d::Vec2& pos );
};

#endif
