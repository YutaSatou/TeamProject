#ifndef _BRUSH_H_
#define _BRUSH_H_

#include "cocos2d.h"

class BrushTrail;

class Brush : public cocos2d::Node
{
	
protected:
	
	Brush();
	
	~Brush();
	
	virtual bool init() override;
	
public:
	
	static Brush* create();
	
private:
	
	void initTouchListener();
	
private:
	
	BrushTrail*	mBrushTrail;
};

#endif