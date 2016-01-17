#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "../Common/LiquidObject.h"
#include "../Data/ObjectDataPtr.h"

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
	bool init( ObjectDataPtr objectData );
	
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
	static Player* create( ObjectDataPtr objectData );
	
private:
	
	/**
	 *	@brief	パーティクルの初期化
	 */
	virtual void initParticle() override;
	
	/**
	 *	@brief	剛体と接触した時に呼ばれるコールバック関数
	 *	@param	contactNode	接触したノード
	 *	@param	fixture		接触したフィクスチャ
	 */
	virtual void onContactRigidBegin( cocos2d::Node* contactNode, LiquidFunFixture* fixture ) override;
	
private:
	
	ObjectDataPtr mObjectData;	//=> オブジェクトデータ
};

#endif