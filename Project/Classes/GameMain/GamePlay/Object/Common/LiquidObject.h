#ifndef _LIQUID_OBJECT_H_
#define _LIQUID_OBJECT_H_

#include "cocos2d.h"
#include "../../LiquidFun/LiquidFunUserAPI.h"

/*------------------------------------------------------------*/
//	@class		：	LiquidObject
//	@brief		：	液体オブジェクトの基底
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class LiquidObject : public cocos2d::Node
{
	
protected:
	
	using UserDataPointer	= void*;
	using EachBufferFunc	= std::function< void( UserDataPointer*, LiquidFunParticleColor*, LiquidFunVec2* ) >;
	
protected:
	
	/**
	 *	@brief	コンストラクタ
	 */
	LiquidObject();
	
	/**
	 *	@brief	デストラクタ
	 */
	virtual ~LiquidObject();
	
public:
	
	/**
	 *	@brief	パーティクルの初期化
	 */
	virtual void initParticle() = 0;
	
	/**
	 *	@brief	パーティクルの更新
	 */
	virtual void updateParticle();
	
protected:
	
	/**
	 *	@brief	剛体と液体の接触時に呼ばれるコールバック関数
	 *	@param	contactNode	接触したノード
	 *	@param	body		接触したボディ
	 *	@param	particle	接触したパーティクル
	 *	@param	index		接触したパーティクルのインデックス
	 */
	virtual void onContactLiquidBegin( cocos2d::Node* contactNode, LiquidFunBody* body, LiquidFunParticle* particle, int index );
	
	/**
	 *	@brief	剛体と液体の離脱時に呼ばれるコールバック関数
	 *	@param	contactNode	接触したノード
	 *	@param	body		接触したボディ
	 *	@param	particle	接触したパーティクル
	 *	@param	index		接触したパーティクルのインデックス
	 */
	virtual void onContactLiquidEnd( cocos2d::Node* contactNode, LiquidFunBody* body, LiquidFunParticle* particle, int index );
	
	/**
	 *	@brief	テクスチャの登録
	 *	@param	textureName	テクスチャの名前
	 */
	void registerTexture( const std::string& textureName );
	
	/**
	 *	@brief	接触コールバックの設定
	 */
	void setupContactCallback();
	
	/**
	 *	@brief	バッファの巡回
	 *	@param	func	実行する関数
	 */
	void eachBuffer( const EachBufferFunc& func );
	
protected:
	
	LiquidFunParticle*		mParticle;				//=> パーティクル
	LiquidFunParticleGroup*	mParticleGroup;			//=> パーティクルグループ
};

#endif