#ifndef _OBJECT_DATA_READER_H_
#define _OBJECT_DATA_READER_H_

#include "Utility/Template/SmartPtr.h"
#include <string>
#include <vector>

struct ObjectData;

/*------------------------------------------------------------*/
//	@class		：	ObjectDataReader
//	@brief		：	オブジェクトデータ読み込み
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class ObjectDataReader
{
	
public:
	
	using ObjectDataContainer = std::vector< SharedPtr< ObjectData > >;
	
public:
	
	/**
	 *	@brief	コンストラクタ
	 */
	ObjectDataReader() = default;
	
	/**
	 *	@brief	デストラクタ
	 */
	~ObjectDataReader() = default;
	
	/**
	 *	@brief	データの読み込み
	 *	@param	plistFilePath		プロパティリストファイルのパス
	 *	@return	ObjectDataContainer	読み込んだデータを格納したコンテナ
	 */
	ObjectDataContainer read( const std::string& plistFilePath );
};

#endif