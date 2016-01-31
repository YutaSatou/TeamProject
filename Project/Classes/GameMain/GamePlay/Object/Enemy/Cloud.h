#ifndef _CLOUD_H_
#define _CLOUD_H_

#include "cocos2d.h"
#include "../../LiquidFun/LiquidFunDefine.h"
#include "../Data/ObjectDataDefine.h"

/*------------------------------------------------------------*/
//	@class		：	クラウド
//	@brief		：	雲
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class Cloud : public cocos2d::Sprite
{
	
protected:
	
	/**
	 *	@brief	コンストラクタ
	 */
	Cloud();
	
	/**
	 *	@brief	デストラクタ
	 */
	~Cloud() = default;
	
	/**
	 *	@brief	初期化
	 *	@param	objectData	オブジェクトデータ
	 *	@param	nodeName	ノードに設定する名前
	 *	@return	bool		初期化が完了したか否か
	 */
	bool init( ObjectDataPtr objectData, const std::string& nodeName );
	
public:
	
	/**
	 *	@brief	インスタンスの生成
	 *	@param	objectData	オブジェクトデータ
	 *	@param	nodeName	ノードに設定する名前
	 *	@return	Cloud		インスタンス
	 */
	static Cloud* create( ObjectDataPtr objectData, const std::string& nodeName );
	
private:
	
	/**
	 *	@brief	アニメーションの初期化
	 */
	void initAnimation();
	
	/**
	 *	@brief	物理構造の初期化
	 */
	void initPhysics();
	
	/**
	 *	@brief	液体と接触した時に呼ばれるコールバック関数
	 *	@param	contactNode	接触したノード
	 *	@param	particle	接触したパーティクル
	 *	@param	index		接触したパーティクルのインデックス
	 */
	void onContactLiquidBegin( cocos2d::Node* contactNode, LiquidFunParticle* particle, int index );
	
private:
	
	LiquidFunBody*	mBody;			//=> ボディ
	ObjectDataPtr	mObjectData;	//=> オブジェクトデータ
};

#endif