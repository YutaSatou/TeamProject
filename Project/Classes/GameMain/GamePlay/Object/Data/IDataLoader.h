#ifndef _IDATA_LOADER_H_
#define _IDATA_LOADER_H_

#include "Utility/Template/SmartPtr.h"
#include <vector>

class ObjectData;

/*------------------------------------------------------------*/
//	@class		：	IDataLoader
//	@brief		：	データ読み込みインタフェイス
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class IDataLoader
{
	
public:
	
	using ObjectDataContainer = std::vector< SharedPtr< ObjectData > >;
	
public:
	
	/**
	 *	@brief	デストラクタ
	 */
	virtual ~IDataLoader() = default;
	
	/**
	 *	@brief	データ読み込み時のコールバック関数
	 *	@param	objectDataContainer	オブジェクトデータコンテナ
	 */
	virtual void onDataLoaded( ObjectDataContainer& objectDataContainer ) = 0;
};

#endif