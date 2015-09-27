#ifndef _SLIME_H_
#define _SLIME_H_

#include "cocos2d.h"
#include "../Data/ObjectData.h"

/*------------------------------------------------------------*/
//	@struct		：	Slime
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
	bool init( ObjectData::Ptr objectData, const std::string& nodeName );
	
public:
	
	/**
	 *	@brief	インスタンスの生成
	 *	@param	objectData	オブジェクトデータ
	 *	@param	nodeName	ノードに設定する名前
	 *	@return	Slime		インスタンス
	 */
	static Slime* create( ObjectData::Ptr objectData, const std::string& nodeName );
	
	/**
	 *	@brief	接触時に呼ばれるコールバック関数
	 *	@param	contactNode	接触したノード
	 */
	void onContactBegin( const cocos2d::Node* contactNode );
	
private:
	
	/**
	 *	@brief	物理構造の初期化
	 */
	void initPhysics();
	
private:
	
	ObjectData::Ptr	mObjectData;	//=> オブジェクトデータ
};

#endif