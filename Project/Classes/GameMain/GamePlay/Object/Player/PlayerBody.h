#ifndef _PLAYER_BODY_H_
#define _PLAYER_BODY_H_

#include "../../LiquidFun/LiquidFunDefine.h"
#include "cocos2d.h"

/*------------------------------------------------------------*/
//	@class		：	PlayerBody
//	@brief		：	プレイヤのボディ
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class PlayerBody
{
	
private:
	
	using UserDataPointer	= void*;
	using EachBufferFunc	= std::function< void( UserDataPointer*, LiquidFunParticleColor*, LiquidFunVec2* ) >;
	
public:
	
	/**
	 *	@brief	コンストラクタ
	 */
	PlayerBody();
	
	/**
	 *	@brief	デストラクタ
	 */
	~PlayerBody();
	
	/**
	 *	@brief	初期化
	 *	@param	parentNode	親ノード
	 *	@param	textureName	テクスチャの名前
	 *	@param	position	ボディの座標
	 */
	void init( cocos2d::Node* parentNode, const std::string& textureName, const cocos2d::Vec2& position );
	
	/**
	 *	@brief	更新
	 */
	void update();
	
	/**
	 *	@brief	重力の有効化
	 */
	void enableGravity();
	
private:
	
	/**
	 *	@brief	ボディの初期化
	 *	@param	position	ボディの座標
	 */
	void initBody( const cocos2d::Vec2& position );
	
	/**
	 *	@brief	テクスチャの初期化
	 *	@param	textureName	テクスチャの名前
	 */
	void initTexture( const std::string& textureName );
	
	/**
	 *	@brief	バッファの巡回
	 *	@param	func	実行する関数
	 */
	void eachBuffer( const EachBufferFunc& func );
	
private:
	
	cocos2d::Node*			mParentNode;			//=> 親ノード
	LiquidFunParticle*		mParticle;				//=> パーティクル
	LiquidFunParticleGroup*	mParticleGroup;			//=> パーティクルグループ
	cocos2d::Size			mParticleGroupSize;		//=> パーティクルグループの大きさ
};

#endif