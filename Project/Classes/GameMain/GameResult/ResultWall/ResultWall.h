//
//  ResultSlimeContainer.hpp
//  TeamProject
//
//  Created by Satou yuta on 2016/01/16.
//
//

#ifndef _RESULTWALL_H_
#define _RESULTWALL_H_

#include "cocos2d.h"
#include "../../GamePlay/LiquidFun/LiquidFunDefine.h"

class ResultWall : public cocos2d::Node
{
	
protected:
	
	ResultWall();
	
	~ResultWall() = default;
	
	bool init( const cocos2d::Vec2& start, const cocos2d::Vec2& end );
	
public:
	
	static ResultWall* create( const cocos2d::Vec2& start, const cocos2d::Vec2& end );
	
private:
	
	void initPhysics( const cocos2d::Vec2& start, const cocos2d::Vec2& end );
	
private:
	
	LiquidFunBody* mBody;
};

#endif
