#ifndef _LIQUID_FUN_CONTACT_LISTENER_H_
#define _LIQUID_FUN_CONTACT_LISTENER_H_

#include "cocos2d.h"
#include "../Core/LiquidFunBox2D.h"

/*------------------------------------------------------------*/
//	@class		：	LiquidFunContactListener
//	@brief		：	LiquidFunの接触検知リスナ
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class LiquidFunContactListener : public cocos2d::Node, public LiquidFunBaseContactListener
{
	
protected:
	
	/**
	 *	@brief	コンストラクタ
	 */
	LiquidFunContactListener();
	
	/**
	 *	@brief	デストラクタ
	 */
	~LiquidFunContactListener() = default;
	
	/**
	 *	@brief	初期化
	 *	@return	bool	初期化が完了したか否か
	 */
	virtual bool init() override;
	
public:
	
	/**
	 *	@brief	インスタンスの生成
	 *	@return	LiquidFunContactListener	インスタンス
	 */
	static LiquidFunContactListener* create();
	
private:
	
	/**
	 *	@brief	剛体と剛体の接触時に呼ばれるコールバック関数
	 *	@param	contact	接触したオブジェクトの情報
	 */
	virtual void BeginContact( LiquidFunContact* contact ) override;
	
	/**
	 *	@brief	剛体と剛体の接触中に呼ばれるコールバック関数
	 *	@param	contact		接触したオブジェクトの情報
	 *	@param	oldManifold	接触した箇所の詳細情報
	 */
	virtual void PreSolve( LiquidFunContact* contact, const LiquidFunManifold* oldManifold ) override;
	
	/**
	 *	@brief	剛体と剛体の離脱時に呼ばれるコールバック関数
	 *	@param	contact	接触したオブジェクトの情報
	 */
	virtual void EndContact( LiquidFunContact* contact ) override;
	
	/**
	 *	@brief	剛体と液体の接触時に呼ばれるコールバック関数
	 *	@param	particle	接触したパーティクル
	 *	@param	contact		接触したオブジェクトの情報
	 */
	virtual void BeginContact( LiquidFunParticle* particle, LiquidFunParticleBodyContact* contact ) override;
	
	/**
	 *	@brief	剛体と液体の離脱時に呼ばれるコールバック関数
	 *	@param	fixture		接触したフィクスチャ
	 *	@param	particle	接触したパーティクル
	 *	@param	index		接触したパーティクルのインデックス
	 */
	virtual void EndContact( LiquidFunFixture* fixture, LiquidFunParticle* particle, int index ) override;
	
public:
	
	using ContactRigidBegin		= std::function< void( LiquidFunContact* ) >;
	using ContactRigidPreSolve	= std::function< void( LiquidFunContact*, const LiquidFunManifold* ) >;
	using ContactRigidEnd		= std::function< void( LiquidFunContact* ) >;
	using ContactLiquidBegin	= std::function< void( LiquidFunParticle*, LiquidFunParticleBodyContact* ) >;
	using ContactLiquidEnd		= std::function< void( LiquidFunFixture*, LiquidFunParticle*, int ) >;
	
	ContactRigidBegin		onContactRigidBegin;	//=> 剛体と剛体の接触時に呼ばれるコールバック関数
	ContactRigidPreSolve	onContactRigidPreSolve;	//=> 剛体と剛体の接触中に呼ばれるコールバック関数
	ContactRigidEnd			onContactRigidEnd;		//=> 剛体と剛体の離脱時に呼ばれるコールバック関数
	ContactLiquidBegin		onContactLiquidBegin;	//=> 剛体と液体の接触時に呼ばれるコールバック関数
	ContactLiquidEnd		onContactLiquidEnd;		//=> 剛体と液体の離脱時に呼ばれるコールバック関数
};

#endif