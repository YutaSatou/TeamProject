#ifndef _SLIME_H_
#define _SLIME_H_

#include "cocos2d.h"
#include "../../LiquidFun/LiquidFunDefine.h"
#include "Utility/Template/SmartPtr.h"

struct ObjectData;

/*------------------------------------------------------------*/
//	@class		：	Slime
//	@brief		：	スライム
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class Slime : public cocos2d::Sprite
{
	
protected:
	
	/**
	 *	@brief	コンストラクタ
	 */
	Slime();
	
	/**
	 *	@brief	デストラクタ
	 */
	~Slime() = default;
	
	/**
	 *	@brief	初期化
	 *	@param	objectData	オブジェクトデータ
	 *	@param	nodeName	ノードに設定する名前
	 *	@return	bool		初期化が完了したか否か
	 */
	bool init( SharedPtr< ObjectData > objectData, const std::string& nodeName );
	
public:
	
	/**
	 *	@brief	インスタンスの生成
	 *	@param	objectData	オブジェクトデータ
	 *	@param	nodeName	ノードに設定する名前
	 *	@return	Slime		インスタンス
	 */
	static Slime* create( SharedPtr< ObjectData > objectData, const std::string& nodeName );
	
	/**
	 *	@brief	接触時に呼ばれるコールバック関数
	 *	@param	contactNode	接触したノード
	 *	@param	contactBody	接触したボディ
	 */
	void onContactBegin( cocos2d::Node* contactNode, LiquidFunBody* contactBody );
	
private:
	
	/**
	 *	@brief	物理構造の初期化
	 */
	void initPhysics();
	
private:
	
	LiquidFunBody*			mBody;			//=> ボディ
	SharedPtr< ObjectData >	mObjectData;	//=> オブジェクトデータ
};

#endif