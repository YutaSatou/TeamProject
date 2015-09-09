#ifndef _SCENE_SWITCHER_H_
#define _SCENE_SWITCHER_H_

/**
 *	@brief	シーンの種類
 */
enum SceneType : int
{
	TITLE			= 0,
	STAGE_SELECT	= 1,
	PLAY			= 2,
	RESULT			= 3,
	LENGTH			= 4,
};

/*------------------------------------------------------------*/
//	@class		：	SceneSwitcher
//	@brief		：	シーン変更者
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class SceneSwitcher
{
	
public:
	
	/**
	 *	@brief	通常のシーン変更
	 *	@param	type	変更するシーン
	 */
	static void change( SceneType type );
};

#endif