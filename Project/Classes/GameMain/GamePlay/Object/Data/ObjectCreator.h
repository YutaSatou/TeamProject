#ifndef _OBJECT_CREATOR_H_
#define _OBJECT_CREATOR_H_

#include "IDataLoader.h"
#include <string>
#include <functional>
#include <unordered_map>

namespace cocos2d
{
	class Node;
}

class ObjectData;

/*------------------------------------------------------------*/
//	@class		：	ObjectCreator
//	@brief		：	オブジェクト生成者
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class ObjectCreator
{
	
protected:
	
	using ObjectName				= std::string;
	using CreateFunction			= std::function< cocos2d::Node*( SharedPtr< ObjectData >, const ObjectName& ) >;
	using CreateFunctionContainer	= std::unordered_map< ObjectName, CreateFunction >;
	
protected:
	
	/**
	 *	@brief	コンストラクタ
	 *	@param	parentNode	生成したオブジェクトを追加する親ノード
	 */
	ObjectCreator( cocos2d::Node* parentNode );
	
	/**
	 *	@brief	デストラクタ
	 */
	virtual ~ObjectCreator();
	
public:
	
	/**
	 *	@brief	オブジェクト生成関数の追加
	 *	@param	name	オブジェクトの名前
	 *	@param	func	オブジェクト生成関数
	 */
	void addCreateFunction( const ObjectName& name, CreateFunction func );
	
	/**
	 *	@brief	オブジェクトの生成
	 *	@param	objectDataContainer	オブジェクトデータコンテナ
	 */
	virtual void createObject( IDataLoader::ObjectDataContainer& objectDataContainer );
	
private:
	
	CreateFunctionContainer	mCreateFunctionContainer;	//=> 生成関数のコンテナ
	cocos2d::Node*			mParentNode;				//=> 生成したオブジェクトを追加する親ノード
};

#endif