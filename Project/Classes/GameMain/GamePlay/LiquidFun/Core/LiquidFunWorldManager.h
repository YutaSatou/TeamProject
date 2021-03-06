#ifndef _LIQUID_FUN_WORLD_MANAGER_H_
#define _LIQUID_FUN_WORLD_MANAGER_H_

#include "cocos2d.h"
#include "LiquidFunBox2D.h"
#include "Utility/Template/Singleton.h"

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
	~LiquidFunWorldManager() = default;
	
	/**
	 *	@brief	更新
	 */
	void update();
	
	/**
	 *	@brief	コンタクトリスナの登録
	 *	@param	contactListener	コンタクトリスナ
	 */
	void registerContactListener( LiquidFunBaseContactListener* contactListener );
	
	/**
	 *	@brief	AABBクエリの登録
	 *	@param	callback	コールバック
	 *	@param	aabb		検索する範囲
	 */
	void registerAABBQuery( LiquidFunQueryCallback* callback, const LiquidFunAABB& aabb );
	
	/**
	 *	@brief	ボディの追加
	 *	@param	bodyDesc		ボディ設定記述子
	 *	@return	LiquidFunBody	ボディのインスタンス( ワールドに登録済 )
	 */
	LiquidFunBody* addBody( const LiquidFunBodyDesc* bodyDesc );
	
	/**
	 *	@brief	ジョイントの追加
	 *	@param	jointDesc		ジョイント設定記述子
	 *	@return	LiquidFunJoint	ジョイントのインスタンス( ワールドに登録済 )
	 */
	LiquidFunJoint* addJoint( const LiquidFunJointDesc* jointDesc );
	
	/**
	 *	@brief	パーティクルの追加
	 *	@param	particleDesc		パーティクル設定記述子
	 *	@return	LiquidFunParticle	パーティクルのインスタンス( ワールドに登録済 )
	 */
	LiquidFunParticle* addParticle( const LiquidFunParticleDesc* particleDesc );
	
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
	friend class LiquidFunDebugDrawer;	// Debug用だから特別。
	
	using LiquidFunWorldPtr		= std::shared_ptr< LiquidFunWorld >;
	using LiquidFunSchedulerPtr	= std::shared_ptr< LiquidFunScheduler >;
	
	LiquidFunWorldPtr		mWorld;		//=> ワールド
	LiquidFunSchedulerPtr	mScheduler;	//=> 定期実行者
	cocos2d::Vect			mGravity;	//=> 重力値
};

#endif