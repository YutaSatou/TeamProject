#ifndef _BALL_H_
#define _BALL_H_

#include "cocos2d.h"

class Ball : public cocos2d::Sprite
{
	
protected:
	
	Ball() = default;
	
	~Ball() = default;
	
	bool init( const cocos2d::Vec2& position );
	
public:
	
	static Ball* create( const cocos2d::Vec2& position );
	
private:
	
	void initPhysics();
};

#endif