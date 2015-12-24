#ifndef _GAME_UI_BUTTON_H_
#define _GAME_UI_BUTTON_H_

#include "cocos2d.h"
#include "ui/CocosGUI.h"

/*------------------------------------------------------------*/
//	@struct		：	GameUIButtonDesc
//	@brief		：	ボタンの設定記述子
//	@author		：	利川聖太
/*------------------------------------------------------------*/
struct GameUIButtonDesc
{
	using TouchEndedFunc = std::function< void() >;
	
	std::string		textureName;	//=> テクスチャの名前
	cocos2d::Vec2	position;		//=> ボタンの座標
	TouchEndedFunc	touchEndedFunc;	//=> ボタンを離した時に呼ばれる関数
	
	/**
	 *	@brief	コンストラクタ
	 *	@param	_textureName	テクスチャの名前
	 *	@param	_position		ボタンの座標
	 *	@param	_func			ボタンを離した時に呼ばれる関数
	 */
	GameUIButtonDesc( const std::string& _textureName, const cocos2d::Vec2& _position, TouchEndedFunc _func )
		: textureName( _textureName )
		, position( _position )
		, touchEndedFunc( _func )
	{
		
	}
};

/*------------------------------------------------------------*/
//	@class		：	GameUIButton
//	@brief		：	ゲームユーザインタフェイスに使用するボタン
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class GameUIButton : public cocos2d::ui::Button
{
	
protected:
	
	/**
	 *	@brief	コンストラクタ
	 */
	GameUIButton() = default;
	
	/**
	 *	@brief	デストラクタ
	 */
	~GameUIButton() = default;
	
	/**
	 *	@brief	初期化
	 *	@param	desc	ボタンの設定記述子
	 *	@return	bool	初期化が完了したか否か
	 */
	bool init( const GameUIButtonDesc& desc );
	
public:
	
	/**
	 *	@brief	インスタンスの生成
	 *	@param	desc			ボタンの設定記述子
	 *	@return	GameUIButton	インスタンス
	 */
	static GameUIButton* create( const GameUIButtonDesc& desc );
};

#endif