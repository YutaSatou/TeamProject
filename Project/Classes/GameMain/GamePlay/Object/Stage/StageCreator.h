#ifndef _STAGE_CREATOR_H_
#define _STAGE_CREATOR_H_

#include "../Data/ObjectDataDefine.h"
#include <string>
#include <functional>

/*------------------------------------------------------------*/
//	@class		：	StageCreator
//	@brief		：	ステージ生成者
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class StageCreator
{
	
public:
	
	using DataLoadListener = std::function< void( ObjectDataPtr ) >;
	
public:
	
	/**
	 *	@brief	コンストラクタ
	 */
	StageCreator();
	
	/**
	 *	@brief	デストラクタ
	 */
	~StageCreator() = default;
	
	/**
	 *	@brief	リスナの追加
	 *	@param	listener	リスナ
	 */
	void addListener( DataLoadListener listener );
	
	/**
	 *	@brief	ステージの生成
	 *	@param	plistFilePath	プロパティリストファイルのパス
	 */
	void createStage( const std::string& plistFilePath );
	
private:
	
	DataLoadListener mListener;	//=> データ読み込みリスナ
};

#endif