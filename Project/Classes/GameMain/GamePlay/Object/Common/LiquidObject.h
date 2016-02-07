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
	
private:
	
	using ParticleSpriteContainer = std::vector< cocos2d::Sprite* >;
	
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
	
	/**
	 *	@brief	液体挙動の有効化
	 */
	void enableLiquidBehavior();
	
	/**
	 *	@brief	液体挙動の無効化
	 */
	void disableLiquidBehavior();
	
	/**
	 *	@brief	継続的な力の加算
	 *	@param	force	液体に加える力
	 */
	void applyForce( const cocos2d::Vec2& force );
	
	/**
	 *	@brief	瞬間的な力の加算
	 *	@param	impulse	液体に加える力
	 */
	void applyLinearImpulse( const cocos2d::Vec2& impulse );
	
	/**
	 *	@brief	移動量の取得
	 *	@return	Vec2	移動量( 質量計算済 )
	 */
	cocos2d::Vec2 getLinearVelocity() const;
	
protected:
	
	/**
	 *	@brief	剛体と接触した時に呼ばれるコールバック関数
	 *	@param	contactNode	接触したノード
	 *	@param	fixture		接触したフィクスチャ
	 */
	virtual void onContactRigidBegin( cocos2d::Node* contactNode, LiquidFunFixture* fixture );
	
	/**
	 *	@brief	剛体と接触し終わった時に呼ばれるコールバック関数
	 *	@param	contactNode	接触したノード
	 *	@param	fixture		接触したフィクスチャ
	 */
	virtual void onContactRigidEnd( cocos2d::Node* contactNode, LiquidFunFixture* fixture );
	
	/**
	 *	@brief	テクスチャの登録
	 *	@param	textureName	テクスチャの名前
	 */
	void registerTexture( const std::string& textureName );
	
	/**
	 *	@brief	テクスチャの登録解除
	 */
	void unregisterTexture();
	
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
	
	LiquidFunParticle*		mParticle;		//=> パーティクル
	LiquidFunParticleGroup*	mParticleGroup;	//=> パーティクルグループ
	
private:
	
	ParticleSpriteContainer mParticleSpriteContainer;	//=> パーティクルスプライトコンテナ
};

#endif