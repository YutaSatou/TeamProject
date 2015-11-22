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
	 *	@param	oldManifold	接触した箇所の情報
	 */
	virtual void PreSolve( LiquidFunContact* contact, const LiquidFunManifold* oldManifold ) override;
	
	/**
	 *	@brief	離脱時に呼ばれるコールバック関数
	 *	@param	contact	接触したオブジェクトの情報
	 */
	virtual void EndContact( LiquidFunContact* contact ) override;
	
public:
	
	using ContactBegin		= std::function< void( LiquidFunContact* ) >;
	using ContactPreSolve	= std::function< void( LiquidFunContact*, const LiquidFunManifold* ) >;
	using ContactEnd		= std::function< void( LiquidFunContact* ) >;
	
	ContactBegin	onContactBegin;
	ContactPreSolve	onContactPreSolve;
	ContactEnd		onContactEnd;
};

#endif