#ifndef _OBJECT_FACTORY_H_
#define _OBJECT_FACTORY_H_

#include <string>
#include <functional>
#include <unordered_map>

/*------------------------------------------------------------*/
//	@class		：	ObjectFactory
//	@brief		：	オブジェクト生成工場
//	@typename	：	InstanceType	： 生成するインスタンス( ポインタ )
//	@typename	：	Param			： インスタンスに渡す引数
//	@author		：	利川聖太
/*------------------------------------------------------------*/
template< typename InstanceType, typename ...Param >
class ObjectFactory
{
	
protected:
	
	using CreateFunction			= std::function< InstanceType*( Param... ) >;
	using CreateFunctionContainer	= std::unordered_map< std::string, CreateFunction >;
	
public:
	
	/**
	 *	@brief	コンストラクタ
	 */
	ObjectFactory() = default;
	
	/**
	 *	@brief	デストラクタ
	 */
	virtual ~ObjectFactory();
	
	/**
	 *	@brief	オブジェクト生成関数の追加
	 *	@param	key		要素に紐付けるキー
	 *	@param	func	オブジェクト生成関数
	 */
	void addCreateFunction( const std::string& key, CreateFunction func );
	
	/**
	 *	@brief	オブジェクトの生成
	 *	@param	key				要素を引き出すキー
	 *	@param	param...		インスタンスに渡す引数
	 *	@return	InstanceType	オブジェクトのインスタンス
	 */
	InstanceType* createObject( const std::string& key, Param... param );
	
	/**
	 *	@brief	要素が登録済みか否か
	 *	@param	key		要素を引き出すキー
	 *	@return	bool	要素が登録済みか否か
	 */
	bool isRegisterElement( const std::string& key ) const;
	
	/**
	 *	@brief	文字列にキーが含まれているか否か
	 *	@param	key		検索するキー
	 *	@param	str		確認する文字列
	 *	@return	bool	文字列にキーが含まれているか否か
	 */
	bool containsKeyToStr( const std::string& key, const std::string& str ) const;
	
	/**
	 *	@brief	ファイルパスからファイルネームの抽出
	 *	@param	filePath	ファイルのパス
	 *	@return	std::string	ファイルネーム
	 */
	std::string extractFileName( const std::string& filePath ) const;
	
private:
	
	CreateFunctionContainer mCreateFunctionContainer;	//=> 生成関数のコンテナ
};

// 実装ヘッダ
#include "ObjectFactoryImpl.h"

#endif