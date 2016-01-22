//
//  ResultTexturePhysics.hpp
//  TeamProject
//
//  Created by Satou yuta on 2016/01/18.
//
//

#ifndef ResultTexturePhysics_hpp
#define ResultTexturePhysics_hpp

#include "cocos2d.h"
#include "../../GamePlay/LiquidFun/LiquidFunDefine.h"

class ResultTexturePhysics : public cocos2d::Node
{
	
protected:
	
	ResultTexturePhysics();
	
	~ResultTexturePhysics() = default;
	
	bool init( float radius, const cocos2d::Vec2& pos );
	
public:
	
	static ResultTexturePhysics* create( float radius, const cocos2d::Vec2& pos );
	
private:
	
	void initPhysics( float radius );
	
private:
	
	LiquidFunBody* mBody;
};
#endif
