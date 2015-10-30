#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "cocos2d.h"
#include "Utility/Template/SmartPtr.h"

class ObjectData;
class ColorCMY;
class ColorMixer;

/*------------------------------------------------------------*/
//	@class		：	Player
//	@brief		：	プレイヤ
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class Player : public cocos2d::Sprite
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
	
public:
	
	/**
	 *	@brief	インスタンスの生成
	 *	@param	objectData	オブジェクトデータ
	 *	@return	Player		インスタンス
	 */
	static Player* create( SharedPtr< ObjectData > objectData );
	
	/**
	 *	@brief	接触時に呼ばれるコールバック関数
	 *	@param	contactNode	接触したノード
	 */
	void onContactBegin( cocos2d::Node* contactNode );
	
	/**
	 *	@brief	重力の有効化
	 */
	void enableGravity();
	
private:
	
	/**
	 *	@brief	物理構造の初期化
	 */
	void initPhysics();
	
	/**
	 *	@brief	色の更新
	 *	@param	blendColor	合成色
	 */
	void updateColor( const ColorCMY& blendColor );
	
private:
	
	SharedPtr< ObjectData >	mObjectData;	//=> オブジェクトデータ
	SharedPtr< ColorMixer >	mColorMixer;	//=> 色合成者
};

#endif