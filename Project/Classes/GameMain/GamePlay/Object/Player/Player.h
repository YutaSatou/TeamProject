#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "../Common/LiquidObject.h"
#include "Utility/Template/SmartPtr.h"

struct ObjectData;

/*------------------------------------------------------------*/
//	@class		：	Player
//	@brief		：	プレイヤ
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class Player : public LiquidObject
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
	 *	@brief	液体挙動の有効化
	 */
	void enableLiquidBehavior();
	
private:
	
	/**
	 *	@brief	パーティクルの初期化
	 */
	virtual void initParticle() override;
	
private:
	
	SharedPtr< ObjectData > mObjectData;	//=> オブジェクトデータ
};

#endif