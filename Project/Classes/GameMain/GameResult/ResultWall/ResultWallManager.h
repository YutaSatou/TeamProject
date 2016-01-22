//
//  ResultWallManager.hpp
//  TeamProject
//
//  Created by Satou yuta on 2016/01/16.
//
//

#ifndef _RESULTWALLMANAGER_H_
#define _RESULTWALLMANAGER_H_

#include "cocos2d.h"

class ResultWallManager : public cocos2d::Node
{
	
protected:
	
	ResultWallManager() = default;
	
	~ResultWallManager() = default;
	
	bool init();
	
public:
	
	static ResultWallManager* create();
};

#endif
