#ifndef _IDATA_LOAD_LISTENER_H_
#define _IDATA_LOAD_LISTENER_H_

#include "Utility/Template/SmartPtr.h"
#include <vector>

class ObjectData;

/*------------------------------------------------------------*/
//	@class		：	IDataLoadListener
//	@brief		：	データ読み込みリスナインタフェイス
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class IDataLoadListener
{
	
public:
	
	using ObjectDataContainer = std::vector< SharedPtr< ObjectData > >;
	
public:
	
	/**
	 *	@brief	デストラクタ
	 */
	virtual ~IDataLoadListener() = default;
	
	/**
	 *	@brief	データ読み込み時のコールバック関数
	 *	@param	objectDataContainer	オブジェクトデータコンテナ
	 */
	virtual void onDataLoaded( ObjectDataContainer& objectDataContainer ) = 0;
};

#endif