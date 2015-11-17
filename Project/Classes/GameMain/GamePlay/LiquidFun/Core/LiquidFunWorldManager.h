#ifndef _LIQUID_FUN_WORLD_MANAGER_H_
#define _LIQUID_FUN_WORLD_MANAGER_H_

#include "Utility/Template/Singleton.h"
#include "cocos2d.h"
#include "LiquidFunBox2D.h"

class LiquidFunScheduler;

/*------------------------------------------------------------*/
//	@class		：	LiquidFunWorldManager
//	@brief		：	LiquidFunのワールド管理者
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class LiquidFunWorldManager : public Singleton< LiquidFunWorldManager >
{
	
public:
	
	/**
	 *	@brief	デストラクタ
	 */
	~LiquidFunWorldManager();
	
	/**
	 *	@brief	更新
	 */
	void update();
	
	/**
	 *	@brief	ボディの追加
	 *	@param	bodyDef			ボディの情報
	 *	@return	LiquidFunBody	ボディのインスタンス( ワールドに登録済 )
	 */
	LiquidFunBody* addBody( const LiquidFunBodyDef* bodyDef );
	
	/**
	 *	@brief	ジョイントの追加
	 *	@param	jointDef		ジョイントの情報
	 *	@return	LiquidFunJoint	ジョイントのインスタンス( ワールドに登録済 )
	 */
	LiquidFunJoint* addJoint( const LiquidFunJointDef* jointDef );
	
	/**
	 *	@brief	パーティクルの追加
	 *	@param	particleDef			パーティクルの情報
	 *	@return	LiquidFunParticle	パーティクルのインスタンス( ワールドに登録済 )
	 */
	LiquidFunParticle* addParticle( const LiquidFunParticleDef* particleDef );
	
	/**
	 *	@brief	ボディの削除
	 *	@param	body	ボディのインスタンス
	 */
	void deleteBody( LiquidFunBody* body );
	
	/**
	 *	@brief	ジョイントの削除
	 *	@param	joint	ジョイントのインスタンス
	 */
	void deleteJoint( LiquidFunJoint* joint );
	
	/**
	 *	@brief	パーティクルの削除
	 *	@param	particle	パーティクルのインスタンス
	 */
	void deleteParticle( LiquidFunParticle* particle );
	
	/**
	 *	@brief	重力値の取得
	 *	@return	Vect	重力値
	 */
	cocos2d::Vect getGravity() const;
	
	/**
	 *	@brief	重力値の設定
	 *	@param	gravity	重力値
	 */
	void setGravity( const cocos2d::Vect& gravity );
	
private:
	
	/**
	 *	@brief	コンストラクタ
	 */
	LiquidFunWorldManager();
	
private:
	
	friend class Singleton< LiquidFunWorldManager >;
	friend class LiquidFunDebugDrawer;
	
	LiquidFunWorld*		mWorld;		//=> ワールド
	LiquidFunScheduler*	mScheduler;	//=> 定期実行
	cocos2d::Vect		mGravity;	//=> 重力値
};

#endif