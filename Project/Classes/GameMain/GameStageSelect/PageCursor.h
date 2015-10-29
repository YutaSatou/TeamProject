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

class PageCursor : public cocos2d::Layer{

protected:
    
    PageCursor() = default;
    
    ~PageCursor() = default;
    
    virtual bool init() override;
    
    virtual void update( float deltaTime ) override;
    
public:
    
    PageCursor* create();
    
private:

};

#endif
