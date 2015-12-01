#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "cocos2d.h"
#include "Utility/Template/SmartPtr.h"

struct	ObjectData;
class	PlayerBody;
class	ColorCMY;
class	ColorMixer;

/*------------------------------------------------------------*/
//	@class		：	Player
//	@brief		：	プレイヤ
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class Player : public cocos2d::Node
{
	
protected:
	
	/**
	 *	@brief	コンストラクタ
	 */
	Player();
	
	/**
	 *	@brief	デストラクタ
	 */
	~Player() = default;
	
	/**
	 *	@brief	初期化
	 *	@param	objectData	オブジェクトデータ
	 *	@return	bool		初期化が完了したか否か
	 */
	bool init( SharedPtr< ObjectData > objectData );
	
	/**
	 *	@brief	更新
	 *	@param	deltaTime	デルタ時間
	 */
	virtual void update( float deltaTime ) override;
	
public:
	
	/**
	 *	@brief	インスタンスの生成
	 *	@param	objectData	オブジェクトデータ
	 *	@return	Player		インスタンス
	 */
	static Player* create( SharedPtr< ObjectData > objectData );
	
	/**
	 *	@brief	重力の有効化
	 */
	void enableGravity();
	
	/**
	 *	@brief	色の更新
	 *	@param	blendColor	合成色
	 */
	void updateColor( const ColorCMY& blendColor );
	
private:
	
	SharedPtr< ObjectData >	mObjectData;	//=> オブジェクトデータ
	SharedPtr< PlayerBody >	mPlayerBody;	//=> プレイヤのボディ
	SharedPtr< ColorMixer >	mColorMixer;	//=> 色合成者
};

#endif