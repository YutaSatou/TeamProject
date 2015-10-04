#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "cocos2d.h"
#include "../Data/ObjectData.h"

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
	
private:
	
	ObjectData::Ptr	mObjectData;	//=> オブジェクトデータ
};

#endif