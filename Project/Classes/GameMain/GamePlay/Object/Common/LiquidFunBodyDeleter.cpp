#include "LiquidFunBodyDeleter.h"
#include "../../LiquidFun/LiquidFunUserAPI.h"

// コンストラクタ
LiquidFunBodyDeleter::LiquidFunBodyDeleter()
	: Deleter()
{
	registerDeleteFunction( []( LiquidFunBody* body ) { LiquidFunBodySettlor::detachBody( body ); } );
}

// インスタンスの生成
LiquidFunBodyDeleter* LiquidFunBodyDeleter::create( LiquidFunBody* body )
{
	LiquidFunBodyDeleter* inst { new LiquidFunBodyDeleter() };
	
	if ( inst && inst->init() )
	{
		inst->autorelease();
		inst->registerDeleteInstance( body );
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}