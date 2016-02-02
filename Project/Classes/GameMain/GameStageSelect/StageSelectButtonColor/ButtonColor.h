//
//  ButtonColor.hpp
//  TeamProject
//
//  Created by Satou yuta on 2016/02/01.
//
//

#ifndef _BUTTONCOLOR_H_
#define _BUTTONCOLOR_H_

#include "cocos2d.h"

class ButtonColor
{
protected:
	
public:
	
	ButtonColor() = default;
	
	~ButtonColor() = default;
	
	bool isStageClear( int stageNum );
	
	cocos2d::Color3B buttonColor( int stageNum );
	
private:
	
	std::string loadPlist( int stageNum ) const;
};

#endif
