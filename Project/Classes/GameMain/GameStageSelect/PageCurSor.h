//
//  PageCurSor.h
//  TeamProject
//
//  Created by Satou yuta on 2015/10/23.
//
//

#ifndef _PAGECURSOR_H_
#define _PAGECURSOR_H_

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class PageCurSor : public cocos2d::Layer{

protected:
    
    PageCurSor() = default;
    
    ~PageCurSor() = default;
    
    virtual bool init() override;
    
    virtual void update( float deltaTime ) override;
    
public:
    
    PageCurSor* create();
    
private:

};

#endif
