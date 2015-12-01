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
	 *	@brief	接触時に呼ばれるコールバック関数
	 *	@param	contact	接触したオブジェクトの情報
	 */
	virtual void BeginContact( LiquidFunContact* contact ) override;
	
	/**
	 *	@brief	接触中に呼ばれるコールバック関数
	 *	@param	contact		接触したオブジェクトの情報
	 *	@param	oldManifold	接触した箇所の詳細情報
	 */
	virtual void PreSolve( LiquidFunContact* contact, const LiquidFunManifold* oldManifold ) override;
	
	/**
	 *	@brief	離脱時に呼ばれるコールバック関数
	 *	@param	contact	接触したオブジェクトの情報
	 */
	virtual void EndContact( LiquidFunContact* contact ) override;
	
	/**
	 *	@brief	接触時に呼ばれるコールバック関数( パーティクル )
	 *	@param	particle	接触したパーティクル
	 *	@param	contact		接触したオブジェクトの情報
	 */
	virtual void BeginContact( LiquidFunParticle* particle, LiquidFunParticleBodyContact* contact ) override;
	
	/**
	 *	@brief	離脱時に呼ばれるコールバック関数( パーティクル )
	 *	@param	fixture		接触したフィクスチャ
	 *	@param	particle	接触したパーティクル
	 *	@param	index		パーティクルで使用するインデックス
	 */
	virtual void EndContact( LiquidFunFixture* fixture, LiquidFunParticle* particle, int index ) override;
	
public:
	
	using ContactBegin			= std::function< void( LiquidFunContact* ) >;
	using ContactPreSolve		= std::function< void( LiquidFunContact*, const LiquidFunManifold* ) >;
	using ContactEnd			= std::function< void( LiquidFunContact* ) >;
	using ContactParticleBegin	= std::function< void( LiquidFunParticle*, LiquidFunParticleBodyContact* ) >;
	using ContactParticleEnd	= std::function< void( LiquidFunFixture*, LiquidFunParticle*, int ) >;
	
	ContactBegin			onContactBegin;			//=> ユーザが接触時に呼びたい関数
	ContactPreSolve			onContactPreSolve;		//=> ユーザが接触中に呼びたい関数
	ContactEnd				onContactEnd;			//=> ユーザが離脱時に呼びたい関数
	ContactParticleBegin	onContactParticleBegin;	//=> ユーザが接触時に呼びたい関数( パーティクル )
	ContactParticleEnd		onContactParticleEnd;	//=> ユーザが離脱時に呼びたい関数( パーティクル )
};

#endif