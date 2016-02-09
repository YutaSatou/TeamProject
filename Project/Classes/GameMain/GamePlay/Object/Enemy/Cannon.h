#ifndef _CANNON_H_
#define _CANNON_H_

#include "cocos2d.h"
#include "../../LiquidFun/LiquidFunDefine.h"
#include "../Data/ObjectDataDefine.h"

/*------------------------------------------------------------*/
//	@class		：	Cannon
//	@brief		：	大砲
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class Cannon : public cocos2d::Sprite
{
	
public:
	
	using ShootListener = std::function< void( const cocos2d::Vec2& ) >;
	
protected:
	
	/**
	 *	@brief	コンストラクタ
	 */
	Cannon();
	
	/**
	 *	@brief	デストラクタ
	 */
	~Cannon() = default;
	
	/**
	 *	@brief	初期化
	 *	@param	objectData	オブジェクトデータ
	 *	@param	nodeName	ノードに設定する名前
	 *	@param	shootPower	発射する力
	 *	@return	bool		初期化が完了したか否か
	 */
	bool init( ObjectDataPtr objectData, const std::string& nodeName, const cocos2d::Vec2& shootPower );
	
public:
	
	/**
	 *	@brief	インスタンスの生成
	 *	@param	objectData	オブジェクトデータ
	 *	@param	nodeName	ノードに設定する名前
	 *	@param	shootPower	発射する力
	 *	@return	Cannon		インスタンス
	 */
	static Cannon* create( ObjectDataPtr objectData, const std::string& nodeName, const cocos2d::Vec2& shootPower );
	
	/**
	 *	@brief	発射を観測するリスナの登録
	 *	@param	listener	リスナ
	 */
	void registerShootListener( ShootListener listener );
	
private:
	
	/**
	 *	@brief	物理構造の初期化
	 */
	void initPhysics();
	
	/**
	 *	@brief	接触コールバックの設定
	 */
	void setupContactCallback();
	
	/**
	 *	@brief	液体と接触した時に呼ばれるコールバック関数
	 *	@param	contactNode	接触したノード
	 *	@param	particle	接触したパーティクル
	 *	@param	index		接触したパーティクルのインデックス
	 */
	void onContactLiquidBegin( cocos2d::Node* contactNode, LiquidFunParticle* particle, int index );
	
	/**
	 *	@brief	アニメーションの再生
	 */
	void playAnimation();
	
private:
	
	LiquidFunBody*	mBody;			//=> ボディ
	ObjectDataPtr	mObjectData;	//=> オブジェクトデータ
	ShootListener	mShootListener;	//=> 発射を観測するリスナ
	cocos2d::Vec2	mShootPower;	//=> 発射する力
};

#endif