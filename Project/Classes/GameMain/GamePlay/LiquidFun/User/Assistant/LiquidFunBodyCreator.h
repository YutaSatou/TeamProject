#ifndef _LIQUID_FUN_BODY_CREATOR_H_
#define _LIQUID_FUN_BODY_CREATOR_H_

#include "LiquidFunBox2D.h"

namespace cocos2d
{
	class Node;
}

struct LiquidFunMaterial;

/*------------------------------------------------------------*/
//	@class		：	LiquidFunBodyCreator
//	@brief		：	LiquidFunのボディ生成者
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class LiquidFunBodyCreator
{
	
public:
	
	/**
	 *	@brief	コンストラクタ
	 */
	LiquidFunBodyCreator() = default;
	
	/**
	 *	@brief	デストラクタ
	 */
	~LiquidFunBodyCreator() = default;
	
	/**
	 *	@brief	ボディの生成
	 *	@param	bodyDef			ボディの情報
	 *	@param	fixtureDef		フィクスチャの情報
	 *	@return	LiquidFunBody	ボディのインスタンス
	 */
	LiquidFunBody* createBody( const LiquidFunBodyDef& bodyDef, const LiquidFunFixtureDef& fixtureDef );
	
	/**
	 *	@brief	ボディの生成
	 *	@param	registerNode	ボディに登録するノード
	 *	@param	bodyType		ボディの種類
	 *	@param	shape			フィクスチャに登録するシェイプ
	 *	@param	material		フィクスチャに登録するマテリアル
	 *	@return	LiquidFunBody	ボディのインスタンス
	 */
	LiquidFunBody* createBody( cocos2d::Node* registerNode, const LiquidFunBodyType& bodyType, const LiquidFunShape& shape, const LiquidFunMaterial& material );
	
private:
	
	/**
	 *	@brief	ボディの情報の生成
	 *	@param	registerNode		ボディに登録するノード
	 *	@param	bodyType			ボディの種類
	 *	@return	LiquidFunBodyDef	ボディの情報
	 */
	LiquidFunBodyDef createBodyDef( cocos2d::Node* registerNode, const LiquidFunBodyType& bodyType );
	
	/**
	 *	@brief	フィクスチャの情報の生成
	 *	@param	shape				フィクスチャに登録するシェイプ
	 *	@param	material			フィクスチャに登録するマテリアル
	 *	@return	LiquidFunFixtureDef	フィクスチャの情報
	 */
	LiquidFunFixtureDef createFixtureDef( const LiquidFunShape& shape, const LiquidFunMaterial& material );
};

#endif