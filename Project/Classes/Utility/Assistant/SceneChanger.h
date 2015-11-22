#ifndef _SCENE_CHANGER_H_
#define _SCENE_CHANGER_H_

namespace cocos2d
{
	class Layer;
	class Scene;
}

/*------------------------------------------------------------*/
//	@class		：	SceneChanger
//	@brief		：	シーン変更者
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class SceneChanger
{
	
public:
	
	/**
	 *	@brief	シーンの変更
	 *	@param	nextLayer	遷移するシーンで使用するレイヤ
	 */
	static void switchScene( cocos2d::Layer* nextLayer );
	
	/**
	 *	@brief	シーンの変更
	 *	@param	nextScene	遷移するシーン
	 */
	static void switchScene( cocos2d::Scene* nextScene );
};

#endif