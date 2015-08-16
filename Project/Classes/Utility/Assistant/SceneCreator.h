#ifndef _SCENE_CREATOR_H_
#define _SCENE_CREATOR_H_

#include "cocos2d.h"

/*------------------------------------------------------------*/
//	@class		：	SceneCreator
//	@brief		：	シーン生成補助
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class SceneCreator
{
	
public:
	
	/**
	 *	@brief	シーンの生成
	 *	@param	childLayer	子ノードにするレイヤ
	 *	@return	Scene		シーンのインスタンス
	 */
	static cocos2d::Scene* createScene( cocos2d::Layer* childLayer );
	
	/**
	 *	@brief	物理空間を含めたシーンの生成
	 *	@param	childLayer	子ノードにするレイヤ
	 *	@param	gravity		物理空間に与える重力
	 *	@param	isDebug		デバッグ描画を行うか否か
	 *	@param	speed		物理演算が計算される速度
	 *						増加させると高速に動作するオブジェクトのコリジョン抜けを防ぐことができる。
	 *	@return	Scene		シーンのインスタンス
	 */
	static cocos2d::Scene* createPhysicsScene( cocos2d::Layer* childLayer, const cocos2d::Vect& gravity, bool isDebug, float speed = 1.0f );
};

#endif