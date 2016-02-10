#include "EnemyDeadAction.h"
#include "cocos2d.h"

using namespace cocos2d;

// インスタンスの生成
ActionInterval* EnemyDeadAction::create( float deadTime, int blinkCount )
{
	ScaleTo*	scaleAction		{ ScaleTo::create( deadTime, 0.0f ) };
	Blink*		blinkAction		{ Blink::create( deadTime, blinkCount ) };
	Spawn*		deadAction		{ Spawn::create( scaleAction, blinkAction, nullptr ) };
	RemoveSelf*	removeAction	{ RemoveSelf::create() };
	
	return Sequence::create( deadAction, removeAction, nullptr );
}