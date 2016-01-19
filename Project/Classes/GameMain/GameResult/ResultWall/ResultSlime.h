//
//  ResultSlime.hpp
//  TeamProject
//
//  Created by Satou yuta on 2016/01/18.
//
//

#ifndef ResultSlime_hpp
#define ResultSlime_hpp

#include "cocos2d.h"
#include "../../GamePlay/LiquidFun/LiquidFunDefine.h"

class ResultSlime : public cocos2d::Node
{
	
protected:
	
	ResultSlime();
	
	~ResultSlime() = default;
	
	bool init( const cocos2d::Vec2* points, int pointCount );
	
public:
	
	static ResultSlime* create( const cocos2d::Vec2* points, int pointCount );
	
private:
	
	void initPhysics( const cocos2d::Vec2* points, int pointCount );
	
private:
	
	LiquidFunBody* mBody;
};


#endif
