#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "cocos2d.h"
#include "../Data/ObjectData.h"

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
	bool init( ObjectData::Ptr objectData );
	
public:
	
	/**
	 *	@brief	インスタンスの生成
	 *	@param	objectData	オブジェクトデータ
	 *	@return	Player		インスタンス
	 */
	static Player* create( ObjectData::Ptr objectData );
	
	/**
	 *	@brief	接触時に呼ばれるコールバック関数
	 *	@param	contactNode	接触したノード
	 */
	void onContactBegin( cocos2d::Node* contactNode );
	
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
	
	using ColorMixerPtr = std::shared_ptr< ColorMixer >;
	
	ObjectData::Ptr	mObjectData;	//=> オブジェクトデータ
	ColorMixerPtr	mColorMixer;	//=> 色合成者
};

#endif