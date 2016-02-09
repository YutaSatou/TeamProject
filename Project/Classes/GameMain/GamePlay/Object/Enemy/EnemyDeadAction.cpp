#include "EnemyDeadAction.h"
#include "cocos2d.h"

using namespace cocos2d;

ActionInterval* EnemyDeadAction::create( float deadTime, int blinkCount )
{
	ActionInterval*	scaleAction		{ ScaleTo::create( deadTime, 0.0f ) };
	ActionInterval*	blinkAction		{ Blink::create( deadTime, blinkCount ) };
	ActionInterval* deadAction		{ Spawn::create( scaleAction, blinkAction, nullptr ) };
	ActionInterval*	removeAction	{ Sequence::create( deadAction, RemoveSelf::create(), nullptr ) };
	
	return removeAction;
}