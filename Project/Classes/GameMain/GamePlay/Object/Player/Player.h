#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "../Common/LiquidObject.h"
#include "Utility/Template/SmartPtr.h"

struct	ObjectData;
class	ColorMixer;

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
	
	/**
	 *	@brief	剛体と接触した時に呼ばれるコールバック関数
	 *	@param	contactNode	接触したノード
	 *	@param	body		接触したボディ
	 */
	virtual void onContactRigidBegin( cocos2d::Node* contactNode, LiquidFunBody* body ) override;
	
private:
	
	SharedPtr< ObjectData >	mObjectData;	//=> オブジェクトデータ
	SharedPtr< ColorMixer >	mColorMixer;	//=> 色合成者
};

#endif