#include "LiquidFunScheduler.h"
#include "LiquidFunBox2D.h"
#include "LiquidFunHelper.h"
#include "cocos2d.h"

using namespace cocos2d;

namespace
{
	const float	TIME_STEP			= 1.0f / 60.0f;	// 物理エンジンの更新フレーム
	const int	VELOCITY_ITERATIONS	= 6;			// 移動の更新頻度
	const int	POSITION_ITERATIONS	= 4;			// 座標の更新頻度
	const int	PARTICLE_ITERATIONS	= 2;			// 粒子の更新頻度
}

// コンストラクタ
LiquidFunScheduler::LiquidFunScheduler( LiquidFunWorld* world )
	: mWorld( world )
{
	
}

// 更新
void LiquidFunScheduler::update()
{
	updateBox2D();
	
	updateWorldNode();
}

// 物理エンジンの更新
void LiquidFunScheduler::updateBox2D()
{
	mWorld->Step( TIME_STEP, VELOCITY_ITERATIONS, POSITION_ITERATIONS, PARTICLE_ITERATIONS );
}

// ワールド内のノードの更新
void LiquidFunScheduler::updateWorldNode()
{
	for ( LiquidFunBody* body = mWorld->GetBodyList(); body; body = body->GetNext() )
	{
		if ( !body->GetUserData() )
		{
			// ユーザデータが登録されていない場合は戻る。
			continue;
		}
		
		// ユーザデータからノードを取り出して、Cocos2d-x用に座標、角度の変換を行う。
		Node* node = LiquidFunHelper::getNode( body );
		node->setPosition( LiquidFunHelper::toPixsel( body->GetPosition() ) );
		node->setRotation( CC_RADIANS_TO_DEGREES( body->GetAngle() ) * -1 );
	}
}