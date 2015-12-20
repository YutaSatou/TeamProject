#ifndef _BRIDGE_SCENE_H_
#define _BRIDGE_SCENE_H_

#include "cocos2d.h"

/*------------------------------------------------------------*/
//	@class		：	BridgeScene
//	@brief		：	ブリッジシーン
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class BridgeScene : public cocos2d::Layer
{
	
public:
	
	using NextSceneCreateFunc = std::function< cocos2d::Scene*() >;
	
protected:
	
	/**
	 *	@brief	コンストラクタ
	 */
	BridgeScene();
	
	/**
	 *	@brief	デストラクタ
	 */
	~BridgeScene() = default;
	
	/**
	 *	@brief	初期化
	 *	@param	func	次のシーンを生成する関数
	 *	@return	bool	初期化が完了したか否か
	 */
	bool init( NextSceneCreateFunc func );
	
	/**
	 *	@brief	次のシーンへの遷移
	 *	@param	deltaTime	デルタ時間
	 */
	void next( float deltaTime );
	
public:
	
	/**
	 *	@brief	インスタンスの生成
	 *	@param	func		次のシーンを生成する関数
	 *	@return	BridgeScene	インスタンス
	 */
	static BridgeScene* create( NextSceneCreateFunc func );
	
private:
	
	NextSceneCreateFunc mNextSceneCreateFunc;	//=> 次のシーンを生成する関数
};

#endif